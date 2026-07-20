
// desc_fetch_engine.sv
// RING BUFFER descriptor fetch engine over AXI4-LITE master port
// (no bursts available). A 16B descriptor is fetched as FOUR
// sequential 32-bit single-beat AXI4-Lite reads: src_addr, dst_addr,
// length, control - each one full read handshake (ARADDR/ARVALID/
// ARREADY then RDATA/RVALID/RREADY) before the next begins.
import dma_pkg::*;

module desc_fetch_engine (
    input  logic          clk,
    input  logic          rst_n,

    input  logic          dma_enable,
    input  logic [31:0]   ring_base_addr,
    input  logic [RING_IDX_W-1:0] ring_size,
    input  logic [RING_PTR_W-1:0] tail_ptr,
    output logic [RING_PTR_W-1:0] head_ptr,

    output logic          busy,
    output logic          desc_valid,
    output dma_desc_t     desc_out,
    input  logic          desc_consumed,

    // AXI4-Lite master read channel (single outstanding transaction)
    output logic [31:0]   m_axil_araddr,
    output logic          m_axil_arvalid,
    input  logic          m_axil_arready,
    input  logic [31:0]   m_axil_rdata,
    input  logic          m_axil_rvalid,
    output logic          m_axil_rready
);

    typedef enum logic [3:0] {F_IDLE, F_AR_SRC, F_R_SRC, F_AR_DST, F_R_DST,
                               F_AR_LEN, F_R_LEN, F_AR_CTRL, F_R_CTRL, F_WAIT_CONSUME} fstate_t;
    fstate_t state;

    logic [31:0] slot_base;
    logic [31:0] fld_src, fld_dst, fld_len, fld_ctrl;
    logic        ring_has_work;

    assign ring_has_work = ring_not_empty(head_ptr, tail_ptr);
    assign busy          = (state != F_IDLE);
    assign slot_base      = ring_slot_addr(ring_base_addr, head_ptr);

    always_ff @(posedge clk or negedge rst_n) begin
        if (!rst_n) begin
            state          <= F_IDLE;
            head_ptr       <= '0;
            m_axil_arvalid <= 1'b0;
            m_axil_rready  <= 1'b0;
            desc_valid     <= 1'b0;
            fld_src <= '0; fld_dst <= '0; fld_len <= '0; fld_ctrl <= '0;
        end else begin
            case (state)
                F_IDLE: begin
                    desc_valid <= 1'b0;
                    if (dma_enable && ring_has_work) begin
                        m_axil_araddr  <= slot_base; // offset 0: src_addr
                        m_axil_arvalid <= 1'b1;
                        state          <= F_AR_SRC;
                    end
                end
                F_AR_SRC: if (m_axil_arvalid && m_axil_arready) begin
                    m_axil_arvalid <= 1'b0; m_axil_rready <= 1'b1; state <= F_R_SRC;
                end
                F_R_SRC: if (m_axil_rvalid && m_axil_rready) begin
                    fld_src <= m_axil_rdata; m_axil_rready <= 1'b0;
                    m_axil_araddr <= slot_base + 4; m_axil_arvalid <= 1'b1; state <= F_AR_DST;
                end
                F_AR_DST: if (m_axil_arvalid && m_axil_arready) begin
                    m_axil_arvalid <= 1'b0; m_axil_rready <= 1'b1; state <= F_R_DST;
                end
                F_R_DST: if (m_axil_rvalid && m_axil_rready) begin
                    fld_dst <= m_axil_rdata; m_axil_rready <= 1'b0;
                    m_axil_araddr <= slot_base + 8; m_axil_arvalid <= 1'b1; state <= F_AR_LEN;
                end
                F_AR_LEN: if (m_axil_arvalid && m_axil_arready) begin
                    m_axil_arvalid <= 1'b0; m_axil_rready <= 1'b1; state <= F_R_LEN;
                end
                F_R_LEN: if (m_axil_rvalid && m_axil_rready) begin
                    fld_len <= m_axil_rdata; m_axil_rready <= 1'b0;
                    m_axil_araddr <= slot_base + 12; m_axil_arvalid <= 1'b1; state <= F_AR_CTRL;
                end
                F_AR_CTRL: if (m_axil_arvalid && m_axil_arready) begin
                    m_axil_arvalid <= 1'b0; m_axil_rready <= 1'b1; state <= F_R_CTRL;
                end
                F_R_CTRL: if (m_axil_rvalid && m_axil_rready) begin
                    fld_ctrl <= m_axil_rdata; m_axil_rready <= 1'b0;
                    desc_valid <= 1'b1; state <= F_WAIT_CONSUME;
                end
                F_WAIT_CONSUME: if (desc_consumed) begin
                    desc_valid <= 1'b0;
                    head_ptr   <= head_ptr + 1'b1;
                    state      <= F_IDLE;
                end
                default: state <= F_IDLE;
            endcase
        end
    end

    assign desc_out.src_addr = fld_src;
    assign desc_out.dst_addr = fld_dst;
    assign desc_out.length   = fld_len;
    assign desc_out.control  = fld_ctrl;

endmodule : desc_fetch_engine
