
// axi_lite_csr.sv
// AXI4-Lite CSR block exposed via BAR0.
// ring_base_addr is 32-bit (AXI_ADDR_W=32), single RING_BASE register.
import dma_pkg::*;

module axi_lite_csr #(
    parameter int ADDR_W = 12,
    parameter int DATA_W = 32
)(
    input  logic                  clk,
    input  logic                  rst_n,
    input  logic [ADDR_W-1:0]     s_axil_awaddr,
    input  logic                  s_axil_awvalid,
    output logic                  s_axil_awready,
    input  logic [DATA_W-1:0]     s_axil_wdata,
    input  logic [3:0]            s_axil_wstrb,
    input  logic                  s_axil_wvalid,
    output logic                  s_axil_wready,
    output logic [1:0]            s_axil_bresp,
    output logic                  s_axil_bvalid,
    input  logic                  s_axil_bready,
    input  logic [ADDR_W-1:0]     s_axil_araddr,
    input  logic                  s_axil_arvalid,
    output logic                  s_axil_arready,
    output logic [DATA_W-1:0]     s_axil_rdata,
    output logic [1:0]            s_axil_rresp,
    output logic                  s_axil_rvalid,
    input  logic                  s_axil_rready,

    output logic                  dma_enable,
    output logic [31:0]           ring_base_addr,
    output logic [RING_IDX_W-1:0] ring_size,
    output logic [RING_PTR_W-1:0] tail_ptr,
    input  logic [RING_PTR_W-1:0] head_ptr,
    output logic                  irq_enable,
    input  logic                  dma_done,
    input  logic                  dma_error,
    input  logic [31:0]           desc_completed_cnt
);

    localparam logic [ADDR_W-1:0] ADDR_CTRL         = 12'h000;
    localparam logic [ADDR_W-1:0] ADDR_RING_BASE    = 12'h004; // single 32-bit ring base register
    localparam logic [ADDR_W-1:0] ADDR_RING_SIZE    = 12'h00C;
    localparam logic [ADDR_W-1:0] ADDR_TAIL_PTR     = 12'h010;
    localparam logic [ADDR_W-1:0] ADDR_HEAD_PTR     = 12'h014;
    localparam logic [ADDR_W-1:0] ADDR_IRQ_EN       = 12'h018;
    localparam logic [ADDR_W-1:0] ADDR_STATUS       = 12'h01C;
    localparam logic [ADDR_W-1:0] ADDR_DESC_CNT     = 12'h020;

    logic [31:0] ctrl_reg, ring_base_reg, ring_size_reg, tail_reg, irq_en_reg;
    logic aw_hs, w_hs;
    assign s_axil_awready = ~s_axil_bvalid;
    assign s_axil_wready  = ~s_axil_bvalid;
    assign aw_hs = s_axil_awvalid & s_axil_awready;
    assign w_hs  = s_axil_wvalid  & s_axil_wready;

    always_ff @(posedge clk or negedge rst_n) begin
        if (!rst_n) begin
            ctrl_reg <= '0; ring_base_reg <= '0;
            ring_size_reg <= '0; tail_reg <= '0; irq_en_reg <= '0;
            s_axil_bvalid <= 1'b0; s_axil_bresp <= 2'b00;
        end else begin
            if (aw_hs && w_hs) begin
                s_axil_bvalid <= 1'b1; s_axil_bresp <= 2'b00;
                case (s_axil_awaddr)
                    ADDR_CTRL      : ctrl_reg      <= s_axil_wdata;
                    ADDR_RING_BASE : ring_base_reg <= s_axil_wdata;
                    ADDR_RING_SIZE : ring_size_reg <= s_axil_wdata;
                    ADDR_TAIL_PTR  : tail_reg      <= s_axil_wdata;
                    ADDR_IRQ_EN    : irq_en_reg    <= s_axil_wdata;
                    default: ;
                endcase
            end else if (s_axil_bvalid && s_axil_bready) begin
                s_axil_bvalid <= 1'b0;
            end
        end
    end

    assign s_axil_arready = ~s_axil_rvalid;
    always_ff @(posedge clk or negedge rst_n) begin
        if (!rst_n) begin
            s_axil_rvalid <= 1'b0; s_axil_rdata <= '0; s_axil_rresp <= 2'b00;
        end else begin
            if (s_axil_arvalid && s_axil_arready) begin
                s_axil_rvalid <= 1'b1;
                case (s_axil_araddr)
                    ADDR_CTRL      : s_axil_rdata <= ctrl_reg;
                    ADDR_RING_BASE : s_axil_rdata <= ring_base_reg;
                    ADDR_RING_SIZE : s_axil_rdata <= ring_size_reg;
                    ADDR_TAIL_PTR  : s_axil_rdata <= tail_reg;
                    ADDR_HEAD_PTR  : s_axil_rdata <= {{(32-RING_PTR_W){1'b0}}, head_ptr};
                    ADDR_IRQ_EN    : s_axil_rdata <= irq_en_reg;
                    ADDR_STATUS    : s_axil_rdata <= {30'd0, dma_error, dma_done};
                    ADDR_DESC_CNT  : s_axil_rdata <= desc_completed_cnt;
                    default        : s_axil_rdata <= 32'hDEAD_BEEF;
                endcase
            end else if (s_axil_rvalid && s_axil_rready) begin
                s_axil_rvalid <= 1'b0;
            end
        end
    end

    assign dma_enable     = ctrl_reg[0];
    assign ring_base_addr = ring_base_reg;
    assign ring_size      = ring_size_reg[RING_IDX_W-1:0];
    assign tail_ptr       = tail_reg[RING_PTR_W-1:0];
    assign irq_enable      = irq_en_reg[0];

endmodule : axi_lite_csr
