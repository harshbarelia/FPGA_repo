
// c2h_engine.sv
// Card-to-Host DMA engine over AXI4-LITE (no bursts, one beat at a
// time). Same single-beat read-then-write loop as h2c_engine; for
// C2H the descriptor's src_addr is local BRAM and dst_addr is host
// DDR, but the engine logic itself is identical.
import dma_pkg::*;

module c2h_engine (
    input  logic          clk,
    input  logic          rst_n,
    input  logic          desc_valid,
    input  dma_desc_t     desc_in,
    output logic          desc_ack,
    output logic          xfer_done,

    output logic [31:0]   m_axil_araddr,
    output logic          m_axil_arvalid,
    input  logic          m_axil_arready,
    input  logic [31:0]   m_axil_rdata,
    input  logic          m_axil_rvalid,
    output logic          m_axil_rready,

    output logic [31:0]   m_axil_awaddr,
    output logic          m_axil_awvalid,
    input  logic          m_axil_awready,
    output logic [31:0]   m_axil_wdata,
    output logic          m_axil_wvalid,
    input  logic          m_axil_wready,
    input  logic          m_axil_bvalid,
    output logic          m_axil_bready
);

    typedef enum logic [2:0] {S_IDLE, S_AR, S_R, S_AW, S_B, S_DONE} state_t;
    state_t state;

    logic [31:0] bytes_remaining;
    logic [31:0] rd_addr, wr_addr;

    assign desc_ack  = (state == S_DONE);
    assign xfer_done = (state == S_DONE);

    always_ff @(posedge clk or negedge rst_n) begin
        if (!rst_n) begin
            state <= S_IDLE; bytes_remaining <= '0; rd_addr <= '0; wr_addr <= '0;
            m_axil_arvalid <= 1'b0; m_axil_rready <= 1'b0;
            m_axil_awvalid <= 1'b0; m_axil_wvalid <= 1'b0; m_axil_bready <= 1'b0;
        end else begin
            case (state)
                S_IDLE: begin
                    if (desc_valid) begin
                        rd_addr <= desc_in.src_addr;
                        wr_addr <= desc_in.dst_addr;
                        bytes_remaining <= desc_in.length;
                        if (desc_in.length == 0) begin
                            state <= S_DONE;
                        end else begin
                            m_axil_araddr  <= desc_in.src_addr;
                            m_axil_arvalid <= 1'b1;
                            state <= S_AR;
                        end
                    end
                end
                S_AR: if (m_axil_arvalid && m_axil_arready) begin
                    m_axil_arvalid <= 1'b0; m_axil_rready <= 1'b1; state <= S_R;
                end
                S_R: if (m_axil_rvalid && m_axil_rready) begin
                    m_axil_rready  <= 1'b0;
                    m_axil_awaddr  <= wr_addr;
                    m_axil_wdata   <= m_axil_rdata;
                    m_axil_awvalid <= 1'b1;
                    m_axil_wvalid  <= 1'b1;
                    state <= S_AW;
                end
                S_AW: begin
                    if (m_axil_awvalid && m_axil_awready) m_axil_awvalid <= 1'b0;
                    if (m_axil_wvalid  && m_axil_wready)  m_axil_wvalid  <= 1'b0;
                    if (!m_axil_awvalid && !m_axil_wvalid) begin
                        m_axil_bready <= 1'b1;
                        state <= S_B;
                    end
                end
                S_B: if (m_axil_bvalid && m_axil_bready) begin
                    m_axil_bready   <= 1'b0;
                    rd_addr         <= rd_addr + BEAT_BYTES;
                    wr_addr         <= wr_addr + BEAT_BYTES;
                    bytes_remaining <= (bytes_remaining > BEAT_BYTES) ? (bytes_remaining - BEAT_BYTES) : 32'd0;
                    if (bytes_remaining <= BEAT_BYTES) begin
                        state <= S_DONE;
                    end else begin
                        m_axil_araddr  <= rd_addr + BEAT_BYTES;
                        m_axil_arvalid <= 1'b1;
                        state <= S_AR;
                    end
                end
                S_DONE: state <= S_IDLE;
                default: state <= S_IDLE;
            endcase
        end
    end

endmodule : c2h_engine
