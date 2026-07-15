// -----------------------------------------------------------------------------
// tb_decoder.sv
// Self-checking unit testbench for market_message_decoder.sv.
// -----------------------------------------------------------------------------

`timescale 1ns/1ps
import hft_pkg::*;

module tb_decoder;

  localparam int MSG_BYTES = 64;
  localparam int MSG_W     = MSG_BYTES * 8;

  `include "itch_vectors.svh"

  logic clk = 0;
  logic rst_n = 0;

  logic [MSG_W-1:0] s_msg_data;
  logic [15:0]      s_msg_len;
  logic             s_msg_valid;
  logic             s_msg_ready;

  logic             sym_lookup_req;
  logic [15:0]      sym_lookup_stock_locate;
  logic [63:0]      sym_lookup_stock8;
  logic             sym_lookup_hit;
  logic [15:0]      sym_lookup_symbol_id;

  logic             sym_wr_en;
  logic [15:0]      sym_wr_stock_locate;
  logic [63:0]      sym_wr_stock8;

  norm_event_t      m_event;
  dec_meta_t        m_meta;
  logic             m_event_valid;
  logic             m_event_ready;

  logic force_symbol_miss = 1'b0;
  always_comb begin
    sym_lookup_hit       = sym_lookup_req & ~force_symbol_miss;
    sym_lookup_symbol_id = force_symbol_miss ? 16'd0 : 16'd42;
  end

  market_message_decoder #(
    .MSG_BYTES (MSG_BYTES)
  ) dut (
    .clk                     (clk),
    .rst_n                   (rst_n),
    .s_msg_data              (s_msg_data),
    .s_msg_len               (s_msg_len),
    .s_msg_valid             (s_msg_valid),
    .s_msg_ready             (s_msg_ready),
    .sym_lookup_req          (sym_lookup_req),
    .sym_lookup_stock_locate (sym_lookup_stock_locate),
    .sym_lookup_stock8       (sym_lookup_stock8),
    .sym_lookup_hit          (sym_lookup_hit),
    .sym_lookup_symbol_id    (sym_lookup_symbol_id),
    .sym_wr_en               (sym_wr_en),
    .sym_wr_stock_locate     (sym_wr_stock_locate),
    .sym_wr_stock8           (sym_wr_stock8),
    .m_event                 (m_event),
    .m_meta                  (m_meta),
    .m_event_valid           (m_event_valid),
    .m_event_ready           (m_event_ready)
  );

  always #5 clk = ~clk;

  int pass_count = 0;
  int fail_count = 0;

  task automatic check(string name, logic cond);
    if (cond) begin pass_count++; $display("[PASS] %s", name); end
    else begin fail_count++; $error("[FAIL] %s", name); end
  endtask

  task automatic drive_msg(logic [MSG_W-1:0] data, int len);
    s_msg_data  = data << (8 * (MSG_BYTES - len));
    s_msg_len   = len;
    s_msg_valid = 1'b1;
    @(posedge clk);
    while (!s_msg_ready) @(posedge clk);
    s_msg_valid = 1'b0;
  endtask

  task automatic wait_output();
    int guard;
    guard = 0;
    while (!m_event_valid && guard < 20) begin @(posedge clk); guard++; end
    check("output produced within guard window", m_event_valid);
  endtask

  initial begin
    s_msg_data    = '0;
    s_msg_len     = '0;
    s_msg_valid   = 1'b0;
    m_event_ready = 1'b1;
    rst_n         = 1'b0;
    repeat (3) @(posedge clk);
    rst_n = 1'b1;
    @(posedge clk);

    force_symbol_miss = 1'b0;
    drive_msg(MSG_A_VALID, MSG_A_VALID_LEN);
    wait_output();
    check("T1 ev_type == EV_ADD",        m_event.ev_type   == EV_ADD);
    check("T1 status  == DEC_OK",         m_meta.status     == DEC_OK);
    check("T1 order_id == 1001",           m_event.order_id  == 64'd1001);
    check("T1 side == 0 (Buy)",            m_event.side      == 1'b0);
    check("T1 qty == 100",                 m_event.qty       == 32'd100);
    check("T1 price == 1500000",           m_event.price     == 32'd1500000);
    check("T1 symbol_id == 42 (resolved)", m_event.symbol_id == 16'd42);
    @(posedge clk);

    drive_msg(MSG_D_VALID, MSG_D_VALID_LEN);
    wait_output();
    check("T2 ev_type == EV_DELETE", m_event.ev_type == EV_DELETE);
    check("T2 order_id == 1001",       m_event.order_id == 64'd1001);
    @(posedge clk);

    drive_msg({{6*8{1'b0}}, MSG_A_BAD_LENGTH}, MSG_A_BAD_LENGTH_LEN);
    wait_output();
    check("T3 status == DEC_TRUNCATED", m_meta.status == DEC_TRUNCATED);
    check("T3 malformed == 1",           m_meta.malformed == 1'b1);
    @(posedge clk);

    drive_msg({{59*8{1'b0}}, MSG_UNSUPPORTED}, MSG_UNSUPPORTED_LEN);
    wait_output();
    check("T4 status == DEC_UNSUPPORTED", m_meta.status == DEC_UNSUPPORTED);
    @(posedge clk);

    force_symbol_miss = 1'b1;
    drive_msg(MSG_A_VALID, MSG_A_VALID_LEN);
    wait_output();
    check("T5 status == DEC_SYMBOL_UNKNOWN", m_meta.status == DEC_SYMBOL_UNKNOWN);
    check("T5 symbol_id == 0",                m_event.symbol_id == 16'd0);
    force_symbol_miss = 1'b0;
    @(posedge clk);

    m_event_ready = 1'b0;
    drive_msg(MSG_D_VALID, MSG_D_VALID_LEN);
    repeat (3) @(posedge clk);
    check("T6 s_msg_ready deasserted while stalled", !s_msg_ready);
    m_event_ready = 1'b1;
    wait_output();
    @(posedge clk);

    $display("SUMMARY pass=%0d fail=%0d", pass_count, fail_count);
    $finish;
  end

endmodule : tb_decoder
