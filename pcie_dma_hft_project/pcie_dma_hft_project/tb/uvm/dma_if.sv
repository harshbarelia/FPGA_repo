interface dma_if #(parameter int DESC_WIDTH = 128, parameter int DATA_WIDTH = 512) (input logic clk, input logic rst_n);
    logic                  push_valid;
    logic                  push_ready;
    logic [DESC_WIDTH-1:0] push_data;

    logic                  desc_pop_valid;
    logic                  desc_pop_ready;
    logic [DESC_WIDTH-1:0] desc_pop_data;

    logic [DATA_WIDTH-1:0] s_axis_tdata;
    logic                  s_axis_tvalid;
    logic                  s_axis_tready;
    logic                  s_axis_tlast;

    logic                  dma_done_irq;

    modport drv (
        input  clk, rst_n, push_ready, s_axis_tready,
        output push_valid, push_data, s_axis_tdata, s_axis_tvalid, s_axis_tlast
    );

    modport mon (
        input clk, rst_n, push_valid, push_ready, push_data,
              s_axis_tdata, s_axis_tvalid, s_axis_tready, s_axis_tlast,
              dma_done_irq, desc_pop_valid, desc_pop_ready, desc_pop_data
    );
endinterface
