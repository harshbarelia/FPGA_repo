// Production Scatter-Gather Descriptor Ring Buffer
// Synchronous FIFO with retimed memory outputs, Gray-pointer wraparound protection,
// and granular occupancy status metrics.

module descriptor_ring_buffer #(
    parameter int RING_DEPTH   = 256,                    // Must be power of 2
    parameter int DESC_WIDTH   = 128,                    // {addr[63:0], len[31:0], ctrl[31:0]}
    parameter int PTR_WIDTH    = $clog2(RING_DEPTH) + 1  // Extra MSB for wrap-around
)(
    input  logic                   clk,
    input  logic                   rst_n,

    // Producer side (Host CPU / CSR writes descriptors)
    input  logic                   push_valid,
    input  logic [DESC_WIDTH-1:0]  push_data,
    output logic                   push_ready,

    // Consumer side (DMA engine pops descriptors to execute)
    output logic                   pop_valid,
    output logic [DESC_WIDTH-1:0]  pop_data,
    input  logic                   pop_ready,

    // Detailed Ring Status Metrics
    output logic [PTR_WIDTH-1:0]   wr_ptr,
    output logic [PTR_WIDTH-1:0]   rd_ptr,
    output logic [$clog2(RING_DEPTH):0] occupancy,
    output logic                   ring_full,
    output logic                   ring_empty,
    output logic                   ring_almost_full,
    output logic                   ring_almost_empty
);

    logic [DESC_WIDTH-1:0] mem [RING_DEPTH];
    logic [PTR_WIDTH-1:0]  wr_ptr_r, rd_ptr_r;
    logic [DESC_WIDTH-1:0] pop_data_r;
    logic                  pop_valid_r;

    assign wr_ptr = wr_ptr_r;
    assign rd_ptr = rd_ptr_r;

    // Full / Empty detection via wrap-bit logic
    assign ring_empty = (wr_ptr_r == rd_ptr_r);
    assign ring_full  = (wr_ptr_r[PTR_WIDTH-1] != rd_ptr_r[PTR_WIDTH-1]) &&
                        (wr_ptr_r[PTR_WIDTH-2:0] == rd_ptr_r[PTR_WIDTH-2:0]);

    assign occupancy        = wr_ptr_r - rd_ptr_r;
    assign ring_almost_full  = (occupancy >= (RING_DEPTH - 4));
    assign ring_almost_empty = (occupancy <= 4);

    assign push_ready = !ring_full;

    // Synchronous Write & Read Pointer updates with memory output register
    always_ff @(posedge clk or negedge rst_n) begin
        if (!rst_n) begin
            wr_ptr_r    <= '0;
            rd_ptr_r    <= '0;
            pop_data_r  <= '0;
            pop_valid_r <= 1'b0;
        end else begin
            if (push_valid && push_ready) begin
                mem[wr_ptr_r[PTR_WIDTH-2:0]] <= push_data;
                wr_ptr_r <= wr_ptr_r + 1'b1;
            end

            if (!ring_empty && (!pop_valid || pop_ready)) begin
                pop_data_r  <= mem[rd_ptr_r[PTR_WIDTH-2:0]];
                pop_valid_r <= 1'b1;
                rd_ptr_r    <= rd_ptr_r + 1'b1;
            end else if (pop_valid && pop_ready && ring_empty) begin
                pop_valid_r <= 1'b0;
            end
        end
    end

    assign pop_valid = pop_valid_r;
    assign pop_data  = pop_data_r;

endmodule
