# Design Decisions and Tradeoffs

## Scatter-Gather Ring vs Simple Linked-List Descriptor Chain

Chose a fixed-depth circular ring (128 entries) over a linked-list-style
descriptor chain (like Xilinx AXI DMA's SG mode with next-descriptor
pointers). Ring is simpler to implement in hardware (fixed-size BRAM,
no pointer-chasing fetch logic) and matches Altera SSGDMA's approach. Cost:
ring depth is fixed at synthesis time; if software needs more than 128
outstanding descriptors, it must wait for drain, whereas a linked chain can
grow dynamically in host memory. For a 128-entry ring at expected descriptor
rates, this was judged an acceptable tradeoff -- but this is a real
architectural bet that should be revisited if profiling shows ring-full
stalls in practice.

## Ring Depth Sizing (128 entries)

128 was chosen as a starting point matching common IP defaults, not derived
from actual latency/throughput analysis for this specific design. Before
calling this "production-ready," profile actual descriptor arrival rates
under your target HFT workload and resize based on measured occupancy
(see `sim_results/latency_measurements.csv` once real numbers exist).

## MSI-X over Legacy INTx

MSI-X chosen because: (1) supports per-vector masking, needed for
multi-queue extension later, (2) avoids the shared-interrupt-line ambiguity
of legacy INTx, (3) it's the only interrupt mechanism the target job
postings explicitly mention. Cost: more registers to implement
(`msix_table.sv`), more host-driver-side setup complexity (see
`sw/driver_stub`).

## Interrupt Coalescing: Timeout vs Immediate-Fire

Chose a timeout-plus-force-fire-on-near-full scheme rather than fire-on-every-
completion. This trades a small amount of worst-case latency (up to
WB_INTR_TIMEOUT cycles) for significantly reduced interrupt rate under
sustained load, which matters for host CPU overhead in a real system. THE
DEFAULT TIMEOUT VALUE (256 cycles) IS UNTUNED -- it needs to be measured
against actual HFT latency budgets, not left at an arbitrary default, before
this claim is defensible in an interview.

## MPS = 256B Default

256B chosen as the safe default Max Payload Size compatible with most root
complexes without negotiation surprises. 512B would improve TLP efficiency
(less header overhead per byte) but requires confirming root complex support
via PCIe config space capability negotiation, which is NOT implemented in
this repo (`tlp_generator.sv` assumes a fixed MPS, doesn't read it from
config space). This is a real gap, not a stylistic choice.

## Known Unimplemented Items (do not claim these are done)

- TLP request arbiter across c2h_engine/h2c_engine/desc_fetch/desc_completion/msix_table sharing one tlp_generator
- Multi-beat TLP payload streaming in tlp_generator.sv (currently single-beat-per-TLP simplification)
- C2H pipelining across MPS chunks (currently fully serial per chunk -- throughput bottleneck)
- H2C multiple-outstanding-tag pipelining (currently one read request in flight at a time)
- PCIe config space MPS/MRRS negotiation readback
- desc_predictor.sv for the UVM scoreboard
- desc_if.sv virtual interface for the UVM driver/monitor
- Width conversion in axi4_stream_bridge.sv when core and PCIe AXIS widths differ
