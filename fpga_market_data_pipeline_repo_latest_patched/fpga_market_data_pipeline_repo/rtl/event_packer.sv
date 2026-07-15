// -----------------------------------------------------------------------------
// event_packer.sv
// Packs hft_pkg::book_event_record_t into a fixed-width single-beat
// AXI4-Stream transfer toward dma_bridge.sv.
// -----------------------------------------------------------------------------

import hft_pkg::*;

module event_packer #(
    parameter int BEAT_W = 384
)(
    input  logic                   clk,
    input  logic                   rst_n,
    input  book_event_record_t     s_book_event,
    input  logic                   s_book_event_valid,
    output logic                   s_book_event_ready,
    output logic [BEAT_W-1:0]      m_axis_tdata,
    output logic [BEAT_W/8-1:0]    m_axis_tkeep,
    output logic                   m_axis_tvalid,
    input  logic                   m_axis_tready,
    output logic                   m_axis_tlast
);

  localparam int REC_W = $bits(book_event_record_t);
  logic pipe_stall;
  assign pipe_stall          = m_axis_tvalid && !m_axis_tready;
  assign s_book_event_ready  = !pipe_stall;

  logic [63:0] ts_local_ctr;
  always_ff @(posedge clk or negedge rst_n) begin
    if (!rst_n) ts_local_ctr <= '0;
    else        ts_local_ctr <= ts_local_ctr + 1'b1;
  end

  always_ff @(posedge clk or negedge rst_n) begin
    if (!rst_n) begin
      m_axis_tvalid <= 1'b0;
      m_axis_tdata  <= '0;
      m_axis_tkeep  <= '0;
      m_axis_tlast  <= 1'b0;
    end else if (!pipe_stall) begin
      m_axis_tvalid <= s_book_event_valid;
      m_axis_tlast  <= s_book_event_valid;
      m_axis_tkeep  <= {(BEAT_W/8){1'b1}};
      if (s_book_event_valid) begin
        m_axis_tdata <= '0;
        m_axis_tdata[REC_W-1:0] <= s_book_event;
        m_axis_tdata[BEAT_W-1:BEAT_W-64] <= ts_local_ctr;
      end
    end
  end

  a_no_accept_when_stalled: assert property (
    @(posedge clk) disable iff (!rst_n)
    pipe_stall |-> !s_book_event_ready)
  else $error("event_packer accepted input while output stalled");

  a_tlast_every_beat: assert property (
    @(posedge clk) disable iff (!rst_n)
    m_axis_tvalid |-> m_axis_tlast)
  else $error("event_packer: tlast not asserted on single-beat transfer");

endmodule : event_packer
