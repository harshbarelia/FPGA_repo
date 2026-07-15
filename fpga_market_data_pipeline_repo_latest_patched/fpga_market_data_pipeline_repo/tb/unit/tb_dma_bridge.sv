// -----------------------------------------------------------------------------
// tb_dma_bridge.sv
// Directed self-checking unit testbench for dma_bridge.sv
// -----------------------------------------------------------------------------
`timescale 1ns/1ps

module tb_dma_bridge;
  localparam int BEAT_W=512;
  logic clk=0, rst_n=0;
  logic [BEAT_W-1:0] s_tdata, m_tdata; logic [BEAT_W/8-1:0] s_tkeep, m_tkeep; logic s_tvalid, s_tready, s_tlast, m_tvalid, m_tready, m_tlast;
  logic [$clog2(512):0] fifo_occ; logic fifo_ovf; logic [31:0] cnt_in, cnt_out, cnt_drops;

  dma_bridge #(.BEAT_W(BEAT_W), .FIFO_DEPTH(512)) dut(.clk(clk), .rst_n(rst_n), .s_axis_tdata(s_tdata), .s_axis_tkeep(s_tkeep), .s_axis_tvalid(s_tvalid), .s_axis_tready(s_tready), .s_axis_tlast(s_tlast), .m_axis_tdata(m_tdata), .m_axis_tkeep(m_tkeep), .m_axis_tvalid(m_tvalid), .m_axis_tready(m_tready), .m_axis_tlast(m_tlast), .fifo_occupancy(fifo_occ), .fifo_overflow(fifo_ovf), .cnt_beats_in(cnt_in), .cnt_beats_out(cnt_out), .cnt_overflow_drops(cnt_drops));
  always #5 clk=~clk;
  int pass=0, fail=0; task automatic check(string n, logic c); if(c) begin pass++; $display("[PASS] %s", n); end else begin fail++; $error("[FAIL] %s", n); end endtask

  initial begin
    m_tready=1; s_tvalid=0; s_tdata=0; s_tkeep=0; s_tlast=0; rst_n=0; repeat(3) @(posedge clk); rst_n=1; @(posedge clk);
    s_tdata = 512'hDEAD; s_tkeep = {64{1'b1}}; s_tlast=1; s_tvalid=1; @(posedge clk); s_tvalid=0; repeat(2) @(posedge clk);
    check("beat forwarded (cnt_in==1)", cnt_in == 32'd1);
    check("beat read out (cnt_out==1)", cnt_out == 32'd1);
    check("no overflow in nominal case", !fifo_ovf);

    m_tready = 0;
    for (int i=0;i<520;i++) begin
      s_tdata = 512'(i); s_tkeep = {64{1'b1}}; s_tlast=1; s_tvalid=1; @(posedge clk);
    end
    s_tvalid=0;
    check("fifo overflow flagged when full and host stalled", fifo_ovf);
    check("overflow drop counter incremented", cnt_drops > 32'd0);
    m_tready = 1; repeat(600) @(posedge clk);

    $display("SUMMARY pass=%0d fail=%0d", pass, fail); $finish;
  end
endmodule
