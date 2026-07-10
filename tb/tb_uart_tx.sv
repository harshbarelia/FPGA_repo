module tb_uart_tx;

    localparam int CLK_FREQ_HZ = 50_000_000;
    localparam int BAUD_RATE   = 115_200;
    localparam int DIVISOR     = CLK_FREQ_HZ / BAUD_RATE;

    logic clk = 0;
    logic rst_n;
    logic tx_start;
    logic [7:0] tx_data;
    logic tx;
    logic busy;
    logic tx_done;

    uart_tx #(
        .CLK_FREQ_HZ(CLK_FREQ_HZ),
        .BAUD_RATE(BAUD_RATE)
    ) dut (
        .clk(clk),
        .rst_n(rst_n),
        .tx_start(tx_start),
        .tx_data(tx_data),
        .tx(tx),
        .busy(busy),
        .tx_done(tx_done)
    );

    always #1 clk = ~clk;

    initial begin
        $dumpfile("tb_uart_tx.vcd");
        $dumpvars(0, tb_uart_tx);

        rst_n    = 1'b0;
        tx_start = 1'b0;
        tx_data  = 8'hA5;

        repeat (3) @(posedge clk);
        rst_n = 1'b1;

        @(posedge clk);
        tx_start = 1'b1;
        @(posedge clk);
        tx_start = 1'b0;

        repeat (DIVISOR * 12 + 20) @(posedge clk);
        $finish;
    end

endmodule
