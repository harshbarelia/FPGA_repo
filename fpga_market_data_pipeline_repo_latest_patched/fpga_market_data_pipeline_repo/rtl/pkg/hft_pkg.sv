package hft_pkg;

  parameter int TS_W         = 48;
  parameter int SYMBOL_ID_W  = 16;
  parameter int PRICE_W      = 32;
  parameter int QTY_W        = 32;
  parameter int ORDER_ID_W   = 64;
  parameter int FLAGS_W      = 16;

  typedef enum logic [3:0] {
    EV_NOP     = 4'd0,
    EV_ADD     = 4'd1,
    EV_EXEC    = 4'd2,
    EV_CANCEL  = 4'd3,
    EV_DELETE  = 4'd4,
    EV_REPLACE = 4'd5,
    EV_TRADE   = 4'd6,
    EV_CLEAR   = 4'd7
  } ev_type_e;

  typedef enum logic [2:0] {
    DEC_OK              = 3'd0,
    DEC_UNSUPPORTED     = 3'd1,
    DEC_BAD_LENGTH      = 3'd2,
    DEC_BAD_FIELD       = 3'd3,
    DEC_TRUNCATED       = 3'd4,
    DEC_SYMBOL_UNKNOWN  = 3'd5
  } dec_status_e;

  typedef struct packed {
    logic [3:0]               ev_type;
    logic [SYMBOL_ID_W-1:0]   symbol_id;
    logic                     side;
    logic [PRICE_W-1:0]       price;
    logic [QTY_W-1:0]         qty;
    logic [ORDER_ID_W-1:0]    order_id;
    logic [ORDER_ID_W-1:0]    order_id_new;
    logic [TS_W-1:0]          ts_exchange;
    logic [15:0]              stock_locate;
    logic [15:0]              tracking_no;
    logic [FLAGS_W-1:0]       flags;
  } norm_event_t;

  typedef struct packed {
    logic [7:0]               msg_type_ascii;
    logic [15:0]              msg_len_bytes;
    logic [15:0]              stock_locate;
    logic [15:0]              tracking_no;
    logic [TS_W-1:0]          ts_exchange;
    logic [2:0]                status;
    logic                      valid;
    logic                      malformed;
    logic                      unsupported;
  } dec_meta_t;

  typedef struct packed {
    logic [63:0]               ts_local;
    logic [TS_W-1:0]           ts_exchange;
    logic [SYMBOL_ID_W-1:0]    symbol_id;
    logic                      side;
    logic [2:0]                book_event_type;
    logic [PRICE_W-1:0]        price;
    logic [QTY_W-1:0]          qty;
    logic [PRICE_W-1:0]        best_bid;
    logic [PRICE_W-1:0]        best_ask;
    logic [QTY_W-1:0]          best_bid_qty;
    logic [QTY_W-1:0]          best_ask_qty;
    logic [FLAGS_W-1:0]        flags;
  } book_event_record_t;

  parameter byte MSG_STOCK_DIRECTORY   = "R";
  parameter byte MSG_ADD_ORDER         = "A";
  parameter byte MSG_ADD_ORDER_MPID    = "F";
  parameter byte MSG_ORDER_EXECUTED    = "E";
  parameter byte MSG_ORDER_CANCEL      = "X";
  parameter byte MSG_ORDER_DELETE      = "D";
  parameter byte MSG_ORDER_REPLACE     = "U";
  parameter byte MSG_TRADE             = "P";

  parameter int LEN_R = 39;
  parameter int LEN_A = 36;
  parameter int LEN_F = 40;
  parameter int LEN_E = 31;
  parameter int LEN_X = 23;
  parameter int LEN_D = 19;
  parameter int LEN_U = 35;
  parameter int LEN_P = 44;

endpackage : hft_pkg
