//==============================================================================
// pcie_dma_top.sv
// Top-level integration: wires descriptor engine, C2H/H2C DMA engines, TLP
// parser/generator, TLP request arbiter, MSI-X controller/table, AXI bridges,
// and CDC blocks together.
//
// Upgraded to support Multi-Beat Payload Streaming.
//==============================================================================
module pcie_dma_top #(
    parameter int RING_DEPTH  = 128,
    parameter int PTR_WIDTH   = $clog2(RING_DEPTH) + 1,
    parameter int AXIS_WIDTH  = 256,
    parameter int MPS_BYTES   = 256,
    parameter int MRRS_BYTES  = 512
)(
    input  logic core_clk,
    input  logic core_rst_n,
    input  logic pcie_clk,
    input  logic pcie_rst_n,

    // AXI4-Lite register interface (software/CPU facing)
    input  logic [31:0] s_axi_awaddr,
    input  logic         s_axi_awvalid,
    output logic         s_axi_awready,
    input  logic [31:0] s_axi_wdata,
    input  logic         s_axi_wvalid,
    output logic         s_axi_wready,
    output logic [1:0]  s_axi_bresp,
    output logic         s_axi_bvalid,
    input  logic         s_axi_bready,
    input  logic [31:0] s_axi_araddr,
    input  logic         s_axi_arvalid,
    output logic         s_axi_arready,
    output logic [31:0] s_axi_rdata,
    output logic [1:0]  s_axi_rresp,
    output logic         s_axi_rvalid,
    input  logic         s_axi_rready,

    // PCIe hard IP TX/RX AXI4-Stream (pcie_clk domain)
    output logic [AXIS_WIDTH-1:0] pcie_m_axis_tdata,
    output logic         pcie_m_axis_tvalid,
    output logic         pcie_m_axis_tlast,
    input  logic         pcie_m_axis_tready,

    input  logic [AXIS_WIDTH-1:0] pcie_s_axis_tdata,
    input  logic         pcie_s_axis_tvalid,
    input  logic         pcie_s_axis_tlast,
    output logic         pcie_s_axis_tready,

    // FPGA-side user data interfaces (core_clk domain)
    input  logic [AXIS_WIDTH-1:0] user_c2h_tdata,
    input  logic         user_c2h_tvalid,
    input  logic         user_c2h_tlast,
    output logic         user_c2h_tready,

    output logic [AXIS_WIDTH-1:0] user_h2c_tdata,
    output logic         user_h2c_tvalid,
    output logic         user_h2c_tlast,
    input  logic         user_h2c_tready,

    // Credit status from PCIe hard IP (pcie_clk domain)
    input  logic         posted_hdr_credit_avail,
    input  logic         posted_data_credit_avail,
    input  logic         nonposted_hdr_credit_avail
);

    // ==================================================================
    // Internal wires
    // ==================================================================

    // Register block outputs
    logic [63:0] reg_desc_ring_base;
    logic [31:0] reg_wb_intr_timeout;
    logic [31:0] sw_insert_ptr_wr;
    logic        sw_insert_ptr_wr_en;
    logic [31:0] hw_extract_ptr_rd;
    logic        msix_reg_wr_en;
    logic [31:0] msix_reg_wr_addr, msix_reg_wr_data;
    logic        msix_reg_rd_en;
    logic [31:0] msix_reg_rd_addr, msix_reg_rd_data;

    // Ring manager
    logic [PTR_WIDTH-1:0] insert_ptr, extract_ptr;
    logic ring_empty, ring_full, extract_valid;
    logic extract_ptr_update, extract_valid_req;

    // Descriptor fetch
    logic desc_rd_req;
    logic [63:0] desc_rd_addr;
    logic desc_rd_valid;
    logic [255:0] desc_rd_data;
    logic [63:0] desc_src_addr, desc_dst_addr;
    logic [31:0] desc_len;
    logic desc_dir, desc_irq_en, decode_error;
    logic dispatch_valid, dispatch_ack;
    logic xfer_done, xfer_error;
    logic writeback_req, writeback_done;
    logic [3:0] state_dbg;

    // DMA engine dispatch demux
    logic c2h_dispatch_valid, c2h_dispatch_ack, c2h_xfer_done, c2h_xfer_error;
    logic h2c_dispatch_valid, h2c_dispatch_ack, h2c_xfer_done, h2c_xfer_error;

    // TLP arbiter port signals
    // Port 0: desc_fetch (descriptor read requests)
    logic        p0_req_valid, p0_req_ack;
    logic [2:0]  p0_req_type;
    logic [63:0] p0_req_addr;
    logic [31:0] p0_req_len;
    logic [9:0]  p0_req_tag;

    // Port 1: h2c_engine
    logic        p1_req_valid, p1_req_ack;
    logic [2:0]  p1_req_type;
    logic [63:0] p1_req_addr;
    logic [31:0] p1_req_len;
    logic [9:0]  p1_req_tag;

    // Port 2: c2h_engine
    logic        p2_req_valid, p2_req_ack;
    logic [2:0]  p2_req_type;
    logic [63:0] p2_req_addr;
    logic [31:0] p2_req_len;
    logic [9:0]  p2_req_tag;

    // Port 3: writeback + MSI-X
    logic        p3_req_valid, p3_req_ack;
    logic [2:0]  p3_req_type;
    logic [63:0] p3_req_addr;
    logic [31:0] p3_req_len;
    logic [AXIS_WIDTH-1:0] p3_req_payload;
    logic [9:0]  p3_req_tag;

    // Arbiter -> TLP generator
    logic        arb_req_valid, arb_req_ack;
    logic [2:0]  arb_req_type;
    logic [63:0] arb_req_addr;
    logic [31:0] arb_req_len;
    logic [9:0]  arb_req_tag;

    // Streaming payload signals
    logic [AXIS_WIDTH-1:0] p0_payload_tdata, p1_payload_tdata, p2_payload_tdata, p3_payload_tdata;
    logic                  p0_payload_tvalid, p1_payload_tvalid, p2_payload_tvalid, p3_payload_tvalid;
    logic                  p0_payload_tready, p1_payload_tready, p2_payload_tready, p3_payload_tready;
    logic                  p0_payload_tlast, p1_payload_tlast, p2_payload_tlast, p3_payload_tlast;
    logic                  p0_grant, p1_grant, p2_grant, p3_grant;

    logic [AXIS_WIDTH-1:0] arb_payload_tdata;
    logic                  arb_payload_tvalid;
    logic                  arb_payload_tready;
    logic                  arb_payload_tlast;

    // TLP generator -> TX AXIS (core_clk domain)
    logic [AXIS_WIDTH-1:0] core_tx_tdata;
    logic        core_tx_tvalid, core_tx_tlast, core_tx_tready;

    // TLP parser <- RX AXIS (core_clk domain)
    logic [AXIS_WIDTH-1:0] core_rx_tdata;
    logic        core_rx_tvalid, core_rx_tlast, core_rx_tready;

    // TLP parser outputs
    logic        cpld_valid;
    logic [9:0]  cpld_tag;
    logic [255:0] cpld_data;
    logic        cpld_last, cpld_malformed;
    logic        parser_desc_rd_valid;
    logic [255:0] parser_desc_rd_data;

    // Completion / MSI-X
    logic        wb_wr_req;
    logic [63:0] wb_wr_addr;
    logic [31:0] wb_wr_data;
    logic        wb_wr_ack;
    logic [15:0] pending_completions;
    logic        msix_fire;
    logic        wb_event_pulse;
    logic [31:0] wb_intr_timeout_cfg;
    logic [7:0]  msix_vector_sel;
    logic        msix_wr_req;
    logic [63:0] msix_wr_addr;
    logic [31:0] msix_wr_data;
    logic        msix_wr_ack;

    // Credit sync
    logic posted_hdr_credit_sync, posted_data_credit_sync, nonposted_hdr_credit_sync;

    // ==================================================================
    // AXI4-Lite Register Block
    // ==================================================================
    axi4_mm_bridge u_axi_mm (
        .clk(core_clk), .rst_n(core_rst_n),
        .s_axi_awaddr, .s_axi_awvalid, .s_axi_awready,
        .s_axi_wdata, .s_axi_wvalid, .s_axi_wready,
        .s_axi_bresp, .s_axi_bvalid, .s_axi_bready,
        .s_axi_araddr, .s_axi_arvalid, .s_axi_arready,
        .s_axi_rdata, .s_axi_rresp, .s_axi_rvalid, .s_axi_rready,
        .reg_desc_ring_base, .reg_wb_intr_timeout,
        .sw_insert_ptr_wr, .sw_insert_ptr_wr_en,
        .hw_extract_ptr_rd({{(32-PTR_WIDTH){1'b0}}, extract_ptr}),
        .msix_reg_wr_en, .msix_reg_wr_addr, .msix_reg_wr_data,
        .msix_reg_rd_en, .msix_reg_rd_addr, .msix_reg_rd_data
    );

    // ==================================================================
    // Descriptor Ring Manager
    // ==================================================================
    desc_ring_mgr #(.RING_DEPTH(RING_DEPTH)) u_ring_mgr (
        .clk(core_clk), .rst_n(core_rst_n),
        .sw_insert_ptr_wr(sw_insert_ptr_wr[PTR_WIDTH-1:0]),
        .sw_insert_ptr_wr_en(sw_insert_ptr_wr_en),
        .hw_extract_ptr_rd(),
        .insert_ptr, .extract_ptr,
        .extract_ptr_update, .extract_valid_req,
        .ring_empty, .ring_full, .extract_valid,
        .insert_ptr_update_dbg(), .extract_ptr_update_dbg()
    );

    // ==================================================================
    // Descriptor Fetch FSM
    // ==================================================================
    desc_fetch #(.RING_DEPTH(RING_DEPTH)) u_desc_fetch (
        .clk(core_clk), .rst_n(core_rst_n),
        .desc_base_addr(reg_desc_ring_base),
        .extract_valid,
        .extract_ptr,
        .extract_ptr_update,
        .extract_valid_req,
        .desc_rd_req,
        .desc_rd_addr,
        .desc_rd_valid(parser_desc_rd_valid),
        .desc_rd_data(parser_desc_rd_data),
        .desc_src_addr, .desc_dst_addr,
        .desc_len, .desc_dir, .desc_irq_en,
        .decode_error,
        .dispatch_valid, .dispatch_ack,
        .xfer_done, .xfer_error,
        .writeback_req, .writeback_done,
        .state_dbg
    );

    // ==================================================================
    // Dispatch Demux
    // ==================================================================
    assign c2h_dispatch_valid = dispatch_valid && desc_dir;
    assign h2c_dispatch_valid = dispatch_valid && !desc_dir;

    assign dispatch_ack = desc_dir ? c2h_dispatch_ack : h2c_dispatch_ack;
    assign xfer_done    = desc_dir ? c2h_xfer_done    : h2c_xfer_done;
    assign xfer_error   = desc_dir ? c2h_xfer_error   : h2c_xfer_error;

    // ==================================================================
    // C2H DMA Engine (Multi-beat writer)
    // ==================================================================
    c2h_engine #(.AXIS_WIDTH(AXIS_WIDTH), .MPS_BYTES(MPS_BYTES)) u_c2h (
        .clk(core_clk), .rst_n(core_rst_n),
        .dispatch_valid(c2h_dispatch_valid),
        .dst_addr(desc_dst_addr),
        .xfer_len(desc_len),
        .dispatch_ack(c2h_dispatch_ack),
        .xfer_done(c2h_xfer_done),
        .xfer_error(c2h_xfer_error),
        .s_axis_tdata(user_c2h_tdata),
        .s_axis_tvalid(user_c2h_tvalid),
        .s_axis_tlast(user_c2h_tlast),
        .s_axis_tready(user_c2h_tready),
        .tlp_req_valid(p2_req_valid),
        .tlp_req_type(p2_req_type),
        .tlp_req_addr(p2_req_addr),
        .tlp_req_len(p2_req_len),
        .tlp_req_tag(p2_req_tag),
        .tlp_req_grant(p2_grant),
        .tlp_req_ack(p2_req_ack),
        .tlp_payload_tdata(p2_payload_tdata),
        .tlp_payload_tvalid(p2_payload_tvalid),
        .tlp_payload_tready(p2_payload_tready),
        .tlp_payload_tlast(p2_payload_tlast)
    );

    // ==================================================================
    // H2C DMA Engine (Multi-beat reader with elastic buffer)
    // ==================================================================
    h2c_engine #(.AXIS_WIDTH(AXIS_WIDTH), .MAX_READ_REQ_BYTES(MRRS_BYTES)) u_h2c (
        .clk(core_clk), .rst_n(core_rst_n),
        .dispatch_valid(h2c_dispatch_valid),
        .src_addr(desc_src_addr),
        .xfer_len(desc_len),
        .dispatch_ack(h2c_dispatch_ack),
        .xfer_done(h2c_xfer_done),
        .xfer_error(h2c_xfer_error),
        .tlp_req_valid(p1_req_valid),
        .tlp_req_type(p1_req_type),
        .tlp_req_addr(p1_req_addr),
        .tlp_req_len(p1_req_len),
        .tlp_req_tag(p1_req_tag),
        .tlp_req_payload(),
        .tlp_req_ack(p1_req_ack),
        .cpld_valid,
        .cpld_tag,
        .cpld_data(cpld_data[AXIS_WIDTH-1:0]),
        .cpld_last,
        .cpld_malformed,
        .m_axis_tdata(user_h2c_tdata),
        .m_axis_tvalid(user_h2c_tvalid),
        .m_axis_tlast(user_h2c_tlast),
        .m_axis_tready(user_h2c_tready)
    );

    // ==================================================================
    // Port 0: desc_fetch (No payload write stream)
    // ==================================================================
    assign p0_req_valid      = desc_rd_req;
    assign p0_req_type       = 3'd0;
    assign p0_req_addr       = desc_rd_addr;
    assign p0_req_len        = 32'd32;
    assign p0_req_tag        = 10'd0;
    assign p0_payload_tdata  = '0;
    assign p0_payload_tvalid = 1'b0;
    assign p0_payload_tlast  = 1'b0;

    // ==================================================================
    // Port 1: h2c_engine (No payload write stream)
    // ==================================================================
    assign p1_payload_tdata  = '0;
    assign p1_payload_tvalid = 1'b0;
    assign p1_payload_tlast  = 1'b0;

    // ==================================================================
    // Descriptor Completion + Writeback
    // ==================================================================
    desc_completion #(.WB_INTR_TIMEOUT(256)) u_desc_completion (
        .clk(core_clk), .rst_n(core_rst_n),
        .writeback_req,
        .decode_error,
        .xfer_error,
        .writeback_done,
        .wb_target_addr(desc_dst_addr),
        .wb_wr_req,
        .wb_wr_addr,
        .wb_wr_data,
        .wb_wr_ack(p3_req_ack),
        .pending_completions,
        .msix_fire,
        .wb_event_pulse,
        .wb_intr_timeout_cfg
    );

    // ==================================================================
    // MSI-X Controller + Table
    // ==================================================================
    msix_ctrl u_msix_ctrl (
        .clk(core_clk), .rst_n(core_rst_n),
        .wb_event_pulse,
        .pending_completions,
        .wb_intr_timeout_cfg,
        .msix_fire,
        .msix_vector_sel
    );

    msix_table #(.NUM_VECTORS(8)) u_msix_table (
        .clk(core_clk), .rst_n(core_rst_n),
        .reg_wr_en(msix_reg_wr_en),
        .reg_wr_addr(msix_reg_wr_addr),
        .reg_wr_data(msix_reg_wr_data),
        .reg_rd_en(msix_reg_rd_en),
        .reg_rd_addr(msix_reg_rd_addr),
        .reg_rd_data(msix_reg_rd_data),
        .msix_fire,
        .msix_vector_sel,
        .msix_wr_req,
        .msix_wr_addr,
        .msix_wr_data,
        .msix_wr_ack(p3_req_ack)
    );

    // ==================================================================
    // Port 3: Writeback + MSI-X (Single-beat write stream)
    // ==================================================================
    assign p3_req_valid   = wb_wr_req || msix_wr_req;
    assign p3_req_type    = 3'd2;
    assign p3_req_addr    = wb_wr_req ? wb_wr_addr : msix_wr_addr;
    assign p3_req_len     = 32'd4;
    assign p3_req_payload = wb_wr_req ?
                            {{(AXIS_WIDTH-32){1'b0}}, wb_wr_data} :
                            {{(AXIS_WIDTH-32){1'b0}}, msix_wr_data};
    assign p3_req_tag     = 10'd0;

    assign p3_payload_tdata  = p3_req_payload;
    assign p3_payload_tvalid = p3_req_valid;
    assign p3_payload_tlast  = 1'b1;

    // ==================================================================
    // TLP Request Arbiter
    // ==================================================================
    tlp_req_arbiter #(.AXIS_WIDTH(AXIS_WIDTH)) u_arbiter (
        .clk(core_clk), .rst_n(core_rst_n),
        .p0_req_valid, .p0_req_type, .p0_req_addr, .p0_req_len,
        .p0_req_payload('0), .p0_req_tag, .p0_req_ack,
        .p0_grant(p0_grant),
        .p0_payload_tdata, .p0_payload_tvalid, .p0_payload_tready(), .p0_payload_tlast,

        .p1_req_valid, .p1_req_type, .p1_req_addr, .p1_req_len,
        .p1_req_payload('0), .p1_req_tag, .p1_req_ack,
        .p1_grant(p1_grant),
        .p1_payload_tdata, .p1_payload_tvalid, .p1_payload_tready(), .p1_payload_tlast,

        .p2_req_valid, .p2_req_type, .p2_req_addr, .p2_req_len,
        .p2_req_payload('0), .p2_req_tag, .p2_req_ack,
        .p2_grant(p2_grant),
        .p2_payload_tdata, .p2_payload_tvalid, .p2_payload_tready(p2_payload_tready), .p2_payload_tlast,

        .p3_req_valid, .p3_req_type, .p3_req_addr, .p3_req_len,
        .p3_req_payload(p3_req_payload), .p3_req_tag, .p3_req_ack,
        .p3_grant(p3_grant),
        .p3_payload_tdata, .p3_payload_tvalid, .p3_payload_tready(), .p3_payload_tlast,

        .arb_req_valid, .arb_req_type, .arb_req_addr, .arb_req_len,
        .arb_req_tag, .arb_req_ack,

        .arb_payload_tdata, .arb_payload_tvalid, .arb_payload_tready, .arb_payload_tlast
    );

    // ==================================================================
    // TLP Generator (core_clk domain)
    // ==================================================================
    tlp_generator #(.AXIS_WIDTH(AXIS_WIDTH)) u_tlp_gen (
        .clk(core_clk), .rst_n(core_rst_n),
        .req_valid(arb_req_valid),
        .req_type(arb_req_type),
        .req_addr(arb_req_addr),
        .req_length_bytes(arb_req_len),
        .req_tag(arb_req_tag),
        .req_ack(arb_req_ack),
        .payload_tdata(arb_payload_tdata),
        .payload_tvalid(arb_payload_tvalid),
        .payload_tready(arb_payload_tready),
        .payload_tlast(arb_payload_tlast),
        .posted_hdr_credit_avail(posted_hdr_credit_sync),
        .posted_data_credit_avail(posted_data_credit_sync),
        .nonposted_hdr_credit_avail(nonposted_hdr_credit_sync),
        .m_axis_tdata(core_tx_tdata),
        .m_axis_tvalid(core_tx_tvalid),
        .m_axis_tlast(core_tx_tlast),
        .m_axis_tready(core_tx_tready)
    );

    // ==================================================================
    // TLP Parser (core_clk domain)
    // ==================================================================
    tlp_parser #(.AXIS_WIDTH(AXIS_WIDTH)) u_tlp_parser (
        .clk(core_clk), .rst_n(core_rst_n),
        .s_axis_tdata(core_rx_tdata),
        .s_axis_tvalid(core_rx_tvalid),
        .s_axis_tlast(core_rx_tlast),
        .s_axis_tready(core_rx_tready),
        .cpld_valid,
        .cpld_tag,
        .cpld_data,
        .cpld_last,
        .cpld_malformed,
        .desc_rd_valid(parser_desc_rd_valid),
        .desc_rd_data(parser_desc_rd_data)
    );

    // ==================================================================
    // CDC: TX path (core_clk -> pcie_clk)
    // ==================================================================
    axi4_stream_bridge #(
        .CORE_AXIS_WIDTH(AXIS_WIDTH),
        .PCIE_AXIS_WIDTH(AXIS_WIDTH),
        .FIFO_ADDR_WIDTH(5)
    ) u_tx_cdc (
        .core_clk, .core_rst_n,
        .core_tdata(core_tx_tdata),
        .core_tvalid(core_tx_tvalid),
        .core_tlast(core_tx_tlast),
        .core_tready(core_tx_tready),
        .pcie_clk, .pcie_rst_n,
        .pcie_tdata(pcie_m_axis_tdata),
        .pcie_tvalid(pcie_m_axis_tvalid),
        .pcie_tlast(pcie_m_axis_tlast),
        .pcie_tready(pcie_m_axis_tready)
    );

    // ==================================================================
    // CDC: RX path (pcie_clk -> core_clk)
    // ==================================================================
    axi4_stream_bridge #(
        .CORE_AXIS_WIDTH(AXIS_WIDTH),
        .PCIE_AXIS_WIDTH(AXIS_WIDTH),
        .FIFO_ADDR_WIDTH(5)
    ) u_rx_cdc (
        .core_clk(pcie_clk), .core_rst_n(pcie_rst_n),
        .core_tdata(pcie_s_axis_tdata),
        .core_tvalid(pcie_s_axis_tvalid),
        .core_tlast(pcie_s_axis_tlast),
        .core_tready(pcie_s_axis_tready),
        .pcie_clk(core_clk), .pcie_rst_n(core_rst_n),
        .pcie_tdata(core_rx_tdata),
        .pcie_tvalid(core_rx_tvalid),
        .pcie_tlast(core_rx_tlast),
        .pcie_tready(core_rx_tready)
    );

    // ==================================================================
    // CDC: Credit signals
    // ==================================================================
    logic posted_hdr_s1, posted_hdr_s2;
    logic posted_data_s1, posted_data_s2;
    logic nonposted_hdr_s1, nonposted_hdr_s2;

    always_ff @(posedge core_clk or negedge core_rst_n) begin
        if (!core_rst_n) begin
            posted_hdr_s1  <= 1'b0; posted_hdr_s2  <= 1'b0;
            posted_data_s1 <= 1'b0; posted_data_s2 <= 1'b0;
            nonposted_hdr_s1 <= 1'b0; nonposted_hdr_s2 <= 1'b0;
        end else begin
            posted_hdr_s1  <= posted_hdr_credit_avail;
            posted_hdr_s2  <= posted_hdr_s1;
            posted_data_s1 <= posted_data_credit_avail;
            posted_data_s2 <= posted_data_s1;
            nonposted_hdr_s1 <= nonposted_hdr_credit_avail;
            nonposted_hdr_s2 <= nonposted_hdr_s1;
        end
    end

    assign posted_hdr_credit_sync     = posted_hdr_s2;
    assign posted_data_credit_sync    = posted_data_s2;
    assign nonposted_hdr_credit_sync  = nonposted_hdr_s2;

endmodule
