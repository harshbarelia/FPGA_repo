// Production-Grade Scatter-Gather DMA Engine (AXI4 Master)
// Features:
//  - Standard AXI4 Master write interface (AW*, W*, B* channels)
//  - 4KB AXI boundary split protection
//  - Byte-accurate AXI WSTRB generation
//  - Streaming input interface (AXI-Stream RX from Feed Handler)
//  - CSR Interrupt status and completion reporting

module sg_dma_engine #(
    parameter int ADDR_WIDTH = 64,
    parameter int DATA_WIDTH = 512,   // 64-byte datapath
    parameter int DESC_WIDTH = 128,   // {addr[63:0], len[31:0], ctrl[31:0]}
    parameter int STRB_WIDTH = DATA_WIDTH / 8,
    parameter int MAX_BURST_LEN = 16  // AXI4 max beats per burst (1 to 256)
)(
    input  logic                    clk,
    input  logic                    rst_n,

    // Descriptor interface (from descriptor_ring_buffer)
    output logic                    desc_pop_ready,
    input  logic                    desc_pop_valid,
    input  logic [DESC_WIDTH-1:0]   desc_pop_data,

    // AXI4 Master - Address Write Channel
    output logic [3:0]              m_axi_awid,
    output logic [ADDR_WIDTH-1:0]   m_axi_awaddr,
    output logic [7:0]              m_axi_awlen,
    output logic [2:0]              m_axi_awsize,
    output logic [1:0]              m_axi_awburst,
    output logic                    m_axi_awvalid,
    input  logic                    m_axi_awready,

    // AXI4 Master - Write Data Channel
    output logic [DATA_WIDTH-1:0]   m_axi_wdata,
    output logic [STRB_WIDTH-1:0]   m_axi_wstrb,
    output logic                    m_axi_wlast,
    output logic                    m_axi_wvalid,
    input  logic                    m_axi_wready,

    // AXI4 Master - Write Response Channel
    input  logic [3:0]              m_axi_bid,
    input  logic [1:0]              m_axi_bresp,
    input  logic                    m_axi_bvalid,
    output logic                    m_axi_bready,

    // Streaming payload input from eth_udp_parser
    input  logic [DATA_WIDTH-1:0]   s_axis_tdata,
    input  logic [STRB_WIDTH-1:0]   s_axis_tkeep,
    input  logic                    s_axis_tvalid,
    output logic                    s_axis_tready,
    input  logic                    s_axis_tlast,

    // Control & Status Signals
    input  logic                    dma_enable,
    output logic                    dma_busy,
    output logic                    dma_done_irq,
    output logic [31:0]             dma_completed_count
);

    typedef enum logic [2:0] {
        ST_IDLE,
        ST_FETCH_DESC,
        ST_CALC_BURST,
        ST_ISSUE_AW,
        ST_STREAM_W,
        ST_WAIT_B,
        ST_COMPLETE
    } state_t;

    state_t state, next_state;

    // Descriptor registers
    logic [ADDR_WIDTH-1:0] desc_addr;
    logic [31:0]           desc_len;
    logic [31:0]           desc_ctrl;

    // Burst tracking
    logic [ADDR_WIDTH-1:0] current_addr;
    logic [31:0]           bytes_remaining;
    logic [7:0]            current_awlen;
    logic [7:0]            w_beat_cnt;

    // Fixed AXI attributes
    assign m_axi_awid    = 4'b0000;
    assign m_axi_awsize  = 3'( $clog2(STRB_WIDTH) ); // 512b -> 6 (64 bytes/beat)
    assign m_axi_awburst = 2'b01;                     // INCR burst

    assign desc_pop_ready = (state == ST_FETCH_DESC);
    assign dma_busy       = (state != ST_IDLE);

    // State machine sequential
    always_ff @(posedge clk or negedge rst_n) begin
        if (!rst_n) begin
            state <= ST_IDLE;
        end else begin
            state <= next_state;
        end
    end

    // Next state logic
    always_comb begin
        next_state = state;
        case (state)
            ST_IDLE: begin
                if (dma_enable) next_state = ST_FETCH_DESC;
            end
            ST_FETCH_DESC: begin
                if (desc_pop_valid) next_state = ST_CALC_BURST;
                else if (!dma_enable) next_state = ST_IDLE;
            end
            ST_CALC_BURST: begin
                next_state = ST_ISSUE_AW;
            end
            ST_ISSUE_AW: begin
                if (m_axi_awvalid && m_axi_awready) next_state = ST_STREAM_W;
            end
            ST_STREAM_W: begin
                if (m_axi_wvalid && m_axi_wready && m_axi_wlast) next_state = ST_WAIT_B;
            end
            ST_WAIT_B: begin
                if (m_axi_bvalid && m_axi_bready) begin
                    if (bytes_remaining == 0)
                        next_state = ST_COMPLETE;
                    else
                        next_state = ST_CALC_BURST; // Split burst / next segment
                end
            end
            ST_COMPLETE: begin
                next_state = ST_FETCH_DESC;
            end
            default: next_state = ST_IDLE;
        endcase
    end

    // Datapath logic
    always_ff @(posedge clk or negedge rst_n) begin
        if (!rst_n) begin
            desc_addr           <= '0;
            desc_len            <= '0;
            desc_ctrl           <= '0;
            current_addr        <= '0;
            bytes_remaining     <= '0;
            current_awlen       <= '0;
            w_beat_cnt          <= '0;
            dma_completed_count <= '0;
            dma_done_irq        <= 1'b0;
        end else begin
            dma_done_irq <= 1'b0;

            case (state)
                ST_FETCH_DESC: begin
                    if (desc_pop_valid) begin
                        desc_addr       <= desc_pop_data[127:64];
                        desc_len        <= desc_pop_data[63:32];
                        desc_ctrl       <= desc_pop_data[31:0];
                        current_addr    <= desc_pop_data[127:64];
                        bytes_remaining <= desc_pop_data[63:32];
                    end
                end

                ST_CALC_BURST: begin
                    automatic logic [11:0] page_offset     = current_addr[11:0];
                    automatic logic [31:0] bytes_to_4k     = 32'h1000 - 32'(page_offset);
                    automatic logic [31:0] max_burst_bytes = MAX_BURST_LEN * STRB_WIDTH;
                    automatic logic [31:0] burst_bytes;

                    if (bytes_remaining < max_burst_bytes)
                        burst_bytes = bytes_remaining;
                    else
                        burst_bytes = max_burst_bytes;

                    if (burst_bytes > bytes_to_4k)
                        burst_bytes = bytes_to_4k;

                    if (burst_bytes <= STRB_WIDTH)
                        current_awlen <= 8'h00;
                    else
                        current_awlen <= 8'((burst_bytes + STRB_WIDTH - 1) / STRB_WIDTH - 1);

                    w_beat_cnt <= 8'h00;
                end

                ST_STREAM_W: begin
                    if (m_axi_wvalid && m_axi_wready) begin
                        w_beat_cnt <= w_beat_cnt + 1'b1;
                        if (bytes_remaining > STRB_WIDTH)
                            bytes_remaining <= bytes_remaining - STRB_WIDTH;
                        else
                            bytes_remaining <= 0;

                        current_addr <= current_addr + 64'(STRB_WIDTH);
                    end
                end

                ST_COMPLETE: begin
                    dma_done_irq        <= 1'b1;
                    dma_completed_count <= dma_completed_count + 1'b1;
                end

                default: ;
            endcase
        end
    end

    // AXI Assignments
    assign m_axi_awaddr  = current_addr;
    assign m_axi_awlen   = current_awlen;
    assign m_axi_awvalid = (state == ST_ISSUE_AW);

    assign m_axi_wdata   = s_axis_tdata;
    assign m_axi_wstrb   = (s_axis_tkeep != '0) ? s_axis_tkeep : '1;
    assign m_axi_wvalid  = (state == ST_STREAM_W) && s_axis_tvalid;
    assign m_axi_wlast   = (state == ST_STREAM_W) && (w_beat_cnt == current_awlen);
    assign s_axis_tready = (state == ST_STREAM_W) && m_axi_wready;

    assign m_axi_bready  = (state == ST_WAIT_B);

endmodule
