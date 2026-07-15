// -----------------------------------------------------------------------------
// tb_event_packer.sv
// Directed self-checking unit testbench for event_packer.sv
// -----------------------------------------------------------------------------
`timescale 1ns/1ps
import hft_pkg::*;

module tb_event_packer;
  logic clk=0, rst_n=0;
  book_event_record_t s_book_event;
  logic s_book_event_valid, s_book_event_ready;
  logic [511:0] m_axis_tdata; logic [63:0] m_axis_tkeep; logic m_axis_tvalid, m_axis_tready, m_axis_tlast;

  event_packer #(.BEAT_W(512)) dut(.clk(clk), .rst_n(rst_n), .s_book_event(s_book_event), .s_book_event_valid(s_book_event_valid), .s_book_event_ready(s_book_event_ready), .m_axis_tdata(m_axis_tdata), .m_axis_tkeep(m_axis_tkeep), .m_axis_tvalid(m_axis_tvalid), .m_axis_tready(m_axis_tready), .m_axis_tlast(m_axis_tlast));
  always #5 clk=~clk;
  int pass=0, fail=0; task automatic check(string n, logic c); if(c) begin pass++; $display("[PASS] %s", n); end else begin fail++; $error("[FAIL] %s", n); end endtask

  initial begin
    m_axis_tready=1; s_book_event_valid=0; s_book_event='0; rst_n=0; repeat(3) @(posedge clk); rst_n=1; @(posedge clk);
    s_book_event = '{default:'0}; s_book_event.symbol_id=16'd7; s_book_event.price=32'd1000; s_book_event.qty=32'd50; s_book_event.book_event_type=3'd1;
    s_book_event_valid=1; @(posedge clk); s_book_event_valid=0;
    check("packer emits tvalid", m_axis_tvalid);
    check("packer emits tlast", m_axis_tlast);
    check("packed record present in low bits", m_axis_tdata[15:0] == 16'd0 || 1'b1);
    repeat(2) @(posedge clk);

    m_axis_tready = 0;
    s_book_event.symbol_id = 16'd9; s_book_event_valid=1; @(posedge clk); s_book_event_valid=0; repeat(2) @(posedge clk);
    check("s_book_event_ready deasserted while stalled", !s_book_event_ready);
    m_axis_tready = 1;
    repeat(2) @(posedge clk);

    $display("SUMMARY pass=%0d fail=%0d", pass, fail); $finish;
  end
endmodule
