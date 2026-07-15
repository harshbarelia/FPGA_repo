// -----------------------------------------------------------------------------
// udp_payload_framer.sv
//
// Converts a single UDP payload byte stream into framed ITCH message words.
// In v1 the parser already supplies whole messages, so this module is a thin
// adapter that buffers one message and re-emits it as a framed transfer.
// -----------------------------------------------------------------------------

module udp_payload_framer #(
    parameter int MSG_BYTES = 64,
    parameter int MSG_W     = MSG_BYTES * 8
)(
    input  logic                  clk,
    input  logic                  rst_n,
    input  logic [MSG_W-1:0]      s_msg_data,
    input  logic [15:0]           s_msg_len,
    input  logic                  s_msg_valid,
    output logic                  s_msg_ready,
    output logic [MSG_W-1:0]      m_msg_data,
    output logic [15:0]           m_msg_len,
    output logic                  m_msg_valid,
    input  logic                  m_msg_ready
);
  logic held_valid;
  logic [MSG_W-1:0] held_data;
  logic [15:0] held_len;
  assign s_msg_ready = !held_valid || (m_msg_valid && m_msg_ready);

  logic accept, drain;
  assign accept = s_msg_valid && s_msg_ready;
  assign drain  = held_valid && (!m_msg_valid || m_msg_ready);

  always_ff @(posedge clk or negedge rst_n) begin
    if (!rst_n) begin
      held_valid  <= 1'b0;
      held_data   <= '0;
      held_len    <= '0;
      m_msg_valid <= 1'b0;
      m_msg_data  <= '0;
      m_msg_len   <= '0;
    end else begin
      case ({accept, drain})
        2'b10: begin
          held_valid <= 1'b1;
          held_data  <= s_msg_data;
          held_len   <= s_msg_len;
        end
        2'b01: begin
          held_valid <= 1'b0;
        end
        2'b11: begin
          held_valid <= 1'b1;
          held_data  <= s_msg_data;
          held_len   <= s_msg_len;
        end
        default: ;
      endcase

      if (drain) begin
        m_msg_data  <= held_data;
        m_msg_len   <= held_len;
        m_msg_valid <= 1'b1;
      end else if (m_msg_valid && m_msg_ready) begin
        m_msg_valid <= 1'b0;
      end
    end
  end
endmodule : udp_payload_framer
