module tb_sync_fifo;

    parameter int DATA_W = 8;
    parameter int DEPTH  = 16;
    parameter int ADDR_W = $clog2(DEPTH);

    logic clk;
    logic rst_n;
    logic wr_en;
    logic rd_en;
    logic [DATA_W-1:0] in_data;
    logic [DATA_W-1:0] out_data;
    logic full;
    logic empty;

    sync_fifo #(
        .DATA_W(DATA_W),
        .DEPTH(DEPTH),
        .ADDR_W(ADDR_W)
    ) dut (
        .clk(clk),
        .rst_n(rst_n),
        .wr_en(wr_en),
        .in_data(in_data),
        .rd_en(rd_en),
        .out_data(out_data),
        .full(full),
        .empty(empty)
    );

    logic [DATA_W-1:0] model_q[$];

    initial clk = 0;
    always #5 clk = ~clk;

    task automatic reset_dut();
        rst_n   = 0;
        wr_en   = 0;
        rd_en   = 0;
        in_data = '0;
        model_q.delete();
        repeat (3) @(posedge clk);
        rst_n = 1;
        repeat (1) @(posedge clk);
    endtask

    task automatic push(input logic [DATA_W-1:0] data);
        @(posedge clk);
        if (!full) begin
            wr_en   = 1;
            rd_en   = 0;
            in_data = data;
            model_q.push_back(data);
        end else begin
            wr_en = 0;
        end
        @(posedge clk);
        wr_en = 0;
    endtask

    task automatic pop();
        logic [DATA_W-1:0] exp;
        bit do_compare;
        @(posedge clk);
        do_compare = 0;
        if (!empty) begin
            wr_en = 0;
            rd_en = 1;
            if (model_q.size() > 0) begin
                exp = model_q.pop_front();
                do_compare = 1;
            end
        end else begin
            rd_en = 0;
        end
        @(posedge clk);
        if (do_compare && out_data !== exp)
            $error("DATA MISMATCH time=%0t exp=%0h got=%0h", $time, exp, out_data);
        rd_en = 0;
    endtask

    task automatic check_flags();
        if (empty !== (model_q.size() == 0))
            $error("EMPTY mismatch time=%0t exp=%0b got=%0b", $time, (model_q.size() == 0), empty);

        if (full !== (model_q.size() == DEPTH))
            $error("FULL mismatch time=%0t exp=%0b got=%0b", $time, (model_q.size() == DEPTH), full);
    endtask

    initial begin
        reset_dut();

        push(8'h11);
        push(8'h22);
        push(8'h33);
        check_flags();

        pop();
        pop();
        check_flags();

        repeat (DEPTH) push(8'($urandom_range(0, 255)));
        check_flags();

        repeat (DEPTH) pop();
        check_flags();

        $finish;
    end

endmodule
