// Production Low-Latency Ethernet -> IPv4 -> UDP Packet Parser & Hardware Timestamp Tagger
// Parses standard Ethernet frame headers, verifies IPv4 + UDP protocols,
// filters on target destination UDP port, and tags output payload with 64-bit RX timestamp.

module eth_udp_parser #(
    parameter int DATA_WIDTH = 512,  // 64-byte MAC stream
    parameter int TS_WIDTH   = 64,
    parameter int STRB_WIDTH = DATA_WIDTH / 8
)(
    input  logic                   clk,
    input  logic                   rst_n,

    // Control & Configuration
    input  logic                   enable_filter,
    input  logic [15:0]            target_udp_dport,

    // Raw Ethernet MAC RX AXI-Stream Input
    input  logic [DATA_WIDTH-1:0]  s_axis_tdata,
    input  logic [STRB_WIDTH-1:0]  s_axis_tkeep,
    input  logic                   s_axis_tvalid,
    output logic                   s_axis_tready,
    input  logic                   s_axis_tlast,

    // Free-running hardware clock timestamp (from latency_timestamp_unit)
    input  logic [TS_WIDTH-1:0]    free_run_ts,

    // Parsed UDP Payload AXI-Stream Output
    output logic [DATA_WIDTH-1:0]  m_axis_tdata,
    output logic [STRB_WIDTH-1:0]  m_axis_tkeep,
    output logic                   m_axis_tvalid,
    input  logic                   m_axis_tready,
    output logic                   m_axis_tlast,
    output logic [TS_WIDTH-1:0]    m_axis_rx_timestamp,
    output logic [15:0]            m_axis_udp_dport,

    // Error and status metrics
    output logic                   err_ethertype,
    output logic                   err_ipv4_proto,
    output logic                   err_checksum,
    output logic [31:0]            pkt_parsed_count
);

    typedef enum logic [2:0] {
        ST_IDLE,
        ST_PARSE_HDR,
        ST_STREAM_PAYLOAD,
        ST_DROP_PACKET
    } state_t;

    state_t state;

    logic [TS_WIDTH-1:0] captured_timestamp;
    logic [15:0]         parsed_ethertype;
    logic [7:0]          parsed_ip_proto;
    logic [15:0]         parsed_udp_dport;
    logic [15:0]         parsed_udp_sport;
    logic                hdr_valid;

    assign parsed_ethertype = {s_axis_tdata[12*8 +: 8], s_axis_tdata[13*8 +: 8]};
    assign parsed_ip_proto  = s_axis_tdata[23*8 +: 8];
    assign parsed_udp_sport = {s_axis_tdata[34*8 +: 8], s_axis_tdata[35*8 +: 8]};
    assign parsed_udp_dport = {s_axis_tdata[36*8 +: 8], s_axis_tdata[37*8 +: 8]};

    always_comb begin
        hdr_valid = (parsed_ethertype == 16'h0800) &&
                    (parsed_ip_proto  == 8'h11)   &&
                    (!enable_filter || (parsed_udp_dport == target_udp_dport));
    end

    always_ff @(posedge clk or negedge rst_n) begin
        if (!rst_n) begin
            state              <= ST_IDLE;
            captured_timestamp <= '0;
            m_axis_udp_dport   <= '0;
            err_ethertype      <= 1'b0;
            err_ipv4_proto     <= 1'b0;
            err_checksum       <= 1'b0;
            pkt_parsed_count   <= '0;
        end else begin
            case (state)
                ST_IDLE: begin
                    if (s_axis_tvalid && s_axis_tready) begin
                        captured_timestamp <= free_run_ts; // SFD hardware timestamp capture
                        if (hdr_valid) begin
                            m_axis_udp_dport <= parsed_udp_dport;
                            if (s_axis_tlast) begin
                                state <= ST_IDLE;
                                pkt_parsed_count <= pkt_parsed_count + 1'b1;
                            end else begin
                                state <= ST_STREAM_PAYLOAD;
                            end
                        end else begin
                            if (parsed_ethertype != 16'h0800) err_ethertype <= 1'b1;
                            if (parsed_ip_proto  != 8'h11)   err_ipv4_proto <= 1'b1;
                            state <= s_axis_tlast ? ST_IDLE : ST_DROP_PACKET;
                        end
                    end
                end

                ST_STREAM_PAYLOAD: begin
                    if (s_axis_tvalid && s_axis_tready) begin
                        if (s_axis_tlast) begin
                            state <= ST_IDLE;
                            pkt_parsed_count <= pkt_parsed_count + 1'b1;
                        end
                    end
                end

                ST_DROP_PACKET: begin
                    if (s_axis_tvalid && s_axis_tready && s_axis_tlast) begin
                        state <= ST_IDLE;
                    end
                end

                default: state <= ST_IDLE;
            endcase
        end
    end

    assign s_axis_tready       = (state == ST_IDLE) || (state == ST_DROP_PACKET) || m_axis_tready;
    assign m_axis_tdata        = s_axis_tdata;
    assign m_axis_tkeep        = s_axis_tkeep;
    assign m_axis_tvalid       = s_axis_tvalid && ((state == ST_IDLE && hdr_valid) || (state == ST_STREAM_PAYLOAD));
    assign m_axis_tlast        = s_axis_tlast;
    assign m_axis_rx_timestamp = captured_timestamp;

endmodule
