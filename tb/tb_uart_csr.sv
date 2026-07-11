module tb_uart_csr;

    localparam int CLK_FREQ_HZ = 1_000_000;
    localparam int BAUD_RATE   = 100_000;
    localparam int DIVISOR     = CLK_FREQ_HZ / BAUD_RATE;

    logic clk = 0;
    logic rst_n;

    logic        wr_en;
    logic [3:0]  wstrb;
    logic [3:0]  addr;
    logic [31:0] wdata;
    logic        rd_en;
    logic [31:0] rdata;

    logic tx_serial;
    logic rx_serial;

    uart_top_csr #(
        .CLK_FREQ_HZ(CLK_FREQ_HZ),
        .BAUD_RATE(BAUD_RATE)
    ) dut (
        .clk(clk),
        .rst_n(rst_n),
        .wr_en(wr_en),
        .wstrb(wstrb),
        .addr(addr),
        .wdata(wdata),
        .rd_en(rd_en),
        .rdata(rdata),
        .tx_serial(tx_serial),
        .rx_serial(rx_serial)
    );

    assign rx_serial = tx_serial;

    always #1 clk = ~clk;

    task automatic reg_write(input [3:0] a, input [31:0] d);
        begin
            @(posedge clk);
            addr  = a;
            wdata = d;
            wstrb = 4'hF;
            wr_en = 1'b1;
            @(posedge clk);
            wr_en = 1'b0;
        end
    endtask

    task automatic reg_read(input [3:0] a, output [31:0] d);
        begin
            @(posedge clk);
            addr  = a;
            rd_en = 1'b1;
            @(posedge clk);
            d     = rdata;
            rd_en = 1'b0;
        end
    endtask

    logic [31:0] status_val;
    logic [31:0] rxdata_val;

    initial begin
        $dumpfile("tb_uart_csr.vcd");
        $dumpvars(0, tb_uart_csr);

        rst_n = 1'b0;
        wr_en = 1'b0;
        rd_en = 1'b0;
        wstrb = 4'h0;
        addr  = 4'h0;
        wdata = 32'h0;

        repeat (5) @(posedge clk);
        rst_n = 1'b1;

        reg_write(4'h8, 32'h0000_00A5);
        reg_write(4'h0, 32'h0000_0001);

        do begin
            reg_read(4'h4, status_val);
        end while (status_val[0] == 1'b1);

        do begin
            reg_read(4'h4, status_val);
        end while (status_val[1] == 1'b0);

        reg_read(4'hC, rxdata_val);

        if (rxdata_val[7:0] != 8'hA5) begin
            $error("CSR loopback failed: expected 0xA5, got 0x%0h", rxdata_val[7:0]);
        end else begin
            $display("CSR loopback PASSED: got 0x%0h", rxdata_val[7:0]);
        end

        if (status_val[2] == 1'b1) begin
            $error("Unexpected framing_error set");
        end

        reg_write(4'h4, 32'h0000_0006);
        reg_read(4'h4, status_val);
        if (status_val[2:1] != 2'b00) begin
            $error("STATUS bits did not clear: 0x%0h", status_val);
        end

        repeat (20) @(posedge clk);
        $finish;
    end

endmodule
