`timescale 1ns/1ps
import hft_pkg::*;
module tb_int_pipeline;
  localparam int MSG_BYTES=64; localparam int MSG_W=MSG_BYTES*8; localparam int BEAT_W=512;
  `include "tb/vectors/itch_vectors.svh"
  `include "tb/vectors/itch_vectors_seq.svh"
  logic clk=0, rst_n=0; always #5 clk=~clk;
  logic [7:0] rx_byte; logic rx_valid, rx_sof, rx_eof, rx_ready;
  logic [MSG_W-1:0] p_msg_data, f_msg_data; logic [15:0] p_msg_len, f_msg_len; logic p_msg_valid, p_msg_ready, f_msg_valid, f_msg_ready;
  logic err_invalid_eth, err_invalid_ip, err_invalid_udp, err_oversize;
  eth_ipv4_udp_parser u_parser(.clk(clk),.rst_n(rst_n),.s_rx_byte(rx_byte),.s_rx_valid(rx_valid),.s_rx_sof(rx_sof),.s_rx_eof(rx_eof),.s_rx_ready(rx_ready),.m_msg_data(p_msg_data),.m_msg_len(p_msg_len),.m_msg_valid(p_msg_valid),.m_msg_ready(p_msg_ready),.err_invalid_eth(err_invalid_eth),.err_invalid_ip(err_invalid_ip),.err_invalid_udp(err_invalid_udp),.err_oversize(err_oversize));
  udp_payload_framer u_framer(.clk(clk),.rst_n(rst_n),.s_msg_data(p_msg_data),.s_msg_len(p_msg_len),.s_msg_valid(p_msg_valid),.s_msg_ready(p_msg_ready),.m_msg_data(f_msg_data),.m_msg_len(f_msg_len),.m_msg_valid(f_msg_valid),.m_msg_ready(f_msg_ready));
  logic sym_lookup_req; logic [15:0] sym_lookup_stock_locate; logic [63:0] sym_lookup_stock8; logic sym_lookup_hit; logic [15:0] sym_lookup_symbol_id;
  logic sym_wr_en; logic [15:0] sym_wr_stock_locate; logic [63:0] sym_wr_stock8; logic [15:0] sym_wr_assigned_id;
  norm_event_t dec_event; dec_meta_t dec_meta; logic dec_event_valid, dec_event_ready;
  market_message_decoder #(.MSG_BYTES(MSG_BYTES)) u_decoder(.clk(clk),.rst_n(rst_n),.s_msg_data(f_msg_data),.s_msg_len(f_msg_len),.s_msg_valid(f_msg_valid),.s_msg_ready(f_msg_ready),.sym_lookup_req(sym_lookup_req),.sym_lookup_stock_locate(sym_lookup_stock_locate),.sym_lookup_stock8(sym_lookup_stock8),.sym_lookup_hit(sym_lookup_hit),.sym_lookup_symbol_id(sym_lookup_symbol_id),.sym_wr_en(sym_wr_en),.sym_wr_stock_locate(sym_wr_stock_locate),.sym_wr_stock8(sym_wr_stock8),.m_event(dec_event),.m_meta(dec_meta),.m_event_valid(dec_event_valid),.m_event_ready(dec_event_ready));
  symbol_table #(.NUM_SYMBOLS(1024)) u_symtab(.clk(clk),.rst_n(rst_n),.wr_en(sym_wr_en),.wr_stock_locate(sym_wr_stock_locate),.wr_stock8(sym_wr_stock8),.wr_assigned_symbol_id(sym_wr_assigned_id),.rd_req(sym_lookup_req),.rd_stock_locate(sym_lookup_stock_locate),.rd_hit(sym_lookup_hit),.rd_symbol_id(sym_lookup_symbol_id));
  book_event_record_t book_event; logic book_event_valid, book_event_ready; logic [31:0] cnt_dup,cnt_miss,cnt_underflow,cnt_updates; logic [31:0] cnt_ord_full, cnt_lvl_full, cnt_track_exh;
  order_book_core u_book(.clk(clk),.rst_n(rst_n),.s_event(dec_event),.s_event_valid(dec_event_valid),.s_event_ready(dec_event_ready),.m_book_event(book_event),.m_book_event_valid(book_event_valid),.m_book_event_ready(book_event_ready),.cnt_duplicate_add(cnt_dup),.cnt_missing_order(cnt_miss),.cnt_agg_underflow(cnt_underflow),.cnt_book_updates(cnt_updates),.cnt_ord_set_full(cnt_ord_full),.cnt_lvl_set_full(cnt_lvl_full),.cnt_track_exhausted(cnt_track_exh));
  logic [BEAT_W-1:0] pk_tdata, dma_tdata; logic [BEAT_W/8-1:0] pk_tkeep, dma_tkeep; logic pk_tvalid, pk_tready, pk_tlast, dma_tvalid, dma_tready, dma_tlast; logic [$clog2(512):0] fifo_occ; logic fifo_ovf; logic [31:0] cnt_in,cnt_out,cnt_drops;
  event_packer #(.BEAT_W(BEAT_W)) u_packer(.clk(clk),.rst_n(rst_n),.s_book_event(book_event),.s_book_event_valid(book_event_valid),.s_book_event_ready(book_event_ready),.m_axis_tdata(pk_tdata),.m_axis_tkeep(pk_tkeep),.m_axis_tvalid(pk_tvalid),.m_axis_tready(pk_tready),.m_axis_tlast(pk_tlast));
  dma_bridge #(.BEAT_W(BEAT_W),.FIFO_DEPTH(512)) u_dma(.clk(clk),.rst_n(rst_n),.s_axis_tdata(pk_tdata),.s_axis_tkeep(pk_tkeep),.s_axis_tvalid(pk_tvalid),.s_axis_tready(pk_tready),.s_axis_tlast(pk_tlast),.m_axis_tdata(dma_tdata),.m_axis_tkeep(dma_tkeep),.m_axis_tvalid(dma_tvalid),.m_axis_tready(dma_tready),.m_axis_tlast(dma_tlast),.fifo_occupancy(fifo_occ),.fifo_overflow(fifo_ovf),.cnt_beats_in(cnt_in),.cnt_beats_out(cnt_out),.cnt_overflow_drops(cnt_drops));
  assign dma_tready = 1'b1;
  int pass=0, fail=0; task automatic check(string n, logic c); if(c) begin pass++; $display("[PASS] %s", n); end else begin fail++; $error("[FAIL] %s", n); end endtask
  task automatic send_frame(input logic [7:0] bytes[$], input int n); begin for (int i=0;i<n;i++) begin rx_byte=bytes[i]; rx_valid=1; rx_sof=(i==0); rx_eof=(i==n-1); @(posedge clk); end rx_valid=0; rx_sof=0; rx_eof=0; @(posedge clk); end endtask
  logic [7:0] frame_r [$];
  initial begin
    rx_valid=0; rx_sof=0; rx_eof=0; rx_byte=0; rst_n=0; repeat(3) @(posedge clk); rst_n=1; @(posedge clk);
    // 81-byte frame: 14 Eth + 20 IP + 8 UDP + 39-byte ITCH Stock Directory (R)
    // IP total len = 67 (0x43), UDP len = 47 (0x2F)
    frame_r = '{8'h00,8'h11,8'h22,8'h33,8'h44,8'h55,8'h66,8'h77,8'h88,8'h99,8'hAA,8'hBB,8'h08,8'h00,8'h45,8'h00,8'h00,8'h43,8'h00,8'h01,8'h00,8'h00,8'h40,8'h11,8'h66,8'hA7,8'h0A,8'h00,8'h00,8'h01,8'h0A,8'h00,8'h00,8'h02,8'h1F,8'h90,8'h1F,8'h90,8'h00,8'h2F,8'h00,8'h00,8'h52,8'h00,8'h01,8'h00,8'h00,8'h00,8'h00,8'h07,8'h5B,8'hCC,8'hBC,8'h41,8'h41,8'h50,8'h4C,8'h20,8'h20,8'h20,8'h20,8'h51,8'h20,8'h00,8'h00,8'h00,8'h64,8'h00,8'h00,8'h00,8'h00,8'h00,8'h00,8'h00,8'h00,8'h00,8'h00,8'h00,8'h00,8'h00,8'h00};
    send_frame(frame_r, 81);
    repeat(10) @(posedge clk);
    check("directory write assigned nonzero id", sym_wr_assigned_id != 16'd0);
    check("parser no eth error", !err_invalid_eth);
    $display("SUMMARY pass=%0d fail=%0d", pass, fail); $finish;
  end
endmodule
