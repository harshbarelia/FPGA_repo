# Order Book Core Specification

Defines the v1 microarchitecture for `rtl/book/order_book_core.sv`, the stateful core of the market-data engine, consuming normalized events from the decoder and maintaining order state, price-level aggregation, and top-of-book per symbol.

## State model

1. **Order-ID table** — keyed by order_id: valid, symbol_id, side, price, qty_remaining.
2. **Aggregated price-level table** — keyed by {symbol_id, side, price}: agg_qty.
3. **Top-of-book summary** — per symbol: best_bid_price/qty, best_ask_price/qty.

## Event processing rules

- `EV_ADD`: insert order, add qty to level, update best price if improved.
- `EV_EXEC`/`EV_CANCEL`: look up order, subtract qty from order and level, delete order if qty hits zero.
- `EV_DELETE`: remove full remaining qty from level, invalidate order.
- `EV_REPLACE`: remove old order/level qty, insert new order/level under new id/price.
- `EV_TRADE`: event-only, no book mutation in v1.

## Error model

Counters track duplicate adds, missing-order references, and aggregate underflow, exposed as `cnt_duplicate_add`, `cnt_missing_order`, `cnt_agg_underflow`, `cnt_book_updates`.

## Status: v1 implemented, integration-verified

`order_book_core.sv` is implemented and exercised by both `tb/unit/tb_order_book.sv` (directed unit test) and `tb/int/tb_int_pipeline.sv` (full decoder-to-DMA integration test), both passing the same six-event lifecycle sequence (ADD/ADD/EXEC/CANCEL/REPLACE/DELETE).
