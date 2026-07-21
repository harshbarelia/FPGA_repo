# UVM Plan

## Testbench structure
- `dma_if.sv`      : virtual interface for descriptor push and payload stream driving
- `dma_seq_item.sv`: descriptor + payload transaction object
- `dma_driver.sv`  : drives descriptors and payload beats into DUT
- `dma_monitor.sv` : observes accepted descriptors
- `dma_scoreboard.sv`: checks alignment and zero-length violations, counts coverage hooks
- `dma_basic_seq.sv`: random descriptor smoke test
- `dma_wrap_seq.sv` : stresses ring wraparound with > RING_DEPTH transactions
- `dma_env.sv` / `dma_test.sv`: environment and top-level test

## Next verification additions
- Functional coverage for descriptor length bins, address alignment classes, ring occupancy levels
- Scoreboard correlation of pushed descriptors to `dma_done_irq` completions
- Error injection: backpressure, malformed descriptors, short payload, premature `tlast`
- Bind `sva_assertions.sv` into the DUT hierarchy in the simulator command line
