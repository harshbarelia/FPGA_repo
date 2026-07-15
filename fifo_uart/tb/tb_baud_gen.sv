module tb_baud_gen;

    parameter int CLK_FREQ_HZ = 50_000_000;
    parameter int BAUD_RATE   = 115_200;

    logic clk;
    logic rst_n;
    logic baud_tick;

    baud_gen #(
        .CLK_FREQ_HZ(CLK_FREQ_HZ),
        .BAUD_RATE(BAUD_RATE)
    ) dut (
        .clk(clk),
        .rst_n(rst_n),
        .baud_tick(baud_tick)
    );

    initial begin
        clk = 1'b0;
        forever #1 clk = ~clk;
    end

    initial begin
        $dumpfile("tb_baud_gen.vcd");
        $dumpvars(0, tb_baud_gen);

        rst_n = 1'b0;
        repeat (3) @(posedge clk);
        rst_n = 1'b1;

        repeat (600) @(posedge clk);
        $finish;
    end

endmodule
