# Coverage

`coverage_report.html` is NOT included in this repo as a static file because
coverage reports are simulator-generated output, not source code. Fake or
hand-written coverage HTML is worse than no coverage report at all.

To generate it for real:

**ModelSim / QuestaSim:**
```
vsim -coverage -do "coverage save cov.ucdb; run -all; vcover report -html -htmldir cov_html cov.ucdb"
```

**Riviera-PRO:**
```
vsim -acdb -do "run -all; acdb report -html -o coverage_report.html"
```

Commit the generated `cov_html/` directory (or single HTML file) after you
actually run simulation with `+define+ENABLE_SVA` and the covergroups in
`covergroups.sv` and `sva_*.sv` included in your compile list.
