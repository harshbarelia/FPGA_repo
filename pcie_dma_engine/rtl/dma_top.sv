
// dma_top.sv
// Top-level integration: PCIe hard IP exposes AXI4-LITE ONLY (no
// full AXI4 MM port). Custom RING-BUFFER descriptor-driven DMA
// engine (H2C/C2H) shares a SINGLE AXI4-Lite master port via a
// mutex-style arbiter (axi4_arbiter), since AXI4-Lite has no ID
// field and only one outstanding transaction at a time - unlike a
// full AXI4 design, requests cannot be ID-routed and must be
// granted exclusive ownership of the shared port for their entire
// transaction.
//
// Descriptor storage model: circular ring buffer with SW-owned
// tail_ptr (doorbell register) and HW-owned head_ptr (progress,
// read-only from SW).
//
// H2C moves data HOST DDR -> local BRAM.
// C2H moves data local BRAM -> HOST DDR.
import dma_pkg::*;

module dma_top (
    input  logic clk,
    input  logic rst_n,

    // CSR slave port (BAR0) - AXI4-Lite
    input  logic [11:0]  s_axil_awaddr,
    input  logic         s_axil_awvalid,
    output logic         s_axil_awready,
    input  logic [31:0]  s_axil_wdata,
    input  logic [3:0]   s_axil_wstrb,
    input  logic         s_axil_wvalid,
    output logic         s_axil_wready,
    output logic [1:0]   s_axil_bresp,
    output logic         s_axil_bvalid,
    input  logic         s_axil_bready,
    input  logic [11:0]  s_axil_araddr,
    input  logic         s_axil_arvalid,
    output logic         s_axil_arready,
    output logic [31:0]  s_axil_rdata,
    output logic [1:0]   s_axil_rresp,
    output logic         s_axil_rvalid,
    input  logic         s_axil_rready,

    // Shared AXI4-Lite MASTER port (data path: descriptor fetch +
    // H2C/C2H data movement, all single-beat, arbitrated)
    output logic [31:0]  m_axil_araddr,
    output logic         m_axil_arvalid,
    input  logic         m_axil_arready,
    input  logic [31:0]  m_axil_rdata,
    input  logic         m_axil_rvalid,
    output logic         m_axil_rready,

    output logic [31:0]  m_axil_awaddr,
    output logic         m_axil_awvalid,
    input  logic         m_axil_awready,
    output logic [31:0]  m_axil_wdata,
    output logic         m_axil_wvalid,
    input  logic         m_axil_wready,
    input  logic         m_axil_bvalid,
    output logic         m_axil_bready,

    output logic          msix_irq
);

    logic        dma_enable, irq_enable;
    logic [31:0] ring_base_addr;
    logic [RING_IDX_W-1:0] ring_size;
    logic [RING_PTR_W-1:0] tail_ptr, head_ptr;
    logic        dma_done, dma_error;
    logic [31:0] desc_completed_cnt;

    logic       desc_busy, desc_valid, desc_consumed;
    dma_desc_t  desc_out;

    logic h2c_ack, h2c_done, c2h_ack, c2h_done;

    // Port 0: desc_fetch (read-only)
    logic [31:0] df_araddr; logic df_arvalid, df_arready;
    logic [31:0] df_rdata;  logic df_rvalid, df_rready;
    logic        df_req, df_gnt;

    // Port 1: h2c (read + write)
    logic [31:0] h2c_araddr, h2c_awaddr; logic [31:0] h2c_wdata; logic [31:0] h2c_rdata;
    logic h2c_arvalid, h2c_arready, h2c_awvalid, h2c_awready, h2c_wvalid, h2c_wready;
    logic h2c_rvalid, h2c_rready, h2c_bvalid, h2c_bready;
    logic h2c_req, h2c_gnt;

    // Port 2: c2h (read + write)
    logic [31:0] c2h_araddr, c2h_awaddr; logic [31:0] c2h_wdata; logic [31:0] c2h_rdata;
    logic c2h_arvalid, c2h_arready, c2h_awvalid, c2h_awready, c2h_wvalid, c2h_wready;
    logic c2h_rvalid, c2h_rready, c2h_bvalid, c2h_bready;
    logic c2h_req, c2h_gnt;

    assign dma_done  = h2c_done | c2h_done;
    assign dma_error = 1'b0;
    assign desc_consumed = h2c_ack | c2h_ack;

    // req = held high continuously throughout the engine's active states
    // to prevent arbiter grant dropped-lock glitches.
    assign df_req  = desc_busy;
    assign h2c_req = (u_h2c.state != 3'd0); // active (non-IDLE)
    assign c2h_req = (u_c2h.state != 3'd0); // active (non-IDLE)

    axi_lite_csr u_csr (
        .clk(clk), .rst_n(rst_n),
        .s_axil_awaddr(s_axil_awaddr), .s_axil_awvalid(s_axil_awvalid), .s_axil_awready(s_axil_awready),
        .s_axil_wdata(s_axil_wdata), .s_axil_wstrb(s_axil_wstrb), .s_axil_wvalid(s_axil_wvalid), .s_axil_wready(s_axil_wready),
        .s_axil_bresp(s_axil_bresp), .s_axil_bvalid(s_axil_bvalid), .s_axil_bready(s_axil_bready),
        .s_axil_araddr(s_axil_araddr), .s_axil_arvalid(s_axil_arvalid), .s_axil_arready(s_axil_arready),
        .s_axil_rdata(s_axil_rdata), .s_axil_rresp(s_axil_rresp), .s_axil_rvalid(s_axil_rvalid), .s_axil_rready(s_axil_rready),
        .dma_enable(dma_enable),
        .ring_base_addr(ring_base_addr), .ring_size(ring_size), .tail_ptr(tail_ptr), .head_ptr(head_ptr),
        .irq_enable(irq_enable),
        .dma_done(dma_done), .dma_error(dma_error), .desc_completed_cnt(desc_completed_cnt)
    );

    desc_fetch_engine u_desc_fetch (
        .clk(clk), .rst_n(rst_n),
        .dma_enable(dma_enable),
        .ring_base_addr(ring_base_addr), .ring_size(ring_size), .tail_ptr(tail_ptr), .head_ptr(head_ptr),
        .busy(desc_busy), .desc_valid(desc_valid), .desc_out(desc_out), .desc_consumed(desc_consumed),
        .m_axil_araddr(df_araddr), .m_axil_arvalid(df_arvalid), .m_axil_arready(df_arready),
        .m_axil_rdata(df_rdata), .m_axil_rvalid(df_rvalid), .m_axil_rready(df_rready)
    );

    h2c_engine u_h2c (
        .clk(clk), .rst_n(rst_n),
        .desc_valid(desc_valid && !desc_out.control[3]), .desc_in(desc_out), .desc_ack(h2c_ack), .xfer_done(h2c_done),
        .m_axil_araddr(h2c_araddr), .m_axil_arvalid(h2c_arvalid), .m_axil_arready(h2c_arready),
        .m_axil_rdata(h2c_rdata), .m_axil_rvalid(h2c_rvalid), .m_axil_rready(h2c_rready),
        .m_axil_awaddr(h2c_awaddr), .m_axil_awvalid(h2c_awvalid), .m_axil_awready(h2c_awready),
        .m_axil_wdata(h2c_wdata), .m_axil_wvalid(h2c_wvalid), .m_axil_wready(h2c_wready),
        .m_axil_bvalid(h2c_bvalid), .m_axil_bready(h2c_bready)
    );

    c2h_engine u_c2h (
        .clk(clk), .rst_n(rst_n),
        .desc_valid(desc_valid && desc_out.control[3]), .desc_in(desc_out), .desc_ack(c2h_ack), .xfer_done(c2h_done),
        .m_axil_araddr(c2h_araddr), .m_axil_arvalid(c2h_arvalid), .m_axil_arready(c2h_arready),
        .m_axil_rdata(c2h_rdata), .m_axil_rvalid(c2h_rvalid), .m_axil_rready(c2h_rready),
        .m_axil_awaddr(c2h_awaddr), .m_axil_awvalid(c2h_awvalid), .m_axil_awready(c2h_awready),
        .m_axil_wdata(c2h_wdata), .m_axil_wvalid(c2h_wvalid), .m_axil_wready(c2h_wready),
        .m_axil_bvalid(c2h_bvalid), .m_axil_bready(c2h_bready)
    );

    axi4_arbiter u_arb (
        .clk(clk), .rst_n(rst_n),
        .p0_req(df_req), .p0_gnt(df_gnt),
        .p1_req(h2c_req), .p1_gnt(h2c_gnt),
        .p2_req(c2h_req), .p2_gnt(c2h_gnt),

        .p0_araddr(df_araddr), .p0_arvalid(df_arvalid), .p0_arready(df_arready),
        .p0_rdata(df_rdata), .p0_rvalid(df_rvalid), .p0_rready(df_rready),

        .p1_araddr(h2c_araddr), .p1_arvalid(h2c_arvalid), .p1_arready(h2c_arready),
        .p1_rdata(h2c_rdata), .p1_rvalid(h2c_rvalid), .p1_rready(h2c_rready),
        .p1_awaddr(h2c_awaddr), .p1_awvalid(h2c_awvalid), .p1_awready(h2c_awready),
        .p1_wdata(h2c_wdata), .p1_wvalid(h2c_wvalid), .p1_wready(h2c_wready),
        .p1_bvalid(h2c_bvalid), .p1_bready(h2c_bready),

        .p2_araddr(c2h_araddr), .p2_arvalid(c2h_arvalid), .p2_arready(c2h_arready),
        .p2_rdata(c2h_rdata), .p2_rvalid(c2h_rvalid), .p2_rready(c2h_rready),
        .p2_awaddr(c2h_awaddr), .p2_awvalid(c2h_awvalid), .p2_awready(c2h_awready),
        .p2_wdata(c2h_wdata), .p2_wvalid(c2h_wvalid), .p2_wready(c2h_wready),
        .p2_bvalid(c2h_bvalid), .p2_bready(c2h_bready),

        .m_axil_araddr(m_axil_araddr), .m_axil_arvalid(m_axil_arvalid), .m_axil_arready(m_axil_arready),
        .m_axil_rdata(m_axil_rdata), .m_axil_rvalid(m_axil_rvalid), .m_axil_rready(m_axil_rready),
        .m_axil_awaddr(m_axil_awaddr), .m_axil_awvalid(m_axil_awvalid), .m_axil_awready(m_axil_awready),
        .m_axil_wdata(m_axil_wdata), .m_axil_wvalid(m_axil_wvalid), .m_axil_wready(m_axil_wready),
        .m_axil_bvalid(m_axil_bvalid), .m_axil_bready(m_axil_bready)
    );

    irq_ctrl u_irq (
        .clk(clk), .rst_n(rst_n),
        .irq_enable(irq_enable), .h2c_done(h2c_done), .c2h_done(c2h_done),
        .msix_irq(msix_irq), .desc_completed_cnt(desc_completed_cnt)
    );

endmodule : dma_top
