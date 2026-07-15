from dataclasses import dataclass, field
from typing import Dict, Tuple

@dataclass
class Order:
    symbol_id: int
    side: int
    price: int
    qty: int

@dataclass
class BookState:
    orders: Dict[int, Order] = field(default_factory=dict)
    levels: Dict[Tuple[int,int,int], int] = field(default_factory=dict)
    best_bid: Dict[int, Tuple[int,int]] = field(default_factory=dict)
    best_ask: Dict[int, Tuple[int,int]] = field(default_factory=dict)
    duplicate_add: int = 0
    missing_order: int = 0
    agg_underflow: int = 0
    book_updates: int = 0

    def _recompute_best(self, symbol_id: int):
        bids = [(p,q) for (s,side,p),q in self.levels.items() if s == symbol_id and side == 0 and q > 0]
        asks = [(p,q) for (s,side,p),q in self.levels.items() if s == symbol_id and side == 1 and q > 0]
        self.best_bid[symbol_id] = max(bids, key=lambda x: x[0], default=(0,0))
        self.best_ask[symbol_id] = min(asks, key=lambda x: x[0], default=(0,0))

    def apply(self, ev):
        et = ev['ev_type']
        oid = ev.get('order_id', 0)
        sid = ev.get('symbol_id', 0)
        side = ev.get('side', 0)
        price = ev.get('price', 0)
        qty = ev.get('qty', 0)
        if et == 'ADD':
            if oid in self.orders:
                self.duplicate_add += 1
                return
            self.orders[oid] = Order(sid, side, price, qty)
            self.levels[(sid, side, price)] = self.levels.get((sid, side, price), 0) + qty
            self.book_updates += 1
            self._recompute_best(sid)
        elif et in ('EXEC', 'CANCEL'):
            o = self.orders.get(oid)
            if o is None:
                self.missing_order += 1
                return
            if o.qty < qty:
                self.agg_underflow += 1
                return
            o.qty -= qty
            self.levels[(o.symbol_id, o.side, o.price)] -= qty
            if o.qty == 0:
                del self.orders[oid]
            self.book_updates += 1
            self._recompute_best(o.symbol_id)
        elif et == 'DELETE':
            o = self.orders.get(oid)
            if o is None:
                self.missing_order += 1
                return
            self.levels[(o.symbol_id, o.side, o.price)] -= o.qty
            del self.orders[oid]
            self.book_updates += 1
            self._recompute_best(o.symbol_id)
        elif et == 'REPLACE':
            o = self.orders.get(oid)
            if o is None:
                self.missing_order += 1
                return
            self.levels[(o.symbol_id, o.side, o.price)] -= o.qty
            del self.orders[oid]
            new_oid = ev['order_id_new']
            self.orders[new_oid] = Order(o.symbol_id, o.side, price, qty)
            self.levels[(o.symbol_id, o.side, price)] = self.levels.get((o.symbol_id, o.side, price), 0) + qty
            self.book_updates += 1
            self._recompute_best(o.symbol_id)
        elif et == 'TRADE':
            self.book_updates += 1
