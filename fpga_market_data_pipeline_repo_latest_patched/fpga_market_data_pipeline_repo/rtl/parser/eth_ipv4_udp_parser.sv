// -----------------------------------------------------------------------------
// eth_ipv4_udp_parser.sv
//
// Parses a single Ethernet II / IPv4 / UDP frame and emits the UDP payload as
// a framed ITCH message stream. v1 is intentionally strict and small-scope:
//   - Ethernet II only (no VLAN tags)
//   - IPv4 only (no IP options)
//   - UDP only
//   - One UDP datagram carries one ITCH message frame
// -----------------------------------------------------------------------------

module eth_ipv4_udp_parser #(
    parameter int MAX_FRAME_BYTES = 2048,
    parameter int MSG_BYTES       = 64,
    parameter int MSG_W           = MSG_BYTES * 8
)(
    input  logic                  clk,
    input  logic                  rst_n,
    input  logic [7:0]            s_rx_byte,
    input  logic                  s_rx_valid,
    input  logic                  s_rx_sof,
    input  logic                  s_rx_eof,
    output logic                  s_rx_ready,
    output logic [MSG_W-1:0]      m_msg_data,
    output logic [15:0]           m_msg_len,
    output logic                  m_msg_valid,
    input  logic                  m_msg_ready,
    output logic                  err_invalid_eth,
    output logic                  err_invalid_ip,
    output logic                  err_invalid_udp,
    output logic                  err_oversize
);
  typedef enum logic [2:0] {IDLE, ETH, IP, UDP, PAYLOAD, EMIT, DROP} state_t;
  state_t state;
  logic [15:0] byte_cnt, payload_idx;
  logic [7:0]  frame [MAX_FRAME_BYTES-1:0];
  logic [MSG_W-1:0] msg_buf;
  logic [15:0] msg_len_reg;
  logic [15:0] ip_total_len, udp_len;
  logic [7:0]  ip_proto;
  logic [15:0] ipv4_hdr_sum;

  assign s_rx_ready = 1'b1;

  function automatic logic [15:0] ipv4_checksum20(input logic [7:0] hdr[20]);
    logic [19:0] sum;
    int i;
    begin
      sum = 0;
      for (i = 0; i < 20; i += 2) begin
        sum += {hdr[i], hdr[i+1]};
      end
      // Fold 20-bit sum to 16-bit
      sum = sum[15:0] + sum[19:16];
      sum = sum[15:0] + sum[19:16];
      return ~sum[15:0];
    end
  endfunction

  always_ff @(posedge clk or negedge rst_n) begin
    if (!rst_n) begin
      state <= IDLE; byte_cnt <= '0; payload_idx <= '0; msg_buf <= '0; msg_len_reg <= '0;
      m_msg_valid <= 1'b0; m_msg_data <= '0; m_msg_len <= '0;
      err_invalid_eth <= 1'b0; err_invalid_ip <= 1'b0; err_invalid_udp <= 1'b0; err_oversize <= 1'b0;
      ip_total_len <= '0; udp_len <= '0; ip_proto <= '0; ipv4_hdr_sum <= '0;
    end else begin
      if (m_msg_valid && m_msg_ready) m_msg_valid <= 1'b0;

      // EMIT fires one clock after EOF (s_rx_valid may already be 0)
      if (state == EMIT) begin
        if (!err_invalid_eth && !err_invalid_ip && !err_invalid_udp && !err_oversize) begin
          m_msg_data  <= msg_buf;
          m_msg_len   <= msg_len_reg;
          m_msg_valid <= 1'b1;
        end
        state <= IDLE;
      end

      if (s_rx_valid) begin
        if (s_rx_sof) begin
          // SOF: store byte[0] explicitly and reset counter to 1
          // (byte[0] is processed now; next byte[1] will see byte_cnt=1)
          frame[0]  <= s_rx_byte;
          byte_cnt  <= 1;
          payload_idx <= 0; msg_buf <= '0; msg_len_reg <= '0;
          state     <= ETH;
          err_invalid_eth <= 1'b0; err_invalid_ip <= 1'b0;
          err_invalid_udp <= 1'b0; err_oversize    <= 1'b0;
        end else begin
          if (byte_cnt < MAX_FRAME_BYTES) frame[byte_cnt] <= s_rx_byte;
          byte_cnt <= byte_cnt + 1'b1;
        end

        case (state)
          ETH: begin
            if (byte_cnt == 13) begin
              if ({frame[12], s_rx_byte} != 16'h0800) err_invalid_eth <= 1'b1;
              state <= IP;
            end
          end
          IP: begin
            if (byte_cnt == 14) begin
              if (s_rx_byte[7:4] != 4'h4) err_invalid_ip <= 1'b1;
            end
            if (byte_cnt == 15) begin
              // IHL field is frame[14][3:0]; must be 5 (= 20 bytes, no IP options)
              if (frame[14][3:0] != 4'd5) err_invalid_ip <= 1'b1;
            end
            if (byte_cnt == 16) ip_total_len[15:8] <= s_rx_byte;
            if (byte_cnt == 17) ip_total_len[7:0]  <= s_rx_byte;
            if (byte_cnt == 23) begin
              ip_proto <= s_rx_byte;
            end
            if (byte_cnt == 24) begin
              ipv4_hdr_sum[15:8] <= s_rx_byte;
            end
            if (byte_cnt == 25) begin
              ipv4_hdr_sum[7:0] <= s_rx_byte;
            end
            if (byte_cnt == 33) begin
              if (ip_proto != 8'd17) err_invalid_ip <= 1'b1;
              if (ip_total_len < 28)  err_invalid_ip <= 1'b1;
              
              // Validate IPv4 Checksum
              begin
                logic [7:0] ip_hdr [20];
                for (int j = 0; j < 20; j++) begin
                  if (j == 19) ip_hdr[19] = s_rx_byte;
                  else         ip_hdr[j] = frame[14 + j];
                end
                if (ipv4_checksum20(ip_hdr) != 16'h0000) begin
                  err_invalid_ip <= 1'b1;
                end
              end

              state <= UDP;
            end
          end
          UDP: begin
            if (byte_cnt == 38) udp_len[15:8] <= s_rx_byte;
            if (byte_cnt == 39) begin
              udp_len[7:0] <= s_rx_byte;
              if ({frame[38], s_rx_byte} < 16'd8) err_invalid_udp <= 1'b1;
            end
            if (byte_cnt == 41) begin
              payload_idx <= 0;
              state <= PAYLOAD;
            end
          end
          PAYLOAD: begin
            if (payload_idx < MSG_BYTES) begin
              msg_buf[(MSG_BYTES - 1 - payload_idx) * 8 +: 8] <= s_rx_byte;
              payload_idx <= payload_idx + 1'b1;
              msg_len_reg <= payload_idx + 1'b1;
            end else begin
              err_oversize <= 1'b1;
              state <= DROP;
            end
            if (s_rx_eof) begin
              state <= EMIT;
            end
          end
          default: ;
        endcase
      end
    end
  end
endmodule : eth_ipv4_udp_parser
