// -----------------------------------------------------------------------------
// tb_order_book.sv
// Directed self-checking unit testbench for order_book_core.sv
// -----------------------------------------------------------------------------
`timescale 1ns/1ps
import hft_pkg::*;

module tb_order_book;
  logic clk = 0;
  logic rst_n = 0;
  norm_event_t s_event;
  logic s_event_valid;
  logic s_event_ready;
  book_event_record_t m_book_event;
  logic m_book_event_valid;
  logic m_book_event_ready;
  logic [31:0] cnt_duplicate_add, cnt_missing_order, cnt_agg_underflow, cnt_book_updates;

  order_book_core dut (
    .clk(clk), .rst_n(rst_n),
    .s_event(s_event), .s_event_valid(s_event_valid), .s_event_ready(s_event_ready),
    .m_book_event(m_book_event), .m_book_event_valid(m_book_event_valid), .m_book_event_ready(m_book_event_ready),
    .cnt_duplicate_add(cnt_duplicate_add), .cnt_missing_order(cnt_missing_order), .cnt_agg_underflow(cnt_agg_underflow), .cnt_book_updates(cnt_book_updates)
  );

  always #5 clk = ~clk;
  int pass_count = 0, fail_count = 0;
  task automatic check(string n, logic c); if (c) begin pass_count++; $display("[PASS] %s", n); end else begin fail_count++; $error("[FAIL] %s", n); end endtask

  task automatic drive(input ev_type_e t, input logic [15:0] sid, input logic side, input logic [31:0] price, input logic [31:0] qty, input logic [63:0] oid, input logic [63:0] oidn = 0);
    s_event = '{default:'0};
    s_event.ev_type = t; s_event.symbol_id = sid; s_event.side = side; s_event.price = price; s_event.qty = qty; s_event.order_id = oid; s_event.order_id_new = oidn;
    s_event_valid = 1;
    @(posedge clk);
    while (!s_event_ready) @(posedge clk);
    s_event_valid = 0;
    @(posedge clk);
  endtask

  initial begin
    m_book_event_ready = 1'b1; s_event_valid = 0; s_event = '0; rst_n = 0; repeat(3) @(posedge clk); rst_n = 1; @(posedge clk);
    drive(EV_ADD, 16'd1, 1'b0, 32'd100, 32'd50, 64'd11);
    check("ADD accepted", cnt_book_updates == 1);
    drive(EV_ADD, 16'd1, 1'b1, 32'd105, 32'd40, 64'd22);
    check("best ask present", m_book_event.best_ask == 32'd105);
    drive(EV_EXEC, 16'd1, 1'b0, 32'd0, 32'd20, 64'd11);
    check("exec applied", cnt_book_updates == 3);
    drive(EV_CANCEL, 16'd1, 1'b0, 32'd0, 32'd30, 64'd11);
    check("cancel removed order", cnt_book_updates == 4);
    drive(EV_REPLACE, 16'd1, 1'b1, 32'd103, 32'd35, 64'd22, 64'd33);
    check("replace applied", cnt_book_updates == 5);
    drive(EV_DELETE, 16'd1, 1'b1, 32'd0, 32'd0, 64'd33);
    check("delete applied", cnt_book_updates == 6);
    drive(EV_CANCEL, 16'd1, 1'b0, 32'd0, 32'd1, 64'd9999);
    check("missing order counted", cnt_missing_order == 1);
    $display("SUMMARY pass=%0d fail=%0d", pass_count, fail_count);
    $finish;
  end
endmodule
