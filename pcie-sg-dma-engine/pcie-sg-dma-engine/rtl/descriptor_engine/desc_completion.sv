//==============================================================================
// desc_completion.sv
// Writes completion status back to the host-visible descriptor (or a
// separate completion ring, depending on WB_MODE). Also drives the
// interrupt-coalescing timer that feeds msix_ctrl.sv.
//==============================================================================
module desc_completion #(
    parameter int WB_INTR_TIMEOUT = 256   // cycles, matches design_decisions.md rationale
)(
    input  logic        clk,
    input  logic         rst_n,

    input  logic         writeback_req,     // from desc_fetch.sv
    input  logic         decode_error,
    input  logic         xfer_error,
    output logic         writeback_done,

    // Writeback target address (completion status word location in host memory)
    // Typically desc_base_addr + descriptor_offset + status_field_offset
    input  logic [63:0]  wb_target_addr,

    // Writeback TLP generation (memory write to host completion status word)
    output logic         wb_wr_req,
    output logic [63:0]  wb_wr_addr,
    output logic [31:0]  wb_wr_data,        // bit0=complete, bit1=error
    input  logic          wb_wr_ack,

    // Completion tracking for MSI-X coalescing
    output logic [15:0]  pending_completions,
    input  logic          msix_fire,          // clears pending count when fired

    // Interrupt coalescing timer control (feeds msix_ctrl.sv)
    output logic          wb_event_pulse,     // one pulse per completed descriptor
    output logic [31:0]   wb_intr_timeout_cfg
);

    typedef enum logic [1:0] {WB_IDLE, WB_ISSUE, WB_WAIT_ACK} wb_state_t;
    wb_state_t wb_state;

    logic [31:0] status_word;
    logic [15:0] pending_r;
    logic [63:0] wb_addr_r;

    assign wb_intr_timeout_cfg = WB_INTR_TIMEOUT;

    always_ff @(posedge clk or negedge rst_n) begin
        if (!rst_n) begin
            wb_state <= WB_IDLE;
            wb_addr_r <= '0;
        end else case (wb_state)
            WB_IDLE: begin
                if (writeback_req) begin
                    wb_state <= WB_ISSUE;
                    wb_addr_r <= wb_target_addr;
                end
            end
            WB_ISSUE:    wb_state <= WB_WAIT_ACK;
            WB_WAIT_ACK: if (wb_wr_ack) wb_state <= WB_IDLE;
            default:     wb_state <= WB_IDLE;
        endcase
    end

    assign wb_wr_req  = (wb_state == WB_ISSUE);
    assign wb_wr_addr = wb_addr_r;
    assign writeback_done = (wb_state == WB_WAIT_ACK) && wb_wr_ack;

    always_comb begin
        status_word    = 32'h0;
        status_word[0] = 1'b1;                        // complete bit (always set — attempt finished)
        status_word[1] = decode_error || xfer_error;   // error bit
    end

    assign wb_wr_data = status_word;

    assign wb_event_pulse = writeback_done;

    // Pending completion counter -- feeds MSI-X coalescing decision in msix_ctrl.sv
    always_ff @(posedge clk or negedge rst_n) begin
        if (!rst_n) pending_r <= '0;
        else if (writeback_done && !msix_fire) pending_r <= pending_r + 1'b1;
        else if (msix_fire && !writeback_done) pending_r <= '0;
        else if (msix_fire && writeback_done) pending_r <= 16'd1; // fire clears, then this one counts
    end

    assign pending_completions = pending_r;

endmodule
