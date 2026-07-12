module tb_uart_fifo_top;

    localparam int CLK_FREQ_HZ = 1_000_000;
    localparam int BAUD_RATE   = 100_000;
    localparam int CLK_PERIOD  = 2;
    localparam int BIT_CYCLES  = CLK_FREQ_HZ / BAUD_RATE;

    logic clk;
    logic rst_n;

    logic       tx_fifo_wr_en;
    logic [7:0] tx_fifo_din;
    logic       tx_fifo_full;
    logic       tx_fifo_empty;

    logic       rx_fifo_rd_en;
    logic [7:0] rx_fifo_dout;
    logic       rx_fifo_full;
    logic       rx_fifo_empty;

    logic       tx_busy;
    logic       framing_error;

    logic       tx_serial;
    logic       rx_serial;

    uart_fifo_top #(
        .CLK_FREQ_HZ(CLK_FREQ_HZ),
        .BAUD_RATE(BAUD_RATE),
        .FIFO_DEPTH(16)
    ) dut (
        .clk(clk),
        .rst_n(rst_n),
        .tx_fifo_wr_en(tx_fifo_wr_en),
        .tx_fifo_din(tx_fifo_din),
        .tx_fifo_full(tx_fifo_full),
        .tx_fifo_empty(tx_fifo_empty),
        .rx_fifo_rd_en(rx_fifo_rd_en),
        .rx_fifo_dout(rx_fifo_dout),
        .rx_fifo_full(rx_fifo_full),
        .rx_fifo_empty(rx_fifo_empty),
        .tx_busy(tx_busy),
        .framing_error(framing_error),
        .tx_serial(tx_serial),
        .rx_serial(rx_serial)
    );

    assign rx_serial = tx_serial;

    initial clk = 1'b0;
    always #(CLK_PERIOD/2) clk = ~clk;

    task automatic push_tx(input logic [7:0] data);
        begin
            wait (!tx_fifo_full);
            @(posedge clk);
            tx_fifo_din   = data;
            tx_fifo_wr_en = 1'b1;
            @(posedge clk);
            tx_fifo_wr_en = 1'b0;
            tx_fifo_din   = 8'h00;
            $display("[%0t] PUSH TX = 0x%02h", $time, data);
        end
    endtask

    task automatic wait_for_rx_data();
        int timeout_cycles;
        begin
            timeout_cycles = 0;
            while (rx_fifo_empty) begin
                @(posedge clk);
                timeout_cycles++;
                if (timeout_cycles > 20000) begin
                    $fatal(1, "[%0t] Timeout waiting for RX FIFO data", $time);
                end
            end
        end
    endtask

    task automatic pop_rx(output logic [7:0] data);
        begin
            wait_for_rx_data();
            rx_fifo_rd_en = 1'b1;
            @(posedge clk);
            data = rx_fifo_dout;
            rx_fifo_rd_en = 1'b0;
            $display("[%0t] POP RX  = 0x%02h", $time, data);
        end
    endtask

    task automatic check_rx(input logic [7:0] exp);
        logic [7:0] got;
        begin
            pop_rx(got);
            if (got !== exp) begin
                $fatal(1, "[%0t] RX CHECK FAIL expected=0x%02h got=0x%02h", $time, exp, got);
            end
            $display("[%0t] RX CHECK PASS expected=0x%02h got=0x%02h", $time, exp, got);
        end
    endtask

    always @(posedge clk) begin
        if (dut.rx_valid) begin
            $display("[%0t] rx_valid pulse data=0x%02h", $time, dut.rx_data);
        end
    end

    initial begin
        $dumpfile("tb_uart_fifo_top.vcd");
        $dumpvars(0, tb_uart_fifo_top);

        rst_n         = 1'b0;
        tx_fifo_wr_en = 1'b0;
        tx_fifo_din   = 8'h00;
        rx_fifo_rd_en = 1'b0;

        repeat (5) @(posedge clk);
        rst_n = 1'b1;
        $display("[%0t] Reset released", $time);

        push_tx(8'hA5);
        push_tx(8'h3C);
        push_tx(8'hF0);

        $display("[%0t] Skipping TX monitor; using RX checks instead", $time);

        check_rx(8'hA5);
        $display("[%0t] RX after first byte", $time);

        check_rx(8'h3C);
        $display("[%0t] RX after second byte", $time);

        check_rx(8'hF0);
        $display("[%0t] RX after third byte", $time);

        if (framing_error) begin
            $fatal(1, "[%0t] Unexpected framing_error asserted", $time);
        end

        $display("[%0t] UART FIFO loopback PASSED", $time);
        repeat (20) @(posedge clk);
        $finish;
    end

endmodule
