module tb_reset_sync;
    logic clk = 0;
    logic rst_in = 1;
    logic rst_out;

    reset_sync dut (
        .clk(clk),
        .arst_n(rst_in),
        .srst_n(rst_out)
    );

    always #5 clk = ~clk;

    initial begin
        $dumpfile("tb_reset_sync.vcd");
        $dumpvars(0, tb_reset_sync);

        repeat (3) @(posedge clk);
        rst_in = 0;
        repeat (5) @(posedge clk);
        $finish;
    end
endmodule
