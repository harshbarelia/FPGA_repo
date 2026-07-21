// Core SVA properties for the DMA engine / ring buffer.
// Bind these into descriptor_ring_buffer and sg_dma_engine during simulation.

module sva_assertions #(
    parameter int PTR_WIDTH = 9
)(
    input logic clk,
    input logic rst_n,
    input logic push_valid,
    input logic push_ready,
    input logic pop_valid,
    input logic pop_ready,
    input logic ring_full,
    input logic ring_empty,
    input logic [PTR_WIDTH-1:0] wr_ptr,
    input logic [PTR_WIDTH-1:0] rd_ptr
);

    // 1. Never push into a full ring
    property p_no_overrun;
        @(posedge clk) disable iff (!rst_n)
        ring_full |-> !(push_valid && push_ready);
    endproperty
    assert property (p_no_overrun) else $error("Ring overrun: push accepted while full");

    // 2. Never pop from an empty ring
    property p_no_underrun;
        @(posedge clk) disable iff (!rst_n)
        ring_empty |-> !(pop_valid && pop_ready);
    endproperty
    assert property (p_no_underrun) else $error("Ring underrun: pop accepted while empty");

    // 3. rd_ptr must never "lap" wr_ptr by more than RING_DEPTH (no phantom completions)
    property p_ptr_sane;
        @(posedge clk) disable iff (!rst_n)
        (wr_ptr - rd_ptr) <= (1 << (PTR_WIDTH-1));
    endproperty
    assert property (p_ptr_sane) else $error("Descriptor pointer inconsistency detected");

    // TODO: add descriptor-completion-ordering property once completion ring is implemented
    // TODO: add CDC handshake property for gray-coded pointer crossing (2-flop sync check)

endmodule
