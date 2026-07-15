// -----------------------------------------------------------------------------
// order_book_core.sv
// -----------------------------------------------------------------------------
import hft_pkg::*;

module order_book_core #(
    parameter int NUM_ORDERS   = 2048,
    parameter int NUM_LEVELS   = 2048,
    parameter int NUM_SYMBOLS  = 1024,
    parameter int SYMBOL_ID_W  = 16,
    parameter int PRICE_W      = 32,
    parameter int QTY_W        = 32,
    parameter int ORDER_ID_W   = 64,
    parameter int FLAGS_W      = 16,
    parameter int ORD_ADDR_W   = $clog2(NUM_ORDERS),
    parameter int LVL_ADDR_W   = $clog2(NUM_LEVELS),
    parameter int SYM_ADDR_W   = $clog2(NUM_SYMBOLS)
)(
    input  logic                 clk,
    input  logic                 rst_n,
    input  norm_event_t          s_event,
    input  logic                 s_event_valid,
    output logic                 s_event_ready,
    output book_event_record_t   m_book_event,
    output logic                 m_book_event_valid,
    input  logic                 m_book_event_ready,
    output logic [31:0]          cnt_duplicate_add,
    output logic [31:0]          cnt_missing_order,
    output logic [31:0]          cnt_agg_underflow,
    output logic [31:0]          cnt_book_updates
);
  typedef struct packed { logic valid; logic [SYMBOL_ID_W-1:0] symbol_id; logic side; logic [PRICE_W-1:0] price; logic [QTY_W-1:0] qty_remaining; } order_entry_t;
  typedef struct packed { logic valid; logic [SYMBOL_ID_W-1:0] symbol_id; logic side; logic [PRICE_W-1:0] price; logic [QTY_W-1:0] agg_qty; } level_entry_t;
  order_entry_t order_mem [NUM_ORDERS];
  level_entry_t level_mem [NUM_LEVELS];
  logic best_bid_valid [NUM_SYMBOLS], best_ask_valid [NUM_SYMBOLS];
  logic [PRICE_W-1:0] best_bid_price [NUM_SYMBOLS], best_ask_price [NUM_SYMBOLS];
  logic [QTY_W-1:0] best_bid_qty [NUM_SYMBOLS], best_ask_qty [NUM_SYMBOLS];
  logic pipe_stall; assign pipe_stall = m_book_event_valid && !m_book_event_ready; assign s_event_ready = !pipe_stall;
  function automatic [ORD_ADDR_W-1:0] order_hash(input logic [ORDER_ID_W-1:0] order_id); order_hash = order_id[ORD_ADDR_W-1:0]; endfunction
  function automatic [LVL_ADDR_W-1:0] level_hash(input logic [SYMBOL_ID_W-1:0] symbol_id, input logic side, input logic [PRICE_W-1:0] price); level_hash = (symbol_id ^ { {(LVL_ADDR_W-1){1'b0}}, side } ^ price[LVL_ADDR_W-1:0]); endfunction
  function automatic void recompute_best_bid(input logic [SYM_ADDR_W-1:0] sidx);
    logic [PRICE_W-1:0] best_p; logic [QTY_W-1:0] best_q; int j; best_p='0; best_q='0;
    for (j=0;j<NUM_LEVELS;j++) if (level_mem[j].valid && level_mem[j].symbol_id[SYM_ADDR_W-1:0]==sidx && !level_mem[j].side && level_mem[j].agg_qty>0) begin if (!best_bid_valid[sidx] || (level_mem[j].price > best_p)) begin best_p = level_mem[j].price; best_q = level_mem[j].agg_qty; end end
    if (best_q=='0) begin best_bid_valid[sidx] <= 1'b0; best_bid_price[sidx] <= '0; best_bid_qty[sidx] <= '0; end else begin best_bid_valid[sidx] <= 1'b1; best_bid_price[sidx] <= best_p; best_bid_qty[sidx] <= best_q; end
  endfunction
  function automatic void recompute_best_ask(input logic [SYM_ADDR_W-1:0] sidx);
    logic [PRICE_W-1:0] best_p; logic [QTY_W-1:0] best_q; int j; best_p='0; best_q='0;
    for (j=0;j<NUM_LEVELS;j++) if (level_mem[j].valid && level_mem[j].symbol_id[SYM_ADDR_W-1:0]==sidx && level_mem[j].side && level_mem[j].agg_qty>0) begin if (!best_ask_valid[sidx] || (best_p=='0) || (level_mem[j].price < best_p)) begin best_p = level_mem[j].price; best_q = level_mem[j].agg_qty; end end
    if (best_q=='0) begin best_ask_valid[sidx] <= 1'b0; best_ask_price[sidx] <= '0; best_ask_qty[sidx] <= '0; end else begin best_ask_valid[sidx] <= 1'b1; best_ask_price[sidx] <= best_p; best_ask_qty[sidx] <= best_q; end
  endfunction
  integer i; logic [ORD_ADDR_W-1:0] ord_idx; logic [LVL_ADDR_W-1:0] lvl_idx_old, lvl_idx_new; logic [SYM_ADDR_W-1:0] sym_idx; logic [QTY_W-1:0] delta_qty;
  always_ff @(posedge clk or negedge rst_n) begin
    if (!rst_n) begin
      m_book_event_valid <= 1'b0; cnt_duplicate_add <= '0; cnt_missing_order <= '0; cnt_agg_underflow <= '0; cnt_book_updates <= '0;
      for (i=0;i<NUM_ORDERS;i++) order_mem[i].valid = 1'b0;
      for (i=0;i<NUM_LEVELS;i++) level_mem[i].valid = 1'b0;
      for (i=0;i<NUM_SYMBOLS;i++) begin best_bid_valid[i] = 1'b0; best_bid_price[i] = '0; best_bid_qty[i] = '0; best_ask_valid[i] = 1'b0; best_ask_price[i] = '0; best_ask_qty[i] = '0; end
    end else if (!pipe_stall) begin
      m_book_event_valid <= 1'b0;
      if (s_event_valid) begin
        ord_idx = order_hash(s_event.order_id); sym_idx = s_event.symbol_id[SYM_ADDR_W-1:0]; delta_qty='0; m_book_event <= '{default:'0}; m_book_event.ts_exchange <= s_event.ts_exchange; m_book_event.symbol_id <= s_event.symbol_id; m_book_event.side <= s_event.side; m_book_event.price <= s_event.price; m_book_event.qty <= s_event.qty; m_book_event.flags <= s_event.flags;
        unique case (s_event.ev_type)
          EV_ADD: begin
            if (order_mem[ord_idx].valid) begin cnt_duplicate_add <= cnt_duplicate_add + 1'b1; m_book_event.flags[8] <= 1'b1; end else begin
              order_mem[ord_idx].valid <= 1'b1; order_mem[ord_idx].symbol_id <= s_event.symbol_id; order_mem[ord_idx].side <= s_event.side; order_mem[ord_idx].price <= s_event.price; order_mem[ord_idx].qty_remaining <= s_event.qty;
              lvl_idx_new = level_hash(s_event.symbol_id, s_event.side, s_event.price);
              if (!level_mem[lvl_idx_new].valid) begin level_mem[lvl_idx_new].valid <= 1'b1; level_mem[lvl_idx_new].symbol_id <= s_event.symbol_id; level_mem[lvl_idx_new].side <= s_event.side; level_mem[lvl_idx_new].price <= s_event.price; level_mem[lvl_idx_new].agg_qty <= s_event.qty; end else level_mem[lvl_idx_new].agg_qty <= level_mem[lvl_idx_new].agg_qty + s_event.qty;
              if (!s_event.side) begin if (!best_bid_valid[sym_idx] || (s_event.price > best_bid_price[sym_idx])) begin best_bid_valid[sym_idx] <= 1'b1; best_bid_price[sym_idx] <= s_event.price; best_bid_qty[sym_idx] <= s_event.qty; end else if (s_event.price == best_bid_price[sym_idx]) best_bid_qty[sym_idx] <= best_bid_qty[sym_idx] + s_event.qty; end else begin if (!best_ask_valid[sym_idx] || (s_event.price < best_ask_price[sym_idx])) begin best_ask_valid[sym_idx] <= 1'b1; best_ask_price[sym_idx] <= s_event.price; best_ask_qty[sym_idx] <= s_event.qty; end else if (s_event.price == best_ask_price[sym_idx]) best_ask_qty[sym_idx] <= best_ask_qty[sym_idx] + s_event.qty; end
              cnt_book_updates <= cnt_book_updates + 1'b1; m_book_event.book_event_type <= 3'd1; m_book_event_valid <= 1'b1;
            end
          end
          EV_EXEC, EV_CANCEL: begin
            if (!order_mem[ord_idx].valid) begin cnt_missing_order <= cnt_missing_order + 1'b1; m_book_event.flags[9] <= 1'b1; end else begin
              lvl_idx_old = level_hash(order_mem[ord_idx].symbol_id, order_mem[ord_idx].side, order_mem[ord_idx].price); delta_qty = s_event.qty;
              if (order_mem[ord_idx].qty_remaining < delta_qty || level_mem[lvl_idx_old].agg_qty < delta_qty) begin cnt_agg_underflow <= cnt_agg_underflow + 1'b1; m_book_event.flags[10] <= 1'b1; end else begin
                order_mem[ord_idx].qty_remaining <= order_mem[ord_idx].qty_remaining - delta_qty; level_mem[lvl_idx_old].agg_qty <= level_mem[lvl_idx_old].agg_qty - delta_qty; m_book_event.symbol_id <= order_mem[ord_idx].symbol_id; m_book_event.side <= order_mem[ord_idx].side; m_book_event.price <= order_mem[ord_idx].price;
                if ((order_mem[ord_idx].qty_remaining - delta_qty) == 0) order_mem[ord_idx].valid <= 1'b0;
                if (!order_mem[ord_idx].side) recompute_best_bid(sym_idx); else recompute_best_ask(sym_idx);
                cnt_book_updates <= cnt_book_updates + 1'b1; m_book_event.book_event_type <= (s_event.ev_type == EV_EXEC) ? 3'd2 : 3'd3; m_book_event_valid <= 1'b1;
              end
            end
          end
          EV_DELETE: begin
            if (!order_mem[ord_idx].valid) begin cnt_missing_order <= cnt_missing_order + 1'b1; m_book_event.flags[9] <= 1'b1; end else begin
              lvl_idx_old = level_hash(order_mem[ord_idx].symbol_id, order_mem[ord_idx].side, order_mem[ord_idx].price); delta_qty = order_mem[ord_idx].qty_remaining;
              if (level_mem[lvl_idx_old].agg_qty < delta_qty) begin cnt_agg_underflow <= cnt_agg_underflow + 1'b1; m_book_event.flags[10] <= 1'b1; end else begin
                level_mem[lvl_idx_old].agg_qty <= level_mem[lvl_idx_old].agg_qty - delta_qty; m_book_event.symbol_id <= order_mem[ord_idx].symbol_id; m_book_event.side <= order_mem[ord_idx].side; m_book_event.price <= order_mem[ord_idx].price; m_book_event.qty <= delta_qty; order_mem[ord_idx].valid <= 1'b0; if (!order_mem[ord_idx].side) recompute_best_bid(sym_idx); else recompute_best_ask(sym_idx); cnt_book_updates <= cnt_book_updates + 1'b1; m_book_event.book_event_type <= 3'd4; m_book_event_valid <= 1'b1;
              end
            end
          end
          EV_REPLACE: begin
            if (!order_mem[ord_idx].valid) begin cnt_missing_order <= cnt_missing_order + 1'b1; m_book_event.flags[9] <= 1'b1; end else begin
              lvl_idx_old = level_hash(order_mem[ord_idx].symbol_id, order_mem[ord_idx].side, order_mem[ord_idx].price); lvl_idx_new = level_hash(order_mem[ord_idx].symbol_id, order_mem[ord_idx].side, s_event.price);
              if (level_mem[lvl_idx_old].agg_qty < order_mem[ord_idx].qty_remaining) begin cnt_agg_underflow <= cnt_agg_underflow + 1'b1; m_book_event.flags[10] <= 1'b1; end else begin
                level_mem[lvl_idx_old].agg_qty <= level_mem[lvl_idx_old].agg_qty - order_mem[ord_idx].qty_remaining; order_mem[ord_idx].valid <= 1'b0;
                order_mem[order_hash(s_event.order_id_new)].valid <= 1'b1; order_mem[order_hash(s_event.order_id_new)].symbol_id <= order_mem[ord_idx].symbol_id; order_mem[order_hash(s_event.order_id_new)].side <= order_mem[ord_idx].side; order_mem[order_hash(s_event.order_id_new)].price <= s_event.price; order_mem[order_hash(s_event.order_id_new)].qty_remaining <= s_event.qty;
                if (!level_mem[lvl_idx_new].valid) begin level_mem[lvl_idx_new].valid <= 1'b1; level_mem[lvl_idx_new].symbol_id <= order_mem[ord_idx].symbol_id; level_mem[lvl_idx_new].side <= order_mem[ord_idx].side; level_mem[lvl_idx_new].price <= s_event.price; level_mem[lvl_idx_new].agg_qty <= s_event.qty; end else level_mem[lvl_idx_new].agg_qty <= level_mem[lvl_idx_new].agg_qty + s_event.qty;
                if (!order_mem[ord_idx].side) recompute_best_bid(sym_idx); else recompute_best_ask(sym_idx);
                m_book_event.symbol_id <= order_mem[ord_idx].symbol_id; m_book_event.side <= order_mem[ord_idx].side; m_book_event.price <= s_event.price; cnt_book_updates <= cnt_book_updates + 1'b1; m_book_event.book_event_type <= 3'd5; m_book_event_valid <= 1'b1;
              end
            end
          end
          EV_TRADE: begin m_book_event.book_event_type <= 3'd6; m_book_event_valid <= 1'b1; end
          default: ;
        endcase
        m_book_event.best_bid <= best_bid_price[sym_idx]; m_book_event.best_ask <= best_ask_price[sym_idx]; m_book_event.best_bid_qty <= best_bid_qty[sym_idx]; m_book_event.best_ask_qty <= best_ask_qty[sym_idx];
      end
    end
  end
endmodule : order_book_core
