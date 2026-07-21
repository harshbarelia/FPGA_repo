# STA Closure Checklist

## Clocks
- PCIe user clock: 250 MHz target (`create_clock -period 4.000`)
- Ethernet RX clock: 156.25 MHz target (`create_clock -period 6.400`)
- Add generated clocks for AXI/MMCM outputs once integrated

## Reports to generate in Vivado
```tcl
report_clocks
report_clock_interaction
report_timing_summary -delay_type max -report_unconstrained -check_timing_verbose
report_timing -max_paths 50 -sort_by group
report_timing -delay_type min -max_paths 50
report_cdc
report_bus_skew
report_utilization
```

## What must be clean before you claim closure
- Zero unconstrained paths
- WNS >= 0 on setup
- WHS >= 0 on hold
- CDC report reviewed; async FIFO crossings waived/documented, unsafe crossings fixed
- No accidental false-path overuse
- Multicycle paths justified in README with source/destination logic explanation

## Interview-ready explanations
- Why setup failed on the SG-DMA write path
- Whether the bottleneck was fanout, routing, or combo depth
- What pipeline stage you added and what latency cost it introduced
- Why your CDC constraints are safe and not hiding real violations
