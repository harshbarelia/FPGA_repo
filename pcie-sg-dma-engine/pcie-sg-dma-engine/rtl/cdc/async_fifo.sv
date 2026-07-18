//==============================================================================
// async_fifo.sv
// Gray-code pointer asynchronous FIFO for crossing between the core clock
// domain and the PCIe hard IP user clock domain. Used both as the wide
// data-path crossing (C2H/H2C payload) and can be instantiated narrow for
// single-bit status pulses (though a simple 2-flop synchronizer is cheaper
// for pure pulses -- see pulse_sync.sv).
//==============================================================================
module async_fifo #(
    parameter int DATA_WIDTH = 256,
    parameter int ADDR_WIDTH = 4          // 2^ADDR_WIDTH entries, e.g. 16-deep
)(
    input  logic                   wr_clk,
    input  logic                   wr_rst_n,
    input  logic                   wr_en,
    input  logic [DATA_WIDTH-1:0]  wr_data,
    output logic                   wr_full,

    input  logic                   rd_clk,
    input  logic                   rd_rst_n,
    input  logic                   rd_en,
    output logic [DATA_WIDTH-1:0]  rd_data,
    output logic                   rd_empty
);

    localparam int DEPTH = 1 << ADDR_WIDTH;

    logic [DATA_WIDTH-1:0] mem [0:DEPTH-1];

    logic [ADDR_WIDTH:0] wr_ptr_bin, wr_ptr_gray;
    logic [ADDR_WIDTH:0] rd_ptr_bin, rd_ptr_gray;

    logic [ADDR_WIDTH:0] wr_ptr_gray_sync1, wr_ptr_gray_sync2; // wr gray ptr synced into rd_clk
    logic [ADDR_WIDTH:0] rd_ptr_gray_sync1, rd_ptr_gray_sync2; // rd gray ptr synced into wr_clk

    function automatic logic [ADDR_WIDTH:0] bin2gray(logic [ADDR_WIDTH:0] b);
        return b ^ (b >> 1);
    endfunction

    // ---------------- Write domain ----------------
    always_ff @(posedge wr_clk or negedge wr_rst_n) begin
        if (!wr_rst_n) begin
            wr_ptr_bin  <= '0;
            wr_ptr_gray <= '0;
        end else if (wr_en && !wr_full) begin
            wr_ptr_bin  <= wr_ptr_bin + 1'b1;
            wr_ptr_gray <= bin2gray(wr_ptr_bin + 1'b1);
        end
    end

    always_ff @(posedge wr_clk) begin
        if (wr_en && !wr_full) mem[wr_ptr_bin[ADDR_WIDTH-1:0]] <= wr_data;
    end

    // Synchronize read pointer (Gray) into write clock domain
    always_ff @(posedge wr_clk or negedge wr_rst_n) begin
        if (!wr_rst_n) begin
            rd_ptr_gray_sync1 <= '0;
            rd_ptr_gray_sync2 <= '0;
        end else begin
            rd_ptr_gray_sync1 <= rd_ptr_gray;
            rd_ptr_gray_sync2 <= rd_ptr_gray_sync1;
        end
    end

    assign wr_full = (wr_ptr_gray[ADDR_WIDTH]   != rd_ptr_gray_sync2[ADDR_WIDTH]) &&
                      (wr_ptr_gray[ADDR_WIDTH-1] != rd_ptr_gray_sync2[ADDR_WIDTH-1]) &&
                      (wr_ptr_gray[ADDR_WIDTH-2:0] == rd_ptr_gray_sync2[ADDR_WIDTH-2:0]);
    // Standard Gray-code full comparison: MSB and MSB-1 differ, rest match.

    // ---------------- Read domain ----------------
    always_ff @(posedge rd_clk or negedge rd_rst_n) begin
        if (!rd_rst_n) begin
            rd_ptr_bin  <= '0;
            rd_ptr_gray <= '0;
        end else if (rd_en && !rd_empty) begin
            rd_ptr_bin  <= rd_ptr_bin + 1'b1;
            rd_ptr_gray <= bin2gray(rd_ptr_bin + 1'b1);
        end
    end

    assign rd_data = mem[rd_ptr_bin[ADDR_WIDTH-1:0]];

    // Synchronize write pointer (Gray) into read clock domain
    always_ff @(posedge rd_clk or negedge rd_rst_n) begin
        if (!rd_rst_n) begin
            wr_ptr_gray_sync1 <= '0;
            wr_ptr_gray_sync2 <= '0;
        end else begin
            wr_ptr_gray_sync1 <= wr_ptr_gray;
            wr_ptr_gray_sync2 <= wr_ptr_gray_sync1;
        end
    end

    assign rd_empty = (rd_ptr_gray == wr_ptr_gray_sync2);

endmodule
