module tb_uart_top;

    localparam int CLK_FREQ_HZ = 1_000_000;
    localparam int BAUD_RATE   = 100_000;
    localparam int DIVISOR     = CLK_FREQ_HZ / BAUD_RATE;

    logic clk = 0;
    logic rst_n;

    logic tx_start;
    logic [7:0] tx_data;
    logic tx_busy;
    logic tx_done;

    logic [7:0] rx_data;
    logic rx_valid;
    logic framing_error;

    logic tx_serial;
    logic rx_serial;

    uart_top #(
        .CLK_FREQ_HZ(CLK_FREQ_HZ),
        .BAUD_RATE(BAUD_RATE)
    ) dut (
        .clk(clk),
        .rst_n(rst_n),
        .tx_start(tx_start),
        .tx_data(tx_data),
        .tx_busy(tx_busy),
        .tx_done(tx_done),
        .rx_serial(rx_serial),
        .rx_data(rx_data),
        .rx_valid(rx_valid),
        .framing_error(framing_error),
        .tx_serial(tx_serial)
    );

    always #1 clk = ~clk;

    assign rx_serial = tx_serial;

    initial begin
        $dumpfile("tb_uart_top.vcd");
        $dumpvars(0, tb_uart_top);

        rst_n         = 1'b0;
        tx_start      = 1'b0;
        tx_data       = 8'h00;

        repeat (5) @(posedge clk);
        rst_n = 1'b1;

        @(posedge clk);
        tx_data  = 8'hA5;
        tx_start = 1'b1;
        @(posedge clk);
        tx_start = 1'b0;

        wait (rx_valid == 1'b1);
        if (rx_data != 8'hA5) begin
            $error("Loopback failed: expected 0xA5, got 0x%0h", rx_data);
        end
        if (framing_error) begin
            $error("Unexpected framing_error on valid frame");
        end

        repeat (DIVISOR * 2) @(posedge clk);

        @(posedge clk);
        tx_data  = 8'h3C;
        tx_start = 1'b1;
        @(posedge clk);
        tx_start = 1'b0;

        wait (rx_valid == 1'b1);
        if (rx_data != 8'h3C) begin
            $error("Loopback failed: expected 0x3C, got 0x%0h", rx_data);
        end
        if (framing_error) begin
            $error("Unexpected framing_error on valid frame");
        end

        repeat (DIVISOR * 4) @(posedge clk);
        $finish;
    end

endmodule
