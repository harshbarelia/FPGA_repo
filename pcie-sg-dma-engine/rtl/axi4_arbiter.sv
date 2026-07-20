
// axi4_arbiter.sv
// Mutex-style arbiter for the SINGLE shared AXI4-Lite master port.
// AXI4-Lite has no ID field and only one outstanding transaction at
// a time, so this cannot be an ID-routed arbiter like a full AXI4
// design would use. Instead, each requester (desc_fetch, H2C, C2H)
// asserts a "req" signal and gets an exclusive "gnt" that it must
// hold for its ENTIRE transaction (AR+R, or AW+W+B) before
// releasing (deasserting req). Round-robin priority among the three
// requesters when more than one requests in the same cycle.
import dma_pkg::*;

module axi4_arbiter (
    input  logic clk,
    input  logic rst_n,

    input  logic p0_req, // desc_fetch
    output logic p0_gnt,
    input  logic p1_req, // h2c
    output logic p1_gnt,
    input  logic p2_req, // c2h
    output logic p2_gnt,

    // Port 0: desc_fetch (read-only)
    input  logic [31:0] p0_araddr, input logic p0_arvalid, output logic p0_arready,
    output logic [31:0] p0_rdata, output logic p0_rvalid, input logic p0_rready,

    // Port 1: h2c (read + write)
    input  logic [31:0] p1_araddr, input logic p1_arvalid, output logic p1_arready,
    output logic [31:0] p1_rdata, output logic p1_rvalid, input logic p1_rready,
    input  logic [31:0] p1_awaddr, input logic p1_awvalid, output logic p1_awready,
    input  logic [31:0] p1_wdata,  input logic p1_wvalid,  output logic p1_wready,
    output logic p1_bvalid, input logic p1_bready,

    // Port 2: c2h (read + write)
    input  logic [31:0] p2_araddr, input logic p2_arvalid, output logic p2_arready,
    output logic [31:0] p2_rdata, output logic p2_rvalid, input logic p2_rready,
    input  logic [31:0] p2_awaddr, input logic p2_awvalid, output logic p2_awready,
    input  logic [31:0] p2_wdata,  input logic p2_wvalid,  output logic p2_wready,
    output logic p2_bvalid, input logic p2_bready,

    // Shared AXI4-Lite master port (to PCIe hard IP / app fabric)
    output logic [31:0] m_axil_araddr, output logic m_axil_arvalid, input logic m_axil_arready,
    input  logic [31:0] m_axil_rdata,  input  logic m_axil_rvalid,  output logic m_axil_rready,
    output logic [31:0] m_axil_awaddr, output logic m_axil_awvalid, input logic m_axil_awready,
    output logic [31:0] m_axil_wdata,  output logic m_axil_wvalid,  input  logic m_axil_wready,
    input  logic m_axil_bvalid, output logic m_axil_bready
);

    typedef enum logic [1:0] {GNT_NONE, GNT_P0, GNT_P1, GNT_P2} gnt_t;
    gnt_t cur_gnt;
    logic [1:0] rr_ptr; // round-robin start pointer among {P0,P1,P2}

    assign p0_gnt = (cur_gnt == GNT_P0);
    assign p1_gnt = (cur_gnt == GNT_P1);
    assign p2_gnt = (cur_gnt == GNT_P2);

    always_ff @(posedge clk or negedge rst_n) begin
        if (!rst_n) begin
            cur_gnt <= GNT_NONE;
            rr_ptr  <= 2'd0;
        end else begin
            if (cur_gnt == GNT_NONE) begin
                unique case (rr_ptr)
                    2'd0: if (p0_req) begin cur_gnt <= GNT_P0; rr_ptr <= 2'd1; end
                          else if (p1_req) begin cur_gnt <= GNT_P1; rr_ptr <= 2'd2; end
                          else if (p2_req) begin cur_gnt <= GNT_P2; rr_ptr <= 2'd0; end
                    2'd1: if (p1_req) begin cur_gnt <= GNT_P1; rr_ptr <= 2'd2; end
                          else if (p2_req) begin cur_gnt <= GNT_P2; rr_ptr <= 2'd0; end
                          else if (p0_req) begin cur_gnt <= GNT_P0; rr_ptr <= 2'd1; end
                    2'd2: if (p2_req) begin cur_gnt <= GNT_P2; rr_ptr <= 2'd0; end
                          else if (p0_req) begin cur_gnt <= GNT_P0; rr_ptr <= 2'd1; end
                          else if (p1_req) begin cur_gnt <= GNT_P1; rr_ptr <= 2'd2; end
                    default: ;
                endcase
            end else begin
                case (cur_gnt)
                    GNT_P0: if (!p0_req) cur_gnt <= GNT_NONE;
                    GNT_P1: if (!p1_req) cur_gnt <= GNT_NONE;
                    GNT_P2: if (!p2_req) cur_gnt <= GNT_NONE;
                    default: cur_gnt <= GNT_NONE;
                endcase
            end
        end
    end

    always_comb begin
        m_axil_araddr = '0; m_axil_arvalid = 1'b0;
        m_axil_awaddr = '0; m_axil_awvalid = 1'b0;
        m_axil_wdata  = '0; m_axil_wvalid  = 1'b0;
        m_axil_rready = 1'b0; m_axil_bready = 1'b0;

        p0_arready = 1'b0; p0_rvalid = 1'b0; p0_rdata = '0;
        p1_arready = 1'b0; p1_rvalid = 1'b0; p1_rdata = '0;
        p1_awready = 1'b0; p1_wready = 1'b0; p1_bvalid = 1'b0;
        p2_arready = 1'b0; p2_rvalid = 1'b0; p2_rdata = '0;
        p2_awready = 1'b0; p2_wready = 1'b0; p2_bvalid = 1'b0;

        case (cur_gnt)
            GNT_P0: begin
                m_axil_araddr  = p0_araddr;
                m_axil_arvalid = p0_arvalid;
                p0_arready     = m_axil_arready;
                p0_rdata       = m_axil_rdata;
                p0_rvalid      = m_axil_rvalid;
                m_axil_rready  = p0_rready;
            end
            GNT_P1: begin
                m_axil_araddr  = p1_araddr;  m_axil_arvalid = p1_arvalid; p1_arready = m_axil_arready;
                p1_rdata       = m_axil_rdata; p1_rvalid    = m_axil_rvalid; m_axil_rready = p1_rready;
                m_axil_awaddr  = p1_awaddr;  m_axil_awvalid = p1_awvalid; p1_awready = m_axil_awready;
                m_axil_wdata   = p1_wdata;   m_axil_wvalid  = p1_wvalid;  p1_wready  = m_axil_wready;
                p1_bvalid      = m_axil_bvalid; m_axil_bready = p1_bready;
            end
            GNT_P2: begin
                m_axil_araddr  = p2_araddr;  m_axil_arvalid = p2_arvalid; p2_arready = m_axil_arready;
                p2_rdata       = m_axil_rdata; p2_rvalid    = m_axil_rvalid; m_axil_rready = p2_rready;
                m_axil_awaddr  = p2_awaddr;  m_axil_awvalid = p2_awvalid; p2_awready = m_axil_awready;
                m_axil_wdata   = p2_wdata;   m_axil_wvalid  = p2_wvalid;  p2_wready  = m_axil_wready;
                p2_bvalid      = m_axil_bvalid; m_axil_bready = p2_bready;
            end
            default: ;
        endcase
    end

endmodule : axi4_arbiter
