//==============================================================================
// covergroups.sv
// Top-level functional coverage rollup for the descriptor engine + DMA
// datapath, separate from the per-block covergroups already embedded in
// the bound SVA modules (sva_descriptor_invariants.sv, sva_msix_protocol.sv).
// This file focuses on end-to-end scenario coverage that spans multiple
// blocks -- e.g. "did a C2H and H2C transfer ever overlap in flight".
//==============================================================================
module top_coverage (
    input logic clk, rst_n,
    input logic [3:0] desc_fsm_state,
    input logic c2h_xfer_active,
    input logic h2c_xfer_active,
    input logic msix_fire,
    input logic decode_error
);

    covergroup cg_scenario @(posedge clk);
        cp_c2h_h2c_overlap: coverpoint {c2h_xfer_active, h2c_xfer_active} {
            bins c2h_only    = {2'b10};
            bins h2c_only    = {2'b01};
            bins both_active = {2'b11};   // proves engines don't serialize unnecessarily
            bins idle        = {2'b00};
        }
        cp_error_then_recovery: coverpoint decode_error {
            bins error_seen = {1};
        }
        cp_msix_during_error: coverpoint {msix_fire, decode_error} {
            bins fire_after_error = {2'b11};
        }
    endgroup

    cg_scenario cg_inst = new();

    // Run: after simulation, merge this with per-block coverage databases
    // (ModelSim: vcover merge, Riviera-PRO: acdb merge) into a single
    // coverage_report.html -- generate that with your simulator's coverage
    // report tool, do not hand-write an HTML file pretending to be real
    // coverage output.

endmodule
