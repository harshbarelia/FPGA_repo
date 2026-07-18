# Driver Stub

This is a UIO-based userspace driver stub, not a production kernel driver.
It demonstrates BAR0 mapping, register read/write, and triggering a single
DMA descriptor -- the minimum needed to prove you understand the hardware/
software boundary, which is explicitly called out in PCIe/NVMe firmware and
AWS FPGA-accelerator job postings.

## What is real vs. what is a placeholder here

Real:
- BAR0 mmap via UIO resource file
- Register offset layout matching `docs/interface_spec.md`
- Descriptor struct layout matching `desc_fetch.sv` DECODE bit fields

Placeholder / broken on real hardware:
- Descriptor ring physical address (malloc'd memory is not DMA-safe or
  physically contiguous -- see comment block in `pcie_dma_uio.c`)
- No interrupt handling (UIO supports blocking read() on the uio device
  node for interrupts -- not implemented here, add it as your next step)
- No error handling for partial mmap failures, device hot-unplug, etc.

## Next Steps to Make This Real

1. Switch to VFIO (`/dev/vfio/`) instead of UIO for proper IOMMU-backed DMA
   buffer allocation with a real IOVA, OR write a minimal kernel module
   using `dma_alloc_coherent()` for the descriptor ring and data buffers.
2. Add interrupt handling: UIO exposes interrupts via blocking `read()` on
   `/dev/uioX` -- poll or thread this instead of the `usleep` polling loop
   currently in `main()`.
3. Add a `libdma` wrapper (separate .c/.h pair) so this becomes a reusable
   library instead of a single-shot demo program -- useful for building an
   actual benchmark harness that measures real latency from userspace,
   which is the number you want in `sim_results/latency_measurements.csv`'s
   hardware-validated counterpart.

## Honest Status

This has NOT been run against real hardware. It has not even been compiled
and tested against a mock BAR (e.g. via a QEMU PCIe device model). Treat it
as a structurally-informed starting point, not a working driver.
