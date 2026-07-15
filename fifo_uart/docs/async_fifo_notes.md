Async FIFO — Design & Verification Notes
Overview
This module implements an asynchronous FIFO used to safely transfer data between
two independent clock domains (write clock wclk and read clock rclk). Because
the write and read sides operate on unrelated clocks, the design must avoid
metastability when pointer information crosses the clock domain boundary.

Why Gray-Code Pointers
The write and read pointers are converted to Gray code before crossing into the
opposite clock domain. In Gray code, only a single bit changes between any two
consecutive values. This matters because:

If a multi-bit binary pointer is sampled by another clock domain, several bits
could be captured mid-transition, producing a completely wrong intermediate
value (not just an off-by-one error).

With Gray code, even if the destination clock samples the value mid-transition,
the worst case is capturing either the old or the new value — never a
nonsensical value in between.

This is the standard technique for safely communicating pointer state across
clock domains in async FIFOs.

Full / Empty Generation
full is generated on the write side by comparing the write pointer against
the synchronized read pointer (read pointer brought into the write clock
domain through the Gray-code synchronizer).

empty is generated on the read side by comparing the read pointer against
the synchronized write pointer (write pointer brought into the read clock
domain).

Both flags must be derived from the current pointers, not from combinational
"next-state" signals that themselves depend on the flag. Mixing these creates
a feedback loop.

Debugging: UNOPTFLAT Warning
During lint, Verilator reported:


%Warning-UNOPTFLAT: Signal unoptimizable: Circular combinational logic: 'full'

Root cause
The original code computed wr_ptr_bin_next using full, and then computed
full using signals derived from wr_ptr_bin_next (or an equivalent path back
through
