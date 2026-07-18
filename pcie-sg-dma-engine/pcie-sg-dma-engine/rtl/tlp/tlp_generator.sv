//==============================================================================
// tlp_generator.sv
// Builds outbound TLP headers for: Memory Read (descriptor fetch, H2C source
// read), Memory Write (C2H payload write, completion writeback). Interfaces
// to the PCIe hard IP's AXI4-Stream (e.g. Xilinx XDMA / Intel Avalon-ST) on
// the transmit side. Header format follows PCIe base spec 3-DW/4-DW headers.
//
// Supported req_type values:
//   0 = Memory Read (non-posted, descriptor fetch / H2C source read)
//   1 = Memory Write (posted, C2H payload write)
//   2 = Memory Write (posted, completion writeback / MSI-X)
//
// Upgraded to support Multi-Beat Payload Streaming.
//==============================================================================
module tlp_generator #(
    parameter int AXIS_WIDTH = 256   // hard-IP TX AXI-Stream width
)(
    input  logic         clk,
    input  logic          rst_n,

    // Request interface (from tlp_req_arbiter.sv)
    input  logic          req_valid,
    input  logic [2:0]    req_type,        // 0=MRd, 1=MWr(data), 2=MWr(writeback/MSI-X)
    input  logic [63:0]   req_addr,
    input  logic [31:0]   req_length_bytes,
    input  logic [9:0]    req_tag,
    output logic          req_ack,

    // Streaming Payload Interface (from the active master engine)
    input  logic [AXIS_WIDTH-1:0] payload_tdata,
    input  logic                  payload_tvalid,
    output logic                  payload_tready,
    input  logic                  payload_tlast,

    // Credit interface -- must check before asserting m_axis_tvalid
    input  logic          posted_hdr_credit_avail,
    input  logic          posted_data_credit_avail,
    input  logic          nonposted_hdr_credit_avail,

    // TX AXI4-Stream to PCIe hard IP
    output logic [AXIS_WIDTH-1:0] m_axis_tdata,
    output logic          m_axis_tvalid,
    output logic          m_axis_tlast,
    input  logic          m_axis_tready
);

    typedef enum logic [1:0] {TX_IDLE, TX_CHECK_CREDIT, TX_HDR, TX_PAYLOAD} tx_state_t;
    tx_state_t state;

    // Latched request fields
    logic [2:0]   req_type_r;
    logic [63:0]  req_addr_r;
    logic [31:0]  req_length_bytes_r;
    logic [9:0]   req_tag_r;

    // TLP header construction
    logic [31:0] hdr_dw0, hdr_dw1, hdr_dw2, hdr_dw3;
    logic        is_write;
    logic        use_4dw;
    logic [9:0]  length_dw;

    assign is_write  = (req_type_r != 3'd0);
    assign use_4dw   = (req_addr_r[63:32] != 32'h0);
    assign length_dw = (req_length_bytes_r[1:0] != 2'b00) ?
                        (req_length_bytes_r[11:2] + 10'd1) :
                         req_length_bytes_r[11:2];

    always_comb begin
        hdr_dw0 = 32'h0;
        if (is_write) begin
            hdr_dw0[31:29] = use_4dw ? 3'b011 : 3'b010;
        end else begin
            hdr_dw0[31:29] = use_4dw ? 3'b001 : 3'b000;
        end
        hdr_dw0[28:24] = 5'b00000;  // Type = Memory Request
        hdr_dw0[9:0]   = length_dw;

        hdr_dw1 = {16'h0100, req_tag_r[7:0], 4'hF, 4'hF};

        if (use_4dw) begin
            hdr_dw2 = req_addr_r[63:32];
            hdr_dw3 = {req_addr_r[31:2], 2'b00};
        end else begin
            hdr_dw2 = {req_addr_r[31:2], 2'b00};
            hdr_dw3 = 32'h0;
        end
    end

    // Credit check
    logic credit_ok;
    always_comb begin
        unique case (req_type_r)
            3'd0:    credit_ok = nonposted_hdr_credit_avail;
            3'd1,
            3'd2:    credit_ok = posted_hdr_credit_avail && posted_data_credit_avail;
            default: credit_ok = 1'b0;
        endcase
    end

    // State machine
    always_ff @(posedge clk or negedge rst_n) begin
        if (!rst_n) begin
            state <= TX_IDLE;
            req_type_r         <= '0;
            req_addr_r         <= '0;
            req_length_bytes_r <= '0;
            req_tag_r          <= '0;
        end else case (state)
            TX_IDLE: begin
                if (req_valid) begin
                    req_type_r         <= req_type;
                    req_addr_r         <= req_addr;
                    req_length_bytes_r <= req_length_bytes;
                    req_tag_r          <= req_tag;
                    state              <= TX_CHECK_CREDIT;
                end
            end
            TX_CHECK_CREDIT: begin
                if (credit_ok)
                    state <= TX_HDR;
            end
            TX_HDR: begin
                if (m_axis_tready) begin
                    if (is_write)
                        state <= TX_PAYLOAD;
                    else
                        state <= TX_IDLE;
                end
            end
            TX_PAYLOAD: begin
                // Transition back to IDLE when the last beat of the payload stream is accepted
                if (payload_tvalid && m_axis_tready && payload_tlast)
                    state <= TX_IDLE;
            end
            default: state <= TX_IDLE;
        endcase
    end

    // req_ack: asserted when the entire transfer finishes
    assign req_ack = ((state == TX_HDR) && m_axis_tready && !is_write) ||
                     ((state == TX_PAYLOAD) && payload_tvalid && m_axis_tready && payload_tlast);

    // m_axis_tvalid
    always_comb begin
        if (state == TX_HDR) begin
            m_axis_tvalid = 1'b1;
        end else if (state == TX_PAYLOAD) begin
            m_axis_tvalid = payload_tvalid;
        end else begin
            m_axis_tvalid = 1'b0;
        end
    end

    // payload_tready: ready to accept payload beats only during the payload phase
    assign payload_tready = (state == TX_PAYLOAD) && m_axis_tready;

    // m_axis_tlast: end of packet
    assign m_axis_tlast  = ((state == TX_HDR) && !is_write) || ((state == TX_PAYLOAD) && payload_tlast);

    // Data output mux
    always_comb begin
        m_axis_tdata = '0;
        if (state == TX_HDR) begin
            m_axis_tdata[31:0]   = hdr_dw0;
            m_axis_tdata[63:32]  = hdr_dw1;
            m_axis_tdata[95:64]  = hdr_dw2;
            if (use_4dw)
                m_axis_tdata[127:96] = hdr_dw3;
        end else if (state == TX_PAYLOAD) begin
            m_axis_tdata = payload_tdata;
        end
    end

endmodule
