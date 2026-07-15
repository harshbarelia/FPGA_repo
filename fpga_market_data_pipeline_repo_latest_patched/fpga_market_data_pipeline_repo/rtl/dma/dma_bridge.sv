// -----------------------------------------------------------------------------
// dma_bridge.sv
// Transport abstraction between the FPGA event stream and a host-facing
// DMA-style AXI4-Stream interface. Board/IP-agnostic in v1.
// -----------------------------------------------------------------------------

module dma_bridge #(
    parameter int BEAT_W    = 384,
    parameter int FIFO_DEPTH = 512,
    parameter int ADDR_W    = $clog2(FIFO_DEPTH)
)(
    input  logic                  clk,
    input  logic                  rst_n,

    input  logic [BEAT_W-1:0]     s_axis_tdata,
    input  logic [BEAT_W/8-1:0]   s_axis_tkeep,
    input  logic                  s_axis_tvalid,
    output logic                  s_axis_tready,
    input  logic                  s_axis_tlast,

    output logic [BEAT_W-1:0]     m_axis_tdata,
    output logic [BEAT_W/8-1:0]   m_axis_tkeep,
    output logic                  m_axis_tvalid,
    input  logic                  m_axis_tready,
    output logic                  m_axis_tlast,

    output logic [ADDR_W:0]       fifo_occupancy,
    output logic                  fifo_overflow,
    output logic [31:0]           cnt_beats_in,
    output logic [31:0]           cnt_beats_out,
    output logic [31:0]           cnt_overflow_drops
);

  typedef struct packed {
    logic [BEAT_W-1:0]   tdata;
    logic [BEAT_W/8-1:0] tkeep;
    logic                tlast;
  } fifo_word_t;

  fifo_word_t mem [FIFO_DEPTH];
  logic [ADDR_W-1:0] wr_ptr, rd_ptr;
  logic [ADDR_W:0]   occ;

  wire full  = (occ == FIFO_DEPTH);
  wire empty = (occ == 0);

  assign s_axis_tready = !full;
  assign fifo_occupancy = occ;

  fifo_word_t wr_word;
  assign wr_word.tdata = s_axis_tdata;
  assign wr_word.tkeep = s_axis_tkeep;
  assign wr_word.tlast = s_axis_tlast;

  logic push, pop;
  assign push = s_axis_tvalid && s_axis_tready;
  assign pop  = m_axis_tvalid && m_axis_tready;

  always_ff @(posedge clk or negedge rst_n) begin
    if (!rst_n) begin
      wr_ptr <= '0; rd_ptr <= '0; occ <= '0;
      fifo_overflow <= 1'b0;
      cnt_beats_in <= '0; cnt_beats_out <= '0; cnt_overflow_drops <= '0;
    end else begin
      if (push) begin
        mem[wr_ptr] <= wr_word;
        wr_ptr <= wr_ptr + 1'b1;
        cnt_beats_in <= cnt_beats_in + 1'b1;
      end else if (s_axis_tvalid && full) begin
        fifo_overflow <= 1'b1;
        cnt_overflow_drops <= cnt_overflow_drops + 1'b1;
      end

      if (pop) begin
        rd_ptr <= rd_ptr + 1'b1;
        cnt_beats_out <= cnt_beats_out + 1'b1;
      end

      case ({push, pop})
        2'b10: occ <= occ + 1'b1;
        2'b01: occ <= occ - 1'b1;
        default: occ <= occ;
      endcase
    end
  end

  assign m_axis_tvalid = !empty;
  assign m_axis_tdata   = mem[rd_ptr].tdata;
  assign m_axis_tkeep   = mem[rd_ptr].tkeep;
  assign m_axis_tlast   = mem[rd_ptr].tlast;

  a_no_overflow_without_flag: assert property (
    @(posedge clk) disable iff (!rst_n)
    (s_axis_tvalid && full) |-> fifo_overflow)
  else $error("dma_bridge: FIFO full condition not flagged");

  a_occupancy_bounds: assert property (
    @(posedge clk) disable iff (!rst_n)
    occ <= FIFO_DEPTH)
  else $error("dma_bridge: occupancy exceeded FIFO_DEPTH");

endmodule : dma_bridge
