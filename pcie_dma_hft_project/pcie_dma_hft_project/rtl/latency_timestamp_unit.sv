// High-Precision Free-Running Nanosecond Timestamp Unit
// Generates a 64-bit nanosecond-granularity hardware timestamp for packet-in to DMA-complete latency.

module latency_timestamp_unit #(
    parameter int TS_WIDTH       = 64,
    parameter int CLK_FREQ_MHZ   = 300  // 300MHz -> ~3.333ns per cycle
)(
    input  logic                clk,
    input  logic                rst_n,
    output logic [TS_WIDTH-1:0] free_run_ts,
    output logic [TS_WIDTH-1:0] free_run_ns
);

    logic [TS_WIDTH-1:0] ts_counter;
    logic [31:0]         ns_accumulator;

    always_ff @(posedge clk or negedge rst_n) begin
        if (!rst_n) begin
            ts_counter     <= '0;
            ns_accumulator <= '0;
            free_run_ns    <= '0;
        end else begin
            ts_counter <= ts_counter + 1'b1;

            // Increment nanosecond counter by fixed point step (3.333ns per tick at 300MHz)
            // 3.333 * 1000 = 3333 picoseconds
            if (ns_accumulator >= 1000) begin
                free_run_ns    <= free_run_ns + 3; // +3ns
                ns_accumulator <= ns_accumulator - 1000 + 333;
            end else begin
                ns_accumulator <= ns_accumulator + 333;
                free_run_ns    <= free_run_ns + 3;
            end
        end
    end

    assign free_run_ts = ts_counter;

endmodule
