//==============================================================================
// sva_descriptor_invariants.sv
// Bound (not instantiated) into desc_ring_mgr and desc_fetch via bind_all.sv.
// Encodes ring pointer, FSM, and completion/writeback ordering invariants.
//==============================================================================
module sva_descriptor_invariants #(
    parameter int RING_DEPTH = 128,
    parameter int PTR_WIDTH  = $clog2(RING_DEPTH) + 1
)(
    input logic clk, rst_n,
    input logic [PTR_WIDTH-1:0] insert_ptr, extract_ptr,
    input logic extract_valid, insert_ptr_update_dbg, extract_ptr_update_dbg,
    input logic [3:0] state_dbg,
    input logic decode_error, xfer_done, writeback_valid, writeback_done,
    input logic [31:0] desc_addr, desc_len
);

    // ---------------- Ring pointer invariants ----------------
    property p_no_ring_overflow;
        @(posedge clk) disable iff (!rst_n)
        (insert_ptr - extract_ptr) <= RING_DEPTH;
    endproperty
    a_no_ring_overflow: assert property (p_no_ring_overflow)
        else $error("RING OVERFLOW: insert_ptr=%0d extract_ptr=%0d", insert_ptr, extract_ptr);

    property p_no_extract_when_empty;
        @(posedge clk) disable iff (!rst_n)
        extract_valid |-> (insert_ptr != extract_ptr);
    endproperty
    a_no_extract_when_empty: assert property (p_no_extract_when_empty)
        else $error("EXTRACT UNDERFLOW: fetch attempted on empty ring");

    property p_insert_ptr_monotonic;
        @(posedge clk) disable iff (!rst_n)
        insert_ptr_update_dbg |=> (insert_ptr >= $past(insert_ptr));
    endproperty
    a_insert_ptr_monotonic: assert property (p_insert_ptr_monotonic)
        else $error("insert_ptr decreased illegally");

    property p_extract_ptr_monotonic;
        @(posedge clk) disable iff (!rst_n)
        extract_ptr_update_dbg |=> (extract_ptr >= $past(extract_ptr));
    endproperty
    a_extract_ptr_monotonic: assert property (p_extract_ptr_monotonic)
        else $error("extract_ptr decreased illegally");

    // ---------------- FSM invariants ----------------
    property p_no_fetch_on_empty;
        @(posedge clk) disable iff (!rst_n)
        (state_dbg == 4'd1) |-> (insert_ptr != extract_ptr);  // FETCH == 4'd1
    endproperty
    a_no_fetch_on_empty: assert property (p_no_fetch_on_empty)
        else $error("FETCH issued with empty ring");

    property p_reject_invalid_length;
        @(posedge clk) disable iff (!rst_n)
        (state_dbg == 4'd3) |-> ((desc_len != 0) || decode_error);  // DECODE == 4'd3
    endproperty
    a_reject_invalid_length: assert property (p_reject_invalid_length)
        else $error("Zero length descriptor not flagged as error, len=%0d", desc_len);

    property p_legal_fsm_transition;
        @(posedge clk) disable iff (!rst_n)
        $changed(state_dbg) |-> $past(state_dbg) inside {4'd0,4'd1,4'd2,4'd3,4'd4,4'd5,4'd6,4'd7,4'd8};
    endproperty
    a_legal_fsm_transition: assert property (p_legal_fsm_transition)
        else $error("Illegal FSM state observed: %0d", $past(state_dbg));

    // ---------------- Completion / writeback ordering ----------------
    property p_writeback_after_xfer_done;
        @(posedge clk) disable iff (!rst_n)
        (writeback_valid && !decode_error) |-> (xfer_done || $past(xfer_done) || $past(xfer_done, 2) || $past(xfer_done, 3) || $past(xfer_done, 4));
    endproperty
    a_writeback_after_xfer_done: assert property (p_writeback_after_xfer_done)
        else $error("Writeback issued before transfer completion reported");

    // ---------------- Coverage (paired with assertions above) ----------------
    covergroup cg_ring_edge_cases @(posedge clk);
        cp_ring_occupancy: coverpoint (insert_ptr - extract_ptr) {
            bins low       = {[0:RING_DEPTH/4]};
            bins mid       = {[RING_DEPTH/4+1:3*RING_DEPTH/4]};
            bins near_full = {[3*RING_DEPTH/4+1:RING_DEPTH-1]};
            bins full      = {RING_DEPTH};
        }
        cp_wraparound: coverpoint insert_ptr[PTR_WIDTH-2:0] {
            bins wrap_point = {RING_DEPTH-1};
        }
        cp_decode_error: coverpoint decode_error;
        cp_fsm_state: coverpoint state_dbg {
            bins all_states[] = {[0:8]};
        }
        cross cp_ring_occupancy, cp_decode_error;
    endgroup

    cg_ring_edge_cases cg_inst = new();

endmodule
