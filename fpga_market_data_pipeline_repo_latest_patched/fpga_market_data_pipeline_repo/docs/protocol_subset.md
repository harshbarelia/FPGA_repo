# Protocol Subset — Nasdaq TotalView-ITCH 5.0

## Reference specification

This project implements a hardware decoder for a controlled subset of the
Nasdaq TotalView-ITCH 5.0 outbound data feed protocol, as published by
Nasdaq: https://www.nasdaqtrader.com/content/technicalsupport/specifications/dataproducts/NQTVITCHSpecification.pdf

All byte offsets, field widths, and message lengths in this repository are
derived directly from this specification. All multi-byte integer fields are
big-endian. Price fields carry 4 implied decimal digits. Timestamps are
nanoseconds since midnight, encoded as a 6-byte big-endian integer.

## Supported message types (v1)

| Type | Name | Length (bytes) | Book effect |
|---|---|---|---|
| R | Stock Directory | 39 | Symbol bootstrap only |
| A | Add Order - No MPID | 36 | Adds resting order |
| F | Add Order - MPID | 40 | Adds resting order (MPID ignored) |
| E | Order Executed | 31 | Reduces resting order qty |
| X | Order Cancel | 23 | Reduces resting order qty |
| D | Order Delete | 19 | Removes resting order |
| U | Order Replace | 35 | Retires old order, creates new |
| P | Trade (non-cross) | 44 | Event/analytics only |

## Field offsets

### R — Stock Directory (39 bytes)
Message Type(0,1), Stock Locate(1,2), Tracking Number(3,2), Timestamp(5,6), Stock(11,8), Market Category(19,1), Financial Status(20,1), Round Lot Size(21,4)

### A — Add Order (36 bytes)
Message Type(0,1), Stock Locate(1,2), Tracking Number(3,2), Timestamp(5,6), Order Ref(11,8), Buy/Sell(19,1), Shares(20,4), Stock(24,8), Price(32,4)

### F — Add Order MPID (40 bytes)
Same as A plus Attribution(36,4)

### E — Order Executed (31 bytes)
Message Type(0,1), Stock Locate(1,2), Tracking Number(3,2), Timestamp(5,6), Order Ref(11,8), Executed Shares(19,4), Match Number(23,8)

### X — Order Cancel (23 bytes)
Message Type(0,1), Stock Locate(1,2), Tracking Number(3,2), Timestamp(5,6), Order Ref(11,8), Canceled Shares(19,4)

### D — Order Delete (19 bytes)
Message Type(0,1), Stock Locate(1,2), Tracking Number(3,2), Timestamp(5,6), Order Ref(11,8)

### U — Order Replace (35 bytes)
Message Type(0,1), Stock Locate(1,2), Tracking Number(3,2), Timestamp(5,6), Original Order Ref(11,8), New Order Ref(19,8), Shares(27,4), Price(31,4)

### P — Trade (44 bytes)
Message Type(0,1), Stock Locate(1,2), Tracking Number(3,2), Timestamp(5,6), Order Ref(11,8), Buy/Sell(19,1), Shares(20,4), Stock(24,8), Price(32,4), Match Number(36,8)

## Out of scope (v1)

System Event, Market Participant Position, MWCB, IPO Quoting, LULD Auction Collar, Operational Halt, Cross Trade/NOII/RPII, and any type not listed above.

## Design rationale

R bootstraps the symbol directory, A/F create resting liquidity, E/X/D/U mutate or remove it, and P provides trade-print visibility without book mutation.
