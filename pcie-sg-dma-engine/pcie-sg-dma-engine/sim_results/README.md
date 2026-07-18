# Simulation Results

This directory should contain:
- `waveforms/*.png` -- exported from ModelSim/Riviera-PRO waveform viewer after running directed tests
- `logs/*.log` -- raw simulator transcript output, including SVA assertion pass/fail messages
- `latency_measurements.csv` -- cycle-accurate timestamps captured via `$time` at `dispatch_valid` and `xfer_done` in your testbench, exported to CSV

**Nothing in this directory currently contains real simulation output.**
The CSV placeholder makes this explicit rather than pretending otherwise.
Run the directed tests in `tb/directed/` through ModelSim or Riviera-PRO,
capture waveform screenshots and transcript logs, and replace these
placeholders before citing any numbers in your top-level README.

Example logging snippet to add to your testbench for latency capture:
```systemverilog
time t_dispatch, t_done;
always @(posedge dispatch_valid) t_dispatch = $time;
always @(posedge xfer_done) begin
    t_done = $time;
    $fdisplay(logfile, "%s,%0d,%0d,%0d,%0.1f", test_name, dir, length, (t_done-t_dispatch)/10, (t_done-t_dispatch)/1000.0);
end
```
