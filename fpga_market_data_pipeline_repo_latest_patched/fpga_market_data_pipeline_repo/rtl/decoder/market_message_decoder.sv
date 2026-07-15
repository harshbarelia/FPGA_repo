// -----------------------------------------------------------------------------
// market_message_decoder.sv
// Decodes one framed Nasdaq TotalView-ITCH 5.0 message per handshake into
// hft_pkg::norm_event_t / hft_pkg::dec_meta_t. Drives symbol_table's write
// port on decoded Stock Directory ('R') messages so the decoder is the
// single source of directory updates.
// -----------------------------------------------------------------------------

import hft_pkg::*;
import be_extract_pkg::*;

module market_message_decoder #(
    parameter int MSG_BYTES = 64,
    parameter int MSG_W     = MSG_BYTES * 8
)(
    input  logic                     clk,
    input  logic                     rst_n,

    input  logic [MSG_W-1:0]         s_msg_data,
    input  logic [15:0]              s_msg_len,
    input  logic                     s_msg_valid,
    output logic                     s_msg_ready,

    output logic                     sym_lookup_req,
    output logic [15:0]              sym_lookup_stock_locate,
    output logic [63:0]              sym_lookup_stock8,
    input  logic                     sym_lookup_hit,
    input  logic [15:0]              sym_lookup_symbol_id,

    output logic                     sym_wr_en,
    output logic [15:0]              sym_wr_stock_locate,
    output logic [63:0]              sym_wr_stock8,

    output norm_event_t              m_event,
    output dec_meta_t                m_meta,
    output logic                     m_event_valid,
    input  logic                     m_event_ready
);

  logic [7:0]  s1_msg_type;
  logic [15:0] s1_expected_len;
  logic        s1_supported;
  logic        s1_length_ok;
  logic        s1_length_short;
  logic        s1_valid;

  always_comb begin
    s1_msg_type = get_u8(s_msg_data, MSG_BYTES, 0);
    case (s1_msg_type)
      MSG_STOCK_DIRECTORY : begin s1_expected_len = LEN_R; s1_supported = 1'b1; end
      MSG_ADD_ORDER        : begin s1_expected_len = LEN_A; s1_supported = 1'b1; end
      MSG_ADD_ORDER_MPID   : begin s1_expected_len = LEN_F; s1_supported = 1'b1; end
      MSG_ORDER_EXECUTED   : begin s1_expected_len = LEN_E; s1_supported = 1'b1; end
      MSG_ORDER_CANCEL      : begin s1_expected_len = LEN_X; s1_supported = 1'b1; end
      MSG_ORDER_DELETE      : begin s1_expected_len = LEN_D; s1_supported = 1'b1; end
      MSG_ORDER_REPLACE     : begin s1_expected_len = LEN_U; s1_supported = 1'b1; end
      MSG_TRADE               : begin s1_expected_len = LEN_P; s1_supported = 1'b1; end
      default                 : begin s1_expected_len = 16'd0; s1_supported = 1'b0; end
    endcase
    s1_length_ok    = (s_msg_len == s1_expected_len);
    s1_length_short = (s_msg_len < s1_expected_len);
  end

  logic pipe_stall;
  assign pipe_stall  = m_event_valid && !m_event_ready;
  assign s_msg_ready = !pipe_stall;
  assign s1_valid    = s_msg_valid && s_msg_ready;

  logic [MSG_W-1:0] s2_data;
  logic [15:0]      s2_len;
  logic [7:0]       s2_msg_type;
  logic             s2_supported;
  logic             s2_length_ok;
  logic             s2_length_short;
  logic             s2_valid;

  always_ff @(posedge clk or negedge rst_n) begin
    if (!rst_n) begin
      s2_valid <= 1'b0;
    end else if (!pipe_stall) begin
      s2_valid        <= s1_valid;
      s2_data         <= s_msg_data;
      s2_len          <= s_msg_len;
      s2_msg_type     <= s1_msg_type;
      s2_supported    <= s1_supported;
      s2_length_ok    <= s1_length_ok;
      s2_length_short <= s1_length_short;
    end
  end

  logic [15:0] x_stock_locate;
  logic [15:0] x_tracking_no;
  logic [47:0] x_ts_exchange;
  logic [63:0] x_order_id;
  logic [63:0] x_order_id_new;
  logic        x_side;
  logic [31:0] x_qty;
  logic [63:0] x_stock8;
  logic [31:0] x_price;

  always_comb begin
    x_stock_locate = get_be16(s2_data, MSG_BYTES, 1);
    x_tracking_no  = get_be16(s2_data, MSG_BYTES, 3);
    x_ts_exchange  = get_be48(s2_data, MSG_BYTES, 5);
    x_order_id     = 64'd0;
    x_order_id_new = 64'd0;
    x_side         = 1'b0;
    x_qty          = 32'd0;
    x_stock8       = 64'd0;
    x_price        = 32'd0;

    unique case (s2_msg_type)
      MSG_ADD_ORDER, MSG_ADD_ORDER_MPID: begin
        x_order_id = get_be64(s2_data, MSG_BYTES, 11);
        x_side     = (get_u8(s2_data, MSG_BYTES, 19) == "S");
        x_qty      = get_be32(s2_data, MSG_BYTES, 20);
        x_stock8   = pack_stock8(s2_data, MSG_BYTES, 24);
        x_price    = get_be32(s2_data, MSG_BYTES, 32);
      end
      MSG_ORDER_EXECUTED: begin
        x_order_id = get_be64(s2_data, MSG_BYTES, 11);
        x_qty      = get_be32(s2_data, MSG_BYTES, 19);
      end
      MSG_ORDER_CANCEL: begin
        x_order_id = get_be64(s2_data, MSG_BYTES, 11);
        x_qty      = get_be32(s2_data, MSG_BYTES, 19);
      end
      MSG_ORDER_DELETE: begin
        x_order_id = get_be64(s2_data, MSG_BYTES, 11);
      end
      MSG_ORDER_REPLACE: begin
        x_order_id     = get_be64(s2_data, MSG_BYTES, 11);
        x_order_id_new = get_be64(s2_data, MSG_BYTES, 19);
        x_qty          = get_be32(s2_data, MSG_BYTES, 27);
        x_price        = get_be32(s2_data, MSG_BYTES, 31);
      end
      MSG_TRADE: begin
        x_order_id = get_be64(s2_data, MSG_BYTES, 11);
        x_side     = (get_u8(s2_data, MSG_BYTES, 19) == "S");
        x_qty      = get_be32(s2_data, MSG_BYTES, 20);
        x_stock8   = pack_stock8(s2_data, MSG_BYTES, 24);
        x_price    = get_be32(s2_data, MSG_BYTES, 32);
      end
      MSG_STOCK_DIRECTORY: begin
        x_stock8 = pack_stock8(s2_data, MSG_BYTES, 11);
      end
      default: begin
      end
    endcase
  end

  assign sym_lookup_req          = s2_valid & s2_supported & s2_length_ok &
                                    ((s2_msg_type == MSG_ADD_ORDER)      |
                                     (s2_msg_type == MSG_ADD_ORDER_MPID) |
                                     (s2_msg_type == MSG_TRADE));
  assign sym_lookup_stock_locate = x_stock_locate;
  assign sym_lookup_stock8       = x_stock8;

  assign sym_wr_en           = s2_valid & s2_supported & s2_length_ok &
                                (s2_msg_type == MSG_STOCK_DIRECTORY);
  assign sym_wr_stock_locate = x_stock_locate;
  assign sym_wr_stock8       = x_stock8;

  logic         s3_valid;
  logic [7:0]   s3_msg_type;
  logic [15:0]  s3_len;
  logic         s3_supported;
  logic         s3_length_ok;
  logic         s3_length_short;
  norm_event_t  s3_ev_fields;
  logic         s3_sym_hit;
  logic [15:0]  s3_symbol_id;

  always_ff @(posedge clk or negedge rst_n) begin
    if (!rst_n) begin
      s3_valid <= 1'b0;
    end else if (!pipe_stall) begin
      s3_valid        <= s2_valid;
      s3_msg_type     <= s2_msg_type;
      s3_len          <= s2_len;
      s3_supported    <= s2_supported;
      s3_length_ok    <= s2_length_ok;
      s3_length_short <= s2_length_short;
      s3_ev_fields.side          <= x_side;
      s3_ev_fields.price         <= x_price;
      s3_ev_fields.qty           <= x_qty;
      s3_ev_fields.order_id      <= x_order_id;
      s3_ev_fields.order_id_new  <= x_order_id_new;
      s3_ev_fields.ts_exchange   <= x_ts_exchange;
      s3_ev_fields.stock_locate  <= x_stock_locate;
      s3_ev_fields.tracking_no   <= x_tracking_no;
      s3_sym_hit    <= sym_lookup_hit;
      s3_symbol_id  <= sym_lookup_symbol_id;
    end
  end

  logic needs_symbol;
  assign needs_symbol = (s3_msg_type == MSG_ADD_ORDER)      |
                        (s3_msg_type == MSG_ADD_ORDER_MPID) |
                        (s3_msg_type == MSG_TRADE);

  always_comb begin
    m_event = '{default: '0};
    m_meta  = '{default: '0};
    m_meta.msg_type_ascii = s3_msg_type;
    m_meta.msg_len_bytes  = s3_len;
    m_meta.stock_locate   = s3_ev_fields.stock_locate;
    m_meta.tracking_no    = s3_ev_fields.tracking_no;
    m_meta.ts_exchange    = s3_ev_fields.ts_exchange;
    m_meta.valid          = s3_valid;
    m_event.symbol_id     = s3_symbol_id;
    m_event.side          = s3_ev_fields.side;
    m_event.price         = s3_ev_fields.price;
    m_event.qty           = s3_ev_fields.qty;
    m_event.order_id       = s3_ev_fields.order_id;
    m_event.order_id_new  = s3_ev_fields.order_id_new;
    m_event.ts_exchange   = s3_ev_fields.ts_exchange;
    m_event.stock_locate  = s3_ev_fields.stock_locate;
    m_event.tracking_no   = s3_ev_fields.tracking_no;
    m_event.ev_type       = EV_NOP;

    if (!s3_supported) begin
      m_meta.status      = DEC_UNSUPPORTED;
      m_meta.unsupported = 1'b1;
      m_event.flags[0]   = 1'b1;
    end else if (!s3_length_ok) begin
      m_meta.status      = s3_length_short ? DEC_TRUNCATED : DEC_BAD_LENGTH;
      m_meta.malformed   = 1'b1;
      m_event.flags[1]   = 1'b1;
    end else if (needs_symbol && !s3_sym_hit) begin
      m_meta.status      = DEC_SYMBOL_UNKNOWN;
      m_event.flags[3]   = 1'b1;
      case (s3_msg_type)
        MSG_ADD_ORDER, MSG_ADD_ORDER_MPID: m_event.ev_type = EV_ADD;
        MSG_TRADE:                          m_event.ev_type = EV_TRADE;
        default:                             m_event.ev_type = EV_NOP;
      endcase
    end else begin
      m_meta.status = DEC_OK;
      case (s3_msg_type)
        MSG_ADD_ORDER, MSG_ADD_ORDER_MPID: begin
          m_event.ev_type = EV_ADD;
          if (s3_msg_type == MSG_ADD_ORDER_MPID) m_event.flags[5] = 1'b1;
        end
        MSG_ORDER_EXECUTED: m_event.ev_type = EV_EXEC;
        MSG_ORDER_CANCEL:    m_event.ev_type = EV_CANCEL;
        MSG_ORDER_DELETE:    m_event.ev_type = EV_DELETE;
        MSG_ORDER_REPLACE:   m_event.ev_type = EV_REPLACE;
        MSG_TRADE:             m_event.ev_type = EV_TRADE;
        MSG_STOCK_DIRECTORY:   m_event.ev_type = EV_NOP;
        default:                m_event.ev_type = EV_NOP;
      endcase
    end
  end

  assign m_event_valid = s3_valid;

  a_no_accept_when_stalled: assert property (
    @(posedge clk) disable iff (!rst_n)
    pipe_stall |-> !s_msg_ready)
  else $error("s_msg_ready asserted while pipeline stalled");

  a_unsupported_flag: assert property (
    @(posedge clk) disable iff (!rst_n)
    (m_event_valid && m_meta.unsupported) |-> m_event.flags[0])
  else $error("unsupported message missing flags[0]");

endmodule : market_message_decoder
