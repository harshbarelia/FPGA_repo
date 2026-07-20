
// dma_pkg.sv
// Common types/parameters for the custom PCIe DMA engine.
//
// INTERFACE: The PCIe hard IP on this platform exposes AXI4-LITE
// ONLY (no full AXI4 memory-mapped port). AXI4-Lite has:
//   - No burst support (no ARLEN/AWLEN) - every transaction moves
//     exactly one data beat.
//   - No transaction ID - only ONE outstanding read and ONE
//     outstanding write allowed at a time.
// H2C/C2H engines loop, issuing one single-beat AXI4-Lite read then
// one single-beat AXI4-Lite write per BEAT_BYTES chunk, advancing
// the address each iteration.
//
// MEMORY MAP: Host DDR (reached via PCIe) vs local on-chip BRAM.
// H2C moves data FROM host DDR INTO local BRAM.
// C2H moves data FROM local BRAM INTO host DDR.
// These are NOT the same memory - BRAM is small (tens of KB on
// typical Lattice devices) and lives at a distinct address range
// from host DDR.
package dma_pkg;

    parameter int AXI_ADDR_W   = 32;
    parameter int AXI_DATA_W   = 32; // AXI4-Lite data width
    parameter int BEAT_BYTES   = AXI_DATA_W / 8; // bytes moved per single-beat transaction
    parameter int DESC_BYTES   = 16; // bytes per descriptor slot (src,dst,len,ctrl @ 4B each)

    parameter int RING_IDX_W   = 10; // supports up to 1024 slots
    parameter int RING_PTR_W   = RING_IDX_W + 1; // extra bit disambiguates full vs empty

    // Host DDR vs local BRAM address regions (adjust to match your
    // actual PCIe BAR window and on-chip BRAM instance).
    parameter logic [31:0] HOST_DDR_BASE = 32'h0000_0000;
    parameter logic [31:0] HOST_DDR_SIZE = 32'h0100_0000; // 16MB addressable window example
    parameter logic [31:0] BRAM_BASE     = 32'h8000_0000; // local BRAM lives in upper address space
    parameter logic [31:0] BRAM_SIZE     = 32'h0001_0000; // 64KB local BRAM example - SIZE THIS TO YOUR ACTUAL BRAM

    typedef struct packed {
        logic [31:0] control;       // bit1=IRQ_EN, bit3=DIR(0=H2C,1=C2H)
        logic [31:0] length;
        logic [31:0] dst_addr;
        logic [31:0] src_addr;
    } dma_desc_t;

    typedef enum logic [2:0] {
        DMA_IDLE      = 3'd0,
        DMA_FETCH_DESC= 3'd1,
        DMA_DECODE    = 3'd2,
        DMA_XFER      = 3'd3,
        DMA_COMPLETE  = 3'd4,
        DMA_NEXT      = 3'd5,
        DMA_ERROR     = 3'd6
    } dma_state_t;

    function automatic logic [31:0] ring_slot_addr(
        input logic [31:0] ring_base,
        input logic [RING_PTR_W-1:0] ptr
    );
        logic [RING_IDX_W-1:0] slot_idx;
        begin
            slot_idx = ptr[RING_IDX_W-1:0];
            ring_slot_addr = ring_base + (slot_idx * DESC_BYTES);
        end
    endfunction

    function automatic logic ring_not_empty(
        input logic [RING_PTR_W-1:0] head,
        input logic [RING_PTR_W-1:0] tail
    );
        ring_not_empty = (head != tail);
    endfunction

    function automatic logic ring_full(
        input logic [RING_PTR_W-1:0] head,
        input logic [RING_PTR_W-1:0] tail,
        input logic [RING_IDX_W-1:0] ring_size
    );
        logic [RING_PTR_W-1:0] diff;
        begin
            diff = tail - head;
            ring_full = (diff == {1'b0, ring_size});
        end
    endfunction

    function automatic logic addr_in_bram(input logic [31:0] addr);
        addr_in_bram = (addr >= BRAM_BASE) && (addr < (BRAM_BASE + BRAM_SIZE));
    endfunction

    function automatic logic addr_in_host_ddr(input logic [31:0] addr);
        addr_in_host_ddr = (addr >= HOST_DDR_BASE) && (addr < (HOST_DDR_BASE + HOST_DDR_SIZE));
    endfunction

endpackage : dma_pkg
