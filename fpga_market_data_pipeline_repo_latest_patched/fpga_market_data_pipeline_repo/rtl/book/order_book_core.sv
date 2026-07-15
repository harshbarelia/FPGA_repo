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
    output logic [31:0]          cnt_book_updates,
    output logic [31:0]          cnt_ord_set_full,
    output logic [31:0]          cnt_lvl_set_full,
    output logic [31:0]          cnt_track_exhausted
);

  // Set-associative parameters: 4-way set associative
  localparam int ORD_WAYS   = 4;
  localparam int ORD_SETS   = NUM_ORDERS / ORD_WAYS;
  localparam int ORD_SET_W  = $clog2(ORD_SETS);
  localparam int ORD_WAY_W  = $clog2(ORD_WAYS);

  localparam int LVL_WAYS   = 4;
  localparam int LVL_SETS   = NUM_LEVELS / LVL_WAYS;
  localparam int LVL_SET_W  = $clog2(LVL_SETS);
  localparam int LVL_WAY_W  = $clog2(LVL_WAYS);

  // Number of active levels tracked per symbol side to avoid O(NUM_LEVELS) scans
  localparam int N_TRACKED  = 8;

  typedef struct packed {
    logic                     valid;
    logic [ORDER_ID_W-1:0]    order_id;
    logic [SYMBOL_ID_W-1:0]   symbol_id;
    logic                     side;
    logic [PRICE_W-1:0]       price;
    logic [QTY_W-1:0]         qty_remaining;
  } order_entry_t;

  typedef struct packed {
    logic                     valid;
    logic [SYMBOL_ID_W-1:0]   symbol_id;
    logic                     side;
    logic [PRICE_W-1:0]       price;
    logic [QTY_W-1:0]         agg_qty;
  } level_entry_t;

  order_entry_t order_mem [ORD_SETS][ORD_WAYS];
  level_entry_t level_mem [LVL_SETS][LVL_WAYS];

  logic                     best_bid_valid [NUM_SYMBOLS];
  logic [PRICE_W-1:0]       best_bid_price [NUM_SYMBOLS];
  logic [QTY_W-1:0]         best_bid_qty   [NUM_SYMBOLS];
  logic                     best_ask_valid [NUM_SYMBOLS];
  logic [PRICE_W-1:0]       best_ask_price [NUM_SYMBOLS];
  logic [QTY_W-1:0]         best_ask_qty   [NUM_SYMBOLS];

  logic [LVL_ADDR_W-1:0]    tracked_lvl_idx [NUM_SYMBOLS][2][N_TRACKED];
  logic                     tracked_lvl_val [NUM_SYMBOLS][2][N_TRACKED];

  logic pipe_stall;
  assign pipe_stall = m_book_event_valid && !m_book_event_ready;
  assign s_event_ready = !pipe_stall;

  function automatic [ORD_SET_W-1:0] order_hash(input logic [ORDER_ID_W-1:0] id);
    return id[ORD_SET_W-1:0];
  endfunction

  function automatic [LVL_SET_W-1:0] level_hash(
    input logic [SYMBOL_ID_W-1:0] symbol_id,
    input logic                   side,
    input logic [PRICE_W-1:0]     price
  );
    return (symbol_id[LVL_SET_W-1:0] ^ { {(LVL_SET_W-1){1'b0}}, side } ^ price[LVL_SET_W-1:0]);
  endfunction

  // Lookups & Allocations combinationally calculated
  logic [ORD_SET_W-1:0] ord_set;
  logic                 ord_hit;
  logic [ORD_WAY_W-1:0] ord_hit_way;
  logic                 ord_alloc_ok;
  logic [ORD_WAY_W-1:0] ord_alloc_way;

  always_comb begin
    ord_set = order_hash(s_event.order_id);
    ord_hit = 1'b0;
    ord_hit_way = '0;
    for (int w = 0; w < ORD_WAYS; w++) begin
      if (order_mem[ord_set][w].valid && (order_mem[ord_set][w].order_id == s_event.order_id)) begin
        ord_hit = 1'b1;
        ord_hit_way = w[ORD_WAY_W-1:0];
      end
    end
    ord_alloc_ok = 1'b0;
    ord_alloc_way = '0;
    for (int w = 0; w < ORD_WAYS; w++) begin
      if (!order_mem[ord_set][w].valid) begin
        ord_alloc_ok = 1'b1;
        ord_alloc_way = w[ORD_WAY_W-1:0];
        break;
      end
    end
  end

  logic [ORD_SET_W-1:0] ord_set_new;
  logic                 ord_hit_new;
  logic [ORD_WAY_W-1:0] ord_hit_way_new;
  logic                 ord_alloc_ok_new;
  logic [ORD_WAY_W-1:0] ord_alloc_way_new;

  always_comb begin
    ord_set_new = order_hash(s_event.order_id_new);
    ord_hit_new = 1'b0;
    ord_hit_way_new = '0;
    for (int w = 0; w < ORD_WAYS; w++) begin
      if (order_mem[ord_set_new][w].valid && (order_mem[ord_set_new][w].order_id == s_event.order_id_new)) begin
        ord_hit_new = 1'b1;
        ord_hit_way_new = w[ORD_WAY_W-1:0];
      end
    end
    ord_alloc_ok_new = 1'b0;
    ord_alloc_way_new = '0;
    for (int w = 0; w < ORD_WAYS; w++) begin
      if (!order_mem[ord_set_new][w].valid) begin
        ord_alloc_ok_new = 1'b1;
        ord_alloc_way_new = w[ORD_WAY_W-1:0];
        break;
      end
    end
  end

  logic [LVL_SET_W-1:0] lvl_set_new;
  logic                 lvl_hit;
  logic [LVL_WAY_W-1:0] lvl_hit_way;
  logic                 lvl_alloc_ok;
  logic [LVL_WAY_W-1:0] lvl_alloc_way;

  always_comb begin
    lvl_set_new = level_hash(s_event.symbol_id, s_event.side, s_event.price);
    lvl_hit = 1'b0;
    lvl_hit_way = '0;
    for (int w = 0; w < LVL_WAYS; w++) begin
      if (level_mem[lvl_set_new][w].valid &&
          (level_mem[lvl_set_new][w].symbol_id == s_event.symbol_id) &&
          (level_mem[lvl_set_new][w].side == s_event.side) &&
          (level_mem[lvl_set_new][w].price == s_event.price)) begin
        lvl_hit = 1'b1;
        lvl_hit_way = w[LVL_WAY_W-1:0];
      end
    end
    lvl_alloc_ok = 1'b0;
    lvl_alloc_way = '0;
    for (int w = 0; w < LVL_WAYS; w++) begin
      if (!level_mem[lvl_set_new][w].valid) begin
        lvl_alloc_ok = 1'b1;
        lvl_alloc_way = w[LVL_WAY_W-1:0];
        break;
      end
    end
  end

  logic [LVL_SET_W-1:0] lvl_set_old;
  logic                 lvl_hit_old;
  logic [LVL_WAY_W-1:0] lvl_hit_way_old;

  always_comb begin
    if (ord_hit) begin
      lvl_set_old = level_hash(order_mem[ord_set][ord_hit_way].symbol_id,
                               order_mem[ord_set][ord_hit_way].side,
                               order_mem[ord_set][ord_hit_way].price);
      lvl_hit_old = 1'b0;
      lvl_hit_way_old = '0;
      for (int w = 0; w < LVL_WAYS; w++) begin
        if (level_mem[lvl_set_old][w].valid &&
            (level_mem[lvl_set_old][w].symbol_id == order_mem[ord_set][ord_hit_way].symbol_id) &&
            (level_mem[lvl_set_old][w].side == order_mem[ord_set][ord_hit_way].side) &&
            (level_mem[lvl_set_old][w].price == order_mem[ord_set][ord_hit_way].price)) begin
          lvl_hit_old = 1'b1;
          lvl_hit_way_old = w[LVL_WAY_W-1:0];
        end
      end
    end else begin
      lvl_set_old = '0;
      lvl_hit_old = 1'b0;
      lvl_hit_way_old = '0;
    end
  end

  logic                  lvl_upd_1;
  logic [LVL_ADDR_W-1:0] lvl_upd_idx_1;
  logic [QTY_W-1:0]      lvl_upd_qty_1;
  logic                  lvl_upd_val_1;

  logic                  lvl_upd_2;
  logic [LVL_ADDR_W-1:0] lvl_upd_idx_2;
  logic [QTY_W-1:0]      lvl_upd_qty_2;
  logic                  lvl_upd_val_2;

  logic [QTY_W-1:0]      d_qty;
  logic [SYM_ADDR_W-1:0] sym_idx;
  assign sym_idx = s_event.symbol_id[SYM_ADDR_W-1:0];

  always_comb begin
    lvl_upd_1     = 1'b0;
    lvl_upd_idx_1 = '0;
    lvl_upd_qty_1 = '0;
    lvl_upd_val_1 = 1'b0;

    lvl_upd_2     = 1'b0;
    lvl_upd_idx_2 = '0;
    lvl_upd_qty_2 = '0;
    lvl_upd_val_2 = 1'b0;

    d_qty         = '0;

    if (s_event_valid) begin
      case (s_event.ev_type)
        EV_ADD: begin
          if (!ord_hit && (lvl_hit || lvl_alloc_ok)) begin
            lvl_upd_1     = 1'b1;
            lvl_upd_idx_1 = lvl_hit ? {lvl_set_new, lvl_hit_way} : {lvl_set_new, lvl_alloc_way};
            lvl_upd_qty_1 = lvl_hit ? (level_mem[lvl_set_new][lvl_hit_way].agg_qty + s_event.qty) : s_event.qty;
            lvl_upd_val_1 = 1'b1;
          end
        end
        EV_EXEC, EV_CANCEL: begin
          if (ord_hit && lvl_hit_old) begin
            d_qty = s_event.qty;
            if (order_mem[ord_set][ord_hit_way].qty_remaining >= d_qty &&
                level_mem[lvl_set_old][lvl_hit_way_old].agg_qty >= d_qty) begin
              lvl_upd_1     = 1'b1;
              lvl_upd_idx_1 = {lvl_set_old, lvl_hit_way_old};
              lvl_upd_qty_1 = level_mem[lvl_set_old][lvl_hit_way_old].agg_qty - d_qty;
              lvl_upd_val_1 = (lvl_upd_qty_1 > 0);
            end
          end
        end
        EV_DELETE: begin
          if (ord_hit && lvl_hit_old) begin
            d_qty = order_mem[ord_set][ord_hit_way].qty_remaining;
            if (level_mem[lvl_set_old][lvl_hit_way_old].agg_qty >= d_qty) begin
              lvl_upd_1     = 1'b1;
              lvl_upd_idx_1 = {lvl_set_old, lvl_hit_way_old};
              lvl_upd_qty_1 = level_mem[lvl_set_old][lvl_hit_way_old].agg_qty - d_qty;
              lvl_upd_val_1 = (lvl_upd_qty_1 > 0);
            end
          end
        end
        EV_REPLACE: begin
          if (ord_hit && lvl_hit_old && ord_alloc_ok_new) begin
            d_qty = order_mem[ord_set][ord_hit_way].qty_remaining;
            if (level_mem[lvl_set_old][lvl_hit_way_old].agg_qty >= d_qty && (lvl_hit || lvl_alloc_ok)) begin
              lvl_upd_1     = 1'b1;
              lvl_upd_idx_1 = {lvl_set_old, lvl_hit_way_old};
              lvl_upd_qty_1 = level_mem[lvl_set_old][lvl_hit_way_old].agg_qty - d_qty;
              lvl_upd_val_1 = (lvl_upd_qty_1 > 0);

              lvl_upd_2     = 1'b1;
              lvl_upd_idx_2 = lvl_hit ? {lvl_set_new, lvl_hit_way} : {lvl_set_new, lvl_alloc_way};
              
              if (lvl_upd_idx_2 == lvl_upd_idx_1) begin
                lvl_upd_qty_1 = lvl_upd_qty_1 + s_event.qty;
                lvl_upd_val_1 = (lvl_upd_qty_1 > 0);
                lvl_upd_2     = 1'b0;
              end else begin
                lvl_upd_qty_2 = lvl_hit ? (level_mem[lvl_set_new][lvl_hit_way].agg_qty + s_event.qty) : s_event.qty;
                lvl_upd_val_2 = 1'b1;
              end
            end
          end
        end
        default: ;
      endcase
    end
  end

  function automatic logic [QTY_W-1:0] get_next_qty(
    input logic [LVL_ADDR_W-1:0] l_idx,
    input logic                  current_valid,
    input logic [QTY_W-1:0]      current_qty
  );
    if (lvl_upd_1 && (lvl_upd_idx_1 == l_idx)) begin
      return lvl_upd_qty_1;
    end else if (lvl_upd_2 && (lvl_upd_idx_2 == l_idx)) begin
      return lvl_upd_qty_2;
    end else begin
      return current_valid ? current_qty : '0;
    end
  endfunction

  function automatic logic get_next_val(
    input logic [LVL_ADDR_W-1:0] l_idx,
    input logic                  current_valid
  );
    if (lvl_upd_1 && (lvl_upd_idx_1 == l_idx)) begin
      return lvl_upd_val_1;
    end else if (lvl_upd_2 && (lvl_upd_idx_2 == l_idx)) begin
      return lvl_upd_val_2;
    end else begin
      return current_valid;
    end
  endfunction

  logic [PRICE_W-1:0] next_best_bid_p;
  logic [QTY_W-1:0]   next_best_bid_q;
  logic                next_best_bid_v;

  logic [PRICE_W-1:0] next_best_ask_p;
  logic [QTY_W-1:0]   next_best_ask_q;
  logic                next_best_ask_v;

  logic [LVL_ADDR_W-1:0] next_bid_l_idx;
  logic [LVL_SET_W-1:0]  next_bid_l_set;
  logic [LVL_WAY_W-1:0]  next_bid_l_way;
  logic [PRICE_W-1:0]    next_bid_price;
  logic [QTY_W-1:0]      next_bid_qty;
  logic                  next_bid_val;
  logic [PRICE_W-1:0]    next_bid_new_price;

  always_comb begin
    next_best_bid_p = '0;
    next_best_bid_q = '0;
    next_best_bid_v = 1'b0;
    
    next_bid_l_idx = '0;
    next_bid_l_set = '0;
    next_bid_l_way = '0;
    next_bid_price = '0;
    next_bid_qty   = '0;
    next_bid_val   = 1'b0;
    next_bid_new_price = '0;

    for (int t = 0; t < N_TRACKED; t++) begin
      if (tracked_lvl_val[sym_idx][0][t]) begin
        next_bid_l_idx = tracked_lvl_idx[sym_idx][0][t];
        next_bid_l_set = next_bid_l_idx[LVL_ADDR_W-1:LVL_WAY_W];
        next_bid_l_way = next_bid_l_idx[LVL_WAY_W-1:0];
        next_bid_price = level_mem[next_bid_l_set][next_bid_l_way].price;
        next_bid_qty   = get_next_qty(next_bid_l_idx, 1'b1, level_mem[next_bid_l_set][next_bid_l_way].agg_qty);
        next_bid_val   = get_next_val(next_bid_l_idx, 1'b1);

        if (next_bid_val && next_bid_qty > 0) begin
          if (!next_best_bid_v || (next_bid_price > next_best_bid_p)) begin
            next_best_bid_v = 1'b1;
            next_best_bid_p = next_bid_price;
            next_best_bid_q = next_bid_qty;
          end
        end
      end
    end

    if (lvl_upd_1 && lvl_upd_val_1 && lvl_upd_qty_1 > 0 &&
        (s_event.ev_type == EV_ADD || s_event.ev_type == EV_REPLACE) &&
        (s_event.ev_type == EV_ADD ? !s_event.side : !order_mem[ord_set][ord_hit_way].side)) begin
      next_bid_new_price = s_event.price;
      if (!next_best_bid_v || (next_bid_new_price > next_best_bid_p)) begin
        next_best_bid_v = 1'b1;
        next_best_bid_p = next_bid_new_price;
        next_best_bid_q = lvl_upd_qty_1;
      end
    end

    if (lvl_upd_2 && lvl_upd_val_2 && lvl_upd_qty_2 > 0 &&
        s_event.ev_type == EV_REPLACE && !order_mem[ord_set][ord_hit_way].side) begin
      if (!next_best_bid_v || (s_event.price > next_best_bid_p)) begin
        next_best_bid_v = 1'b1;
        next_best_bid_p = s_event.price;
        next_best_bid_q = lvl_upd_qty_2;
      end
    end
  end

  logic [LVL_ADDR_W-1:0] next_ask_l_idx;
  logic [LVL_SET_W-1:0]  next_ask_l_set;
  logic [LVL_WAY_W-1:0]  next_ask_l_way;
  logic [PRICE_W-1:0]    next_ask_price;
  logic [QTY_W-1:0]      next_ask_qty;
  logic                  next_ask_val;
  logic [PRICE_W-1:0]    next_ask_new_price;

  always_comb begin
    next_best_ask_p = '0;
    next_best_ask_q = '0;
    next_best_ask_v = 1'b0;
    
    next_ask_l_idx = '0;
    next_ask_l_set = '0;
    next_ask_l_way = '0;
    next_ask_price = '0;
    next_ask_qty   = '0;
    next_ask_val   = 1'b0;
    next_ask_new_price = '0;

    for (int t = 0; t < N_TRACKED; t++) begin
      if (tracked_lvl_val[sym_idx][1][t]) begin
        next_ask_l_idx = tracked_lvl_idx[sym_idx][1][t];
        next_ask_l_set = next_ask_l_idx[LVL_ADDR_W-1:LVL_WAY_W];
        next_ask_l_way = next_ask_l_idx[LVL_WAY_W-1:0];
        next_ask_price = level_mem[next_ask_l_set][next_ask_l_way].price;
        next_ask_qty   = get_next_qty(next_ask_l_idx, 1'b1, level_mem[next_ask_l_set][next_ask_l_way].agg_qty);
        next_ask_val   = get_next_val(next_ask_l_idx, 1'b1);

        if (next_ask_val && next_ask_qty > 0) begin
          if (!next_best_ask_v || (next_best_ask_p == '0) || (next_ask_price < next_best_ask_p)) begin
            next_best_ask_v = 1'b1;
            next_best_ask_p = next_ask_price;
            next_best_ask_q = next_ask_qty;
          end
        end
      end
    end

    if (lvl_upd_1 && lvl_upd_val_1 && lvl_upd_qty_1 > 0 &&
        (s_event.ev_type == EV_ADD || s_event.ev_type == EV_REPLACE) &&
        (s_event.ev_type == EV_ADD ? s_event.side : order_mem[ord_set][ord_hit_way].side)) begin
      next_ask_new_price = s_event.price;
      if (!next_best_ask_v || (next_best_ask_p == '0) || (next_ask_new_price < next_best_ask_p)) begin
        next_best_ask_v = 1'b1;
        next_best_ask_p = next_ask_new_price;
        next_best_ask_q = lvl_upd_qty_1;
      end
    end

    if (lvl_upd_2 && lvl_upd_val_2 && lvl_upd_qty_2 > 0 &&
        s_event.ev_type == EV_REPLACE && order_mem[ord_set][ord_hit_way].side) begin
      if (!next_best_ask_v || (next_best_ask_p == '0) || (s_event.price < next_best_ask_p)) begin
        next_best_ask_v = 1'b1;
        next_best_ask_p = s_event.price;
        next_best_ask_q = lvl_upd_qty_2;
      end
    end
  end

  logic [PRICE_W-1:0] final_best_bid_p;
  logic [QTY_W-1:0]   final_best_bid_q;
  logic                final_best_bid_v;

  logic [PRICE_W-1:0] final_best_ask_p;
  logic [QTY_W-1:0]   final_best_ask_q;
  logic                final_best_ask_v;

  always_comb begin
    if (s_event_valid) begin
      final_best_bid_p = next_best_bid_p;
      final_best_bid_q = next_best_bid_q;
      final_best_bid_v = next_best_bid_v;

      final_best_ask_p = next_best_ask_p;
      final_best_ask_q = next_best_ask_q;
      final_best_ask_v = next_best_ask_v;
    end else begin
      final_best_bid_p = best_bid_price[sym_idx];
      final_best_bid_q = best_bid_qty[sym_idx];
      final_best_bid_v = best_bid_valid[sym_idx];

      final_best_ask_p = best_ask_price[sym_idx];
      final_best_ask_q = best_ask_qty[sym_idx];
      final_best_ask_v = best_ask_valid[sym_idx];
    end
  end

  always_ff @(posedge clk or negedge rst_n) begin
    if (!rst_n) begin
      m_book_event_valid <= 1'b0;
      cnt_duplicate_add <= '0;
      cnt_missing_order <= '0;
      cnt_agg_underflow <= '0;
      cnt_book_updates <= '0;
      cnt_ord_set_full <= '0;
      cnt_lvl_set_full <= '0;
      cnt_track_exhausted <= '0;
      
      for (int s = 0; s < ORD_SETS; s++) begin
        for (int w = 0; w < ORD_WAYS; w++) begin
          order_mem[s][w].valid = 1'b0;
          order_mem[s][w].order_id = '0;
        end
      end
      
      for (int s = 0; s < LVL_SETS; s++) begin
        for (int w = 0; w < LVL_WAYS; w++) begin
          level_mem[s][w].valid = 1'b0;
        end
      end
      
      for (int i = 0; i < NUM_SYMBOLS; i++) begin
        best_bid_valid[i] = 1'b0;
        best_bid_price[i] = '0;
        best_bid_qty[i]   = '0;
        best_ask_valid[i] = 1'b0;
        best_ask_price[i] = '0;
        best_ask_qty[i]   = '0;
        
        for (int sd = 0; sd < 2; sd++) begin
          for (int t = 0; t < N_TRACKED; t++) begin
            tracked_lvl_idx[i][sd][t] = '0;
            tracked_lvl_val[i][sd][t] = 1'b0;
          end
        end
      end
    end else if (!pipe_stall) begin
      m_book_event_valid <= 1'b0;
      if (s_event_valid) begin
        m_book_event <= '{default:'0};
        m_book_event.ts_exchange <= s_event.ts_exchange;
        m_book_event.symbol_id   <= s_event.symbol_id;
        m_book_event.side        <= s_event.side;
        m_book_event.price       <= s_event.price;
        m_book_event.qty         <= s_event.qty;
        m_book_event.flags       <= s_event.flags;

        unique case (s_event.ev_type)
          EV_ADD: begin
            if (ord_hit) begin
              cnt_duplicate_add <= cnt_duplicate_add + 1'b1;
              m_book_event.flags[8] <= 1'b1;
            end else if (!ord_alloc_ok) begin
              cnt_ord_set_full <= cnt_ord_set_full + 1'b1;
              m_book_event.flags[11] <= 1'b1;
              m_book_event_valid <= 1'b1;
            end else if (!lvl_hit && !lvl_alloc_ok) begin
              cnt_lvl_set_full <= cnt_lvl_set_full + 1'b1;
              m_book_event.flags[12] <= 1'b1;
              m_book_event_valid <= 1'b1;
            end else begin
              order_mem[ord_set][ord_alloc_way].valid <= 1'b1;
              order_mem[ord_set][ord_alloc_way].order_id <= s_event.order_id;
              order_mem[ord_set][ord_alloc_way].symbol_id <= s_event.symbol_id;
              order_mem[ord_set][ord_alloc_way].side <= s_event.side;
              order_mem[ord_set][ord_alloc_way].price <= s_event.price;
              order_mem[ord_set][ord_alloc_way].qty_remaining <= s_event.qty;

              if (!lvl_hit) begin
                level_mem[lvl_set_new][lvl_alloc_way].valid <= 1'b1;
                level_mem[lvl_set_new][lvl_alloc_way].symbol_id <= s_event.symbol_id;
                level_mem[lvl_set_new][lvl_alloc_way].side <= s_event.side;
                level_mem[lvl_set_new][lvl_alloc_way].price <= s_event.price;
                level_mem[lvl_set_new][lvl_alloc_way].agg_qty <= s_event.qty;

                begin
                  logic has_empty;
                  int empty_idx;
                  logic [PRICE_W-1:0] worst_price;
                  int w_slot;
                  
                  has_empty = 1'b0;
                  empty_idx = 0;
                  for (int t = 0; t < N_TRACKED; t++) begin
                    if (!tracked_lvl_val[sym_idx][s_event.side][t]) begin
                      has_empty = 1'b1;
                      empty_idx = t;
                      break;
                    end
                  end
                  
                  if (has_empty) begin
                    tracked_lvl_idx[sym_idx][s_event.side][empty_idx] = {lvl_set_new, lvl_alloc_way};
                    tracked_lvl_val[sym_idx][s_event.side][empty_idx] = 1'b1;
                  end else begin
                    w_slot = 0;
                    begin
                      logic [LVL_SET_W-1:0] ts_set = tracked_lvl_idx[sym_idx][s_event.side][0][LVL_ADDR_W-1:LVL_WAY_W];
                      logic [LVL_WAY_W-1:0] ts_way = tracked_lvl_idx[sym_idx][s_event.side][0][LVL_WAY_W-1:0];
                      worst_price = level_mem[ts_set][ts_way].price;
                    end
                    
                    for (int t = 1; t < N_TRACKED; t++) begin
                      logic [LVL_SET_W-1:0] ts_set = tracked_lvl_idx[sym_idx][s_event.side][t][LVL_ADDR_W-1:LVL_WAY_W];
                      logic [LVL_WAY_W-1:0] ts_way = tracked_lvl_idx[sym_idx][s_event.side][t][LVL_WAY_W-1:0];
                      logic [PRICE_W-1:0] t_price = level_mem[ts_set][ts_way].price;
                      
                      if (!s_event.side) begin // Bid: worst is lowest price
                        if (t_price < worst_price) begin
                          worst_price = t_price;
                          w_slot = t;
                        end
                      end else begin // Ask: worst is highest price
                        if (t_price > worst_price) begin
                          worst_price = t_price;
                          w_slot = t;
                        end
                      end
                    end
                    
                    if (!s_event.side) begin
                      if (s_event.price > worst_price) begin
                        tracked_lvl_idx[sym_idx][s_event.side][w_slot] = {lvl_set_new, lvl_alloc_way};
                      end
                      cnt_track_exhausted <= cnt_track_exhausted + 1'b1;
                    end else begin
                      if (s_event.price < worst_price) begin
                        tracked_lvl_idx[sym_idx][s_event.side][w_slot] = {lvl_set_new, lvl_alloc_way};
                      end
                      cnt_track_exhausted <= cnt_track_exhausted + 1'b1;
                    end
                  end
                end
              end else begin
                level_mem[lvl_set_new][lvl_hit_way].agg_qty <= level_mem[lvl_set_new][lvl_hit_way].agg_qty + s_event.qty;
              end

              cnt_book_updates <= cnt_book_updates + 1'b1;
              m_book_event.book_event_type <= 3'd1;
              m_book_event_valid <= 1'b1;
            end
          end

          EV_EXEC, EV_CANCEL: begin
            if (!ord_hit) begin
              cnt_missing_order <= cnt_missing_order + 1'b1;
              m_book_event.flags[9] <= 1'b1;
            end else begin
              logic [QTY_W-1:0] d_qty = s_event.qty;
              if (order_mem[ord_set][ord_hit_way].qty_remaining < d_qty ||
                  !lvl_hit_old ||
                  level_mem[lvl_set_old][lvl_hit_way_old].agg_qty < d_qty) begin
                cnt_agg_underflow <= cnt_agg_underflow + 1'b1;
                m_book_event.flags[10] <= 1'b1;
              end else begin
                order_mem[ord_set][ord_hit_way].qty_remaining <= order_mem[ord_set][ord_hit_way].qty_remaining - d_qty;
                m_book_event.symbol_id <= order_mem[ord_set][ord_hit_way].symbol_id;
                m_book_event.side <= order_mem[ord_set][ord_hit_way].side;
                m_book_event.price <= order_mem[ord_set][ord_hit_way].price;

                if (order_mem[ord_set][ord_hit_way].qty_remaining == d_qty) begin
                  order_mem[ord_set][ord_hit_way].valid <= 1'b0;
                end

                if (!lvl_upd_val_1) begin
                  level_mem[lvl_set_old][lvl_hit_way_old].valid <= 1'b0;
                  for (int t = 0; t < N_TRACKED; t++) begin
                    if (tracked_lvl_val[sym_idx][order_mem[ord_set][ord_hit_way].side][t] &&
                        (tracked_lvl_idx[sym_idx][order_mem[ord_set][ord_hit_way].side][t] == lvl_upd_idx_1)) begin
                      tracked_lvl_val[sym_idx][order_mem[ord_set][ord_hit_way].side][t] = 1'b0;
                    end
                  end
                end else begin
                  level_mem[lvl_set_old][lvl_hit_way_old].agg_qty <= lvl_upd_qty_1;
                end

                cnt_book_updates <= cnt_book_updates + 1'b1;
                m_book_event.book_event_type <= (s_event.ev_type == EV_EXEC) ? 3'd2 : 3'd3;
                m_book_event_valid <= 1'b1;
              end
            end
          end

          EV_DELETE: begin
            if (!ord_hit) begin
              cnt_missing_order <= cnt_missing_order + 1'b1;
              m_book_event.flags[9] <= 1'b1;
            end else begin
              logic [QTY_W-1:0] d_qty = order_mem[ord_set][ord_hit_way].qty_remaining;
              if (!lvl_hit_old || level_mem[lvl_set_old][lvl_hit_way_old].agg_qty < d_qty) begin
                cnt_agg_underflow <= cnt_agg_underflow + 1'b1;
                m_book_event.flags[10] <= 1'b1;
              end else begin
                order_mem[ord_set][ord_hit_way].valid <= 1'b0;
                m_book_event.symbol_id <= order_mem[ord_set][ord_hit_way].symbol_id;
                m_book_event.side <= order_mem[ord_set][ord_hit_way].side;
                m_book_event.price <= order_mem[ord_set][ord_hit_way].price;
                m_book_event.qty <= d_qty;

                if (!lvl_upd_val_1) begin
                  level_mem[lvl_set_old][lvl_hit_way_old].valid <= 1'b0;
                  for (int t = 0; t < N_TRACKED; t++) begin
                    if (tracked_lvl_val[sym_idx][order_mem[ord_set][ord_hit_way].side][t] &&
                        (tracked_lvl_idx[sym_idx][order_mem[ord_set][ord_hit_way].side][t] == lvl_upd_idx_1)) begin
                      tracked_lvl_val[sym_idx][order_mem[ord_set][ord_hit_way].side][t] = 1'b0;
                    end
                  end
                end else begin
                  level_mem[lvl_set_old][lvl_hit_way_old].agg_qty <= lvl_upd_qty_1;
                end

                cnt_book_updates <= cnt_book_updates + 1'b1;
                m_book_event.book_event_type <= 3'd4;
                m_book_event_valid <= 1'b1;
              end
            end
          end

          EV_REPLACE: begin
            if (!ord_hit) begin
              cnt_missing_order <= cnt_missing_order + 1'b1;
              m_book_event.flags[9] <= 1'b1;
            end else begin
              logic [QTY_W-1:0] d_qty = order_mem[ord_set][ord_hit_way].qty_remaining;
              if (level_mem[lvl_set_old][lvl_hit_way_old].agg_qty < d_qty || !lvl_hit_old) begin
                cnt_agg_underflow <= cnt_agg_underflow + 1'b1;
                m_book_event.flags[10] <= 1'b1;
              end else if (!ord_alloc_ok_new) begin
                cnt_ord_set_full <= cnt_ord_set_full + 1'b1;
                m_book_event.flags[11] <= 1'b1;
                m_book_event_valid <= 1'b1;
              end else if (!lvl_hit && !lvl_alloc_ok) begin
                cnt_lvl_set_full <= cnt_lvl_set_full + 1'b1;
                m_book_event.flags[12] <= 1'b1;
                m_book_event_valid <= 1'b1;
              end else begin
                order_mem[ord_set][ord_hit_way].valid <= 1'b0;

                order_mem[ord_set_new][ord_alloc_way_new].valid <= 1'b1;
                order_mem[ord_set_new][ord_alloc_way_new].order_id <= s_event.order_id_new;
                order_mem[ord_set_new][ord_alloc_way_new].symbol_id <= order_mem[ord_set][ord_hit_way].symbol_id;
                order_mem[ord_set_new][ord_alloc_way_new].side <= order_mem[ord_set][ord_hit_way].side;
                order_mem[ord_set_new][ord_alloc_way_new].price <= s_event.price;
                order_mem[ord_set_new][ord_alloc_way_new].qty_remaining <= s_event.qty;

                if (!lvl_upd_val_1) begin
                  level_mem[lvl_set_old][lvl_hit_way_old].valid <= 1'b0;
                  for (int t = 0; t < N_TRACKED; t++) begin
                    if (tracked_lvl_val[sym_idx][order_mem[ord_set][ord_hit_way].side][t] &&
                        (tracked_lvl_idx[sym_idx][order_mem[ord_set][ord_hit_way].side][t] == lvl_upd_idx_1)) begin
                      tracked_lvl_val[sym_idx][order_mem[ord_set][ord_hit_way].side][t] = 1'b0;
                    end
                  end
                end else begin
                  level_mem[lvl_set_old][lvl_hit_way_old].agg_qty <= lvl_upd_qty_1;
                end

                if (lvl_upd_2) begin
                  if (!lvl_hit) begin
                    level_mem[lvl_set_new][lvl_alloc_way].valid <= 1'b1;
                    level_mem[lvl_set_new][lvl_alloc_way].symbol_id <= order_mem[ord_set][ord_hit_way].symbol_id;
                    level_mem[lvl_set_new][lvl_alloc_way].side <= order_mem[ord_set][ord_hit_way].side;
                    level_mem[lvl_set_new][lvl_alloc_way].price <= s_event.price;
                    level_mem[lvl_set_new][lvl_alloc_way].agg_qty <= lvl_upd_qty_2;

                    begin
                      logic has_empty;
                      int empty_idx;
                      logic [PRICE_W-1:0] worst_price;
                      int w_slot;
                      logic o_side;
                      o_side = order_mem[ord_set][ord_hit_way].side;
                      
                      has_empty = 1'b0;
                      empty_idx = 0;
                      for (int t = 0; t < N_TRACKED; t++) begin
                        if (!tracked_lvl_val[sym_idx][o_side][t]) begin
                          has_empty = 1'b1;
                          empty_idx = t;
                          break;
                        end
                      end
                      
                      if (has_empty) begin
                        tracked_lvl_idx[sym_idx][o_side][empty_idx] = {lvl_set_new, lvl_alloc_way};
                        tracked_lvl_val[sym_idx][o_side][empty_idx] = 1'b1;
                      end else begin
                        w_slot = 0;
                        begin
                          logic [LVL_SET_W-1:0] ts_set = tracked_lvl_idx[sym_idx][o_side][0][LVL_ADDR_W-1:LVL_WAY_W];
                          logic [LVL_WAY_W-1:0] ts_way = tracked_lvl_idx[sym_idx][o_side][0][LVL_WAY_W-1:0];
                          worst_price = level_mem[ts_set][ts_way].price;
                        end
                        
                        for (int t = 1; t < N_TRACKED; t++) begin
                          logic [LVL_SET_W-1:0] ts_set = tracked_lvl_idx[sym_idx][o_side][t][LVL_ADDR_W-1:LVL_WAY_W];
                          logic [LVL_WAY_W-1:0] ts_way = tracked_lvl_idx[sym_idx][o_side][t][LVL_WAY_W-1:0];
                          logic [PRICE_W-1:0] t_price = level_mem[ts_set][ts_way].price;
                          
                          if (!o_side) begin // Bid: worst is lowest price
                            if (t_price < worst_price) begin
                              worst_price = t_price;
                              w_slot = t;
                            end
                          end else begin // Ask: worst is highest price
                            if (t_price > worst_price) begin
                              worst_price = t_price;
                              w_slot = t;
                            end
                          end
                        end
                        
                        if (!o_side) begin
                          if (s_event.price > worst_price) begin
                            tracked_lvl_idx[sym_idx][o_side][w_slot] = {lvl_set_new, lvl_alloc_way};
                          end
                          cnt_track_exhausted <= cnt_track_exhausted + 1'b1;
                        end else begin
                          if (s_event.price < worst_price) begin
                            tracked_lvl_idx[sym_idx][o_side][w_slot] = {lvl_set_new, lvl_alloc_way};
                          end
                          cnt_track_exhausted <= cnt_track_exhausted + 1'b1;
                        end
                      end
                    end
                  end else begin
                    level_mem[lvl_set_new][lvl_hit_way].agg_qty <= lvl_upd_qty_2;
                  end
                end

                m_book_event.symbol_id <= order_mem[ord_set][ord_hit_way].symbol_id;
                m_book_event.side <= order_mem[ord_set][ord_hit_way].side;
                m_book_event.price <= s_event.price;
                cnt_book_updates <= cnt_book_updates + 1'b1;
                m_book_event.book_event_type <= 3'd5;
                m_book_event_valid <= 1'b1;
              end
            end
          end

          EV_TRADE: begin
            m_book_event.book_event_type <= 3'd6;
            m_book_event_valid <= 1'b1;
          end
          default: ;
        endcase

        best_bid_valid[sym_idx] <= final_best_bid_v;
        best_bid_price[sym_idx] <= final_best_bid_p;
        best_bid_qty[sym_idx]   <= final_best_bid_q;
        best_ask_valid[sym_idx] <= final_best_ask_v;
        best_ask_price[sym_idx] <= final_best_ask_p;
        best_ask_qty[sym_idx]   <= final_best_ask_q;

        m_book_event.best_bid     <= final_best_bid_p;
        m_book_event.best_ask     <= final_best_ask_p;
        m_book_event.best_bid_qty <= final_best_bid_q;
        m_book_event.best_ask_qty <= final_best_ask_q;
      end
    end
  end
endmodule : order_book_core
