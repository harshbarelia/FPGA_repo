read_verilog ../rtl/descriptor_ring_buffer.sv
read_verilog ../rtl/sg_dma_engine.sv
read_xdc timing.xdc
synth_design -top sg_dma_engine -part xc7a200tfbg484-2
opt_design
place_design
phys_opt_design
route_design
report_timing_summary -file ../docs/timing_summary.rpt -delay_type max -report_unconstrained -check_timing_verbose
report_timing -file ../docs/setup_top50.rpt -max_paths 50 -sort_by group
report_timing -file ../docs/hold_top50.rpt -delay_type min -max_paths 50
report_clock_interaction -file ../docs/clock_interaction.rpt
report_cdc -file ../docs/cdc_report.rpt
report_utilization -file ../docs/utilization.rpt
