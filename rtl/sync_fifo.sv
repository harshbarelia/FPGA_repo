module sync_fifo #(
    parameter int DATA_W = 8,
    parameter int DEPTH  = 16,
    parameter int ADDR_W = $clog2(DEPTH)
) (
    input  logic              clk,
    input  logic              rst_n,
    input  logic              wr_en,
    input  logic [DATA_W-1:0] in_data,
    input  logic              rd_en,
    output logic [DATA_W-1:0] out_data,
    output logic              full,
    output logic              empty
);

    logic [DATA_W-1:0] mem [0:DEPTH-1];
    logic [ADDR_W:0] wr_ptr;
    logic [ADDR_W:0] rd_ptr;

    always_ff @(posedge clk or negedge rst_n) begin
        if (!rst_n) begin
            wr_ptr <= '0;
        end else if (wr_en && !full) begin
            mem[wr_ptr[ADDR_W-1:0]] <= in_data;
            wr_ptr <= wr_ptr + 1'b1;
        end
    end

    always_ff @(posedge clk or negedge rst_n) begin
        if (!rst_n) begin
            rd_ptr   <= '0;
            out_data <= '0;
        end else if (rd_en && !empty) begin
            out_data <= mem[rd_ptr[ADDR_W-1:0]];
            rd_ptr   <= rd_ptr + 1'b1;
        end
    end

    assign empty = (wr_ptr == rd_ptr);
    assign full  = (wr_ptr[ADDR_W] != rd_ptr[ADDR_W]) &&
                   (wr_ptr[ADDR_W-1:0] == rd_ptr[ADDR_W-1:0]);

endmodule
