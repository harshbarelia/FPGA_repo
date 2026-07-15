module tb_uart_rx;

    localparam int CLK_FREQ_HZ = 1_000_000;
    localparam int BAUD_RATE   = 100_000;
    localparam int DIVISOR     = CLK_FREQ_HZ / BAUD_RATE;

    logic clk = 0;
    logic rst_n;
    logic rx;
    logic [7:0] rx_data;
    logic rx_valid;
    logic framing_error;

    uart_rx #(
        .CLK_FREQ_HZ(CLK_FREQ_HZ),
        .BAUD_RATE(BAUD_RATE)
    ) dut (
        .clk(clk),
        .rst_n(rst_n),
        .rx(rx),
        .rx_data(rx_data),
        .rx_valid(rx_valid),
        .framing_error(framing_error)
    );

    always #1 clk = ~clk;

    task send_byte(input logic [7:0] b);
        integer i;
        begin
            rx = 1'b1;
            repeat (DIVISOR) @(posedge clk);

            rx = 1'b0;
            repeat (DIVISOR) @(posedge clk);

            for (i = 0; i < 8; i = i + 1) begin
                rx = b[i];
                repeat (DIVISOR) @(posedge clk);
            end

            rx = 1'b1;
            repeat (DIVISOR) @(posedge clk);
        end
    endtask

    initial begin
        $dumpfile("tb_uart_rx.vcd");
        $dumpvars(0, tb_uart_rx);

        rst_n = 1'b0;
        rx    = 1'b1;

        repeat (3) @(posedge clk);
        rst_n = 1'b1;

        send_byte(8'hA5);

        repeat (DIVISOR * 4) @(posedge clk);
        $finish;
    end

endmodule
