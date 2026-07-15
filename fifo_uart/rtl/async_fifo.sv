module async_fifo #(
    parameter int DATA_W = 8,
    parameter int DEPTH  = 16,
    parameter int ADDR_W = $clog2(DEPTH)
) (
    input  logic              wr_clk,
    input  logic              wr_rst_n,
    input  logic              wr_en,
    input  logic [DATA_W-1:0] in_data,
    output logic              full,
    input  logic              rd_clk,
    input  logic              rd_rst_n,
    input  logic              rd_en,
    output logic [DATA_W-1:0] out_data,
    output logic              empty
);

    logic [DATA_W-1:0] mem [0:DEPTH-1];

    logic [ADDR_W:0] wr_ptr_bin, wr_ptr_bin_next;
    logic [ADDR_W:0] rd_ptr_bin, rd_ptr_bin_next;
    logic [ADDR_W:0] wr_ptr_gray, wr_ptr_gray_next;
    logic [ADDR_W:0] rd_ptr_gray, rd_ptr_gray_next;
    logic [ADDR_W:0] wr_ptr_gray_sync1, wr_ptr_gray_sync2;
    logic [ADDR_W:0] rd_ptr_gray_sync1, rd_ptr_gray_sync2;

    function automatic logic [ADDR_W:0] bin2gray(input logic [ADDR_W:0] bin);
        return (bin >> 1) ^ bin;
    endfunction

    assign wr_ptr_bin_next  = wr_ptr_bin + ((wr_en && !full) ? 5'b1 : 5'b0);
    assign rd_ptr_bin_next  = rd_ptr_bin + ((rd_en && !empty) ? 5'b1 : 5'b0);
    assign wr_ptr_gray_next = bin2gray(wr_ptr_bin_next);
    assign rd_ptr_gray_next = bin2gray(rd_ptr_bin_next);

    always_ff @(posedge wr_clk or negedge wr_rst_n) begin
        if (!wr_rst_n) begin
            wr_ptr_bin  <= '0;
            wr_ptr_gray <= '0;
        end else if (wr_en && !full) begin
            mem[wr_ptr_bin[ADDR_W-1:0]] <= in_data;
            wr_ptr_bin  <= wr_ptr_bin_next;
            wr_ptr_gray <= wr_ptr_gray_next;
        end
    end

    always_ff @(posedge rd_clk or negedge rd_rst_n) begin
        if (!rd_rst_n) begin
            rd_ptr_bin  <= '0;
            rd_ptr_gray <= '0;
            out_data    <= '0;
        end else if (rd_en && !empty) begin
            out_data    <= mem[rd_ptr_bin[ADDR_W-1:0]];
            rd_ptr_bin  <= rd_ptr_bin_next;
            rd_ptr_gray <= rd_ptr_gray_next;
        end
    end

    always_ff @(posedge wr_clk or negedge wr_rst_n) begin
        if (!wr_rst_n) begin
            rd_ptr_gray_sync1 <= '0;
            rd_ptr_gray_sync2 <= '0;
        end else begin
            rd_ptr_gray_sync1 <= rd_ptr_gray;
            rd_ptr_gray_sync2 <= rd_ptr_gray_sync1;
        end
    end

    always_ff @(posedge rd_clk or negedge rd_rst_n) begin
        if (!rd_rst_n) begin
            wr_ptr_gray_sync1 <= '0;
            wr_ptr_gray_sync2 <= '0;
        end else begin
            wr_ptr_gray_sync1 <= wr_ptr_gray;
            wr_ptr_gray_sync2 <= wr_ptr_gray_sync1;
        end
    end

    assign empty = (wr_ptr_gray_sync2 == rd_ptr_gray);
    assign full  = (wr_ptr_gray == {~rd_ptr_gray_sync2[ADDR_W:ADDR_W-1],
                                         rd_ptr_gray_sync2[ADDR_W-2:0]});

endmodule
