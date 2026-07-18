//==============================================================================
// pulse_sync.sv
// Simple toggle-based pulse synchronizer for single-bit events crossing
// clock domains (e.g. MSI-X trigger, single completion pulse) where a full
// async FIFO would be overkill. Uses toggle + double-flop + edge-detect so
// pulses narrower than the destination clock period are never lost.
//==============================================================================
module pulse_sync (
    input  logic src_clk,
    input  logic src_rst_n,
    input  logic src_pulse,

    input  logic dst_clk,
    input  logic dst_rst_n,
    output logic dst_pulse
);

    logic toggle_r;
    logic sync1, sync2, sync3;

    always_ff @(posedge src_clk or negedge src_rst_n) begin
        if (!src_rst_n) toggle_r <= 1'b0;
        else if (src_pulse) toggle_r <= ~toggle_r;
    end

    always_ff @(posedge dst_clk or negedge dst_rst_n) begin
        if (!dst_rst_n) begin
            sync1 <= 1'b0; sync2 <= 1'b0; sync3 <= 1'b0;
        end else begin
            sync1 <= toggle_r;
            sync2 <= sync1;
            sync3 <= sync2;
        end
    end

    assign dst_pulse = sync2 ^ sync3;

endmodule
