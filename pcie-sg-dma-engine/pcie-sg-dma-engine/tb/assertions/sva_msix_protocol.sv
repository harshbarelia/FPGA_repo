//==============================================================================
// sva_msix_protocol.sv
// Bound into msix_ctrl.sv. Verifies coalescing timeout behavior and
// no-spurious-fire invariant.
//==============================================================================
module sva_msix_protocol #(
    parameter int TIMEOUT_WIDTH = 32
)(
    input logic clk, rst_n,
    input logic msix_fire,
    input logic [15:0] pending_completions,
    input logic [31:0] wb_intr_timeout_cfg,
    input logic wb_event_pulse
);

   property p_msix_fires_within_timeout;
    @(posedge clk) disable iff (!rst_n)
    $rose(wb_event_pulse) |-> ##[1:300] msix_fire;   // bound slightly above WB_INTR_TIMEOUT=256
endproperty
    a_msix_fires_within_timeout: assert property (p_msix_fires_within_timeout)
        else $error("MSI-X never fired after writeback event");

    property p_no_spurious_msix;
        @(posedge clk) disable iff (!rst_n)
        msix_fire |-> (pending_completions > 0);
    endproperty
    a_no_spurious_msix: assert property (p_no_spurious_msix)
        else $error("MSI-X fired with zero pending completions");

    covergroup cg_msix_trigger @(posedge clk);
        cp_fire: coverpoint msix_fire;
        cp_pending_at_fire: coverpoint pending_completions iff (msix_fire) {
            bins low  = {[1:4]};
            bins mid  = {[5:11]};
            bins high = {[12:$]};
        }
    endgroup

    cg_msix_trigger cg_inst = new();

endmodule
