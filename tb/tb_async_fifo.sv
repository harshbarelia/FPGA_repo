module tb_async_fifo;

    parameter int DATA_W = 8;
    parameter int DEPTH  = 16;
    parameter int ADDR_W = $clog2(DEPTH);

    logic wr_clk;
    logic rd_clk;
    logic wr_rst_n;
    logic rd_rst_n;
    logic wr_en;
    logic rd_en;
    logic [DATA_W-1:0] in_data;
    logic [DATA_W-1:0] out_data;
    logic full;
    logic empty;

    async_fifo #(
        .DATA_W(DATA_W),
        .DEPTH(DEPTH),
        .ADDR_W(ADDR_W)
    ) dut (
        .wr_clk(wr_clk),
        .wr_rst_n(wr_rst_n),
        .wr_en(wr_en),
        .in_data(in_data),
        .full(full),
        .rd_clk(rd_clk),
        .rd_rst_n(rd_rst_n),
        .rd_en(rd_en),
        .out_data(out_data),
        .empty(empty)
    );

    logic [DATA_W-1:0] model_q[$];

    initial begin
        wr_clk = 0;
        forever #5 wr_clk = ~wr_clk;
    end

    initial begin
        rd_clk = 0;
        forever #7 rd_clk = ~rd_clk;
    end

    task automatic reset_dut();
        wr_rst_n = 0;
        rd_rst_n = 0;
        wr_en    = 0;
        rd_en    = 0;
        in_data  = '0;
        model_q.delete();
        repeat (3) @(posedge wr_clk);
        repeat (3) @(posedge rd_clk);
        wr_rst_n = 1;
        rd_rst_n = 1;
        repeat (2) @(posedge wr_clk);
        repeat (2) @(posedge rd_clk);
    endtask

    task automatic write_data(input logic [DATA_W-1:0] data);
        @(posedge wr_clk);
        if (!full) begin
            wr_en   = 1;
            in_data = data;
            model_q.push_back(data);
        end else begin
            wr_en = 0;
        end
        @(posedge wr_clk);
        wr_en = 0;
    endtask

    task automatic read_data();
        logic [DATA_W-1:0] exp;
        bit do_compare;
        @(posedge rd_clk);
        do_compare = 0;
        if (!empty) begin
            rd_en = 1;
            if (model_q.size() > 0) begin
                exp = model_q.pop_front();
                do_compare = 1;
            end
        end else begin
            rd_en = 0;
        end
        @(posedge rd_clk);
        if (do_compare && out_data !== exp)
            $error("DATA MISMATCH time=%0t exp=%0h got=%0h", $time, exp, out_data);
        rd_en = 0;
    endtask

    initial begin
        reset_dut();

        write_data(8'h11);
        write_data(8'h22);
        write_data(8'h33);

        read_data();
        read_data();

        repeat (DEPTH) write_data($urandom_range(0, 255));
        repeat (DEPTH) read_data();

        $finish;
    end

endmodule
