//==============================================================================
// msix_ctrl.sv
// MSI-X interrupt controller with coalescing. Fires on WB_INTR_TIMEOUT
// expiry after a writeback event, OR immediately if the completion tracking
// FIFO (pending_completions) is near-full -- whichever comes first. This
// tradeoff is documented in docs/design_decisions.md.
//==============================================================================
module msix_ctrl #(
    parameter int TIMEOUT_WIDTH = 32,
    parameter int NEAR_FULL_THRESHOLD = 12   // out of e.g. 16-entry pending tracker
)(
    input  logic         clk,
    input  logic         rst_n,

    input  logic          wb_event_pulse,       // from desc_completion.sv, one pulse per completed descriptor
    input  logic [15:0]   pending_completions,
    input  logic [31:0]   wb_intr_timeout_cfg,  // WB_INTR_TIMEOUT register value

    output logic          msix_fire,
    output logic [7:0]    msix_vector_sel        // which MSI-X vector to fire, from msix_table.sv lookup
);

    logic [TIMEOUT_WIDTH-1:0] timer_r;
    logic                     timer_armed;
    logic                     near_full;

    assign near_full = (pending_completions >= NEAR_FULL_THRESHOLD);

    always_ff @(posedge clk or negedge rst_n) begin
        if (!rst_n) begin
            timer_r     <= '0;
            timer_armed <= 1'b0;
        end else if (wb_event_pulse && !timer_armed) begin
            timer_armed <= 1'b1;
            timer_r     <= '0;
        end else if (timer_armed) begin
            if (timer_r >= wb_intr_timeout_cfg || near_full) begin
                timer_armed <= 1'b0;
                timer_r     <= '0;
            end else begin
                timer_r <= timer_r + 1'b1;
            end
        end
    end

    assign msix_fire = timer_armed && ((timer_r >= wb_intr_timeout_cfg) || near_full);

    // Vector selection: simplified to a single fixed vector (0) here.
    // Production version should support per-queue vector mapping, indexed
    // by which descriptor queue generated the completion (relevant once
    // you extend beyond a single ring).
    assign msix_vector_sel = 8'd0;

endmodule
