# Synthesis Results

`timing_summary.rpt` and `utilization.rpt` are simulator/synth-tool generated
outputs. They do not exist yet in this repo because the design has not been
run through synthesis.

**Vivado:**
```tcl
report_timing_summary -file synth/timing_summary.rpt
report_utilization -file synth/utilization.rpt
```

**Lattice Radiant:**
Use the Reports panel post-Map/Place-and-Route, export Timing Analysis and
Resource Usage reports to this directory with these filenames.

Do not commit hand-written or estimated numbers into these files. Commit the
actual tool-generated report text after running synthesis on your target
device (matching your Lattice Certus NX Pro board or whichever AMD/Xilinx
part you target for the PCIe hard IP).
