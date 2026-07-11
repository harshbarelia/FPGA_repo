module uart_top_csr #(
    parameter int CLK_FREQ_HZ = 1_000_000,
    parameter int BAUD_RATE   = 100_000
) (
    input  logic        clk,
    input  logic        rst_n,

    input  logic         wr_en,
    input  logic [3:0]   wstrb,
    input  logic [3:0]   addr,
    input  logic [31:0]  wdata,
    input  logic         rd_en,
    output logic [31:0]  rdata,

    output logic tx_serial,
    input  logic rx_serial
);

    logic       tx_start;
    logic [7:0] tx_data;
    logic       tx_busy;
    logic       tx_done;

    logic [7:0] rx_data;
    logic       rx_valid;
    logic       framing_error;

    uart_csr u_csr (
        .clk(clk),
        .rst_n(rst_n),
        .wr_en(wr_en),
        .wstrb(wstrb),
        .addr(addr),
        .wdata(wdata),
        .rd_en(rd_en),
        .rdata(rdata),
        .tx_start(tx_start),
        .tx_data(tx_data),
        .tx_busy(tx_busy),
        .tx_done(tx_done),
        .rx_data_in(rx_data),
        .rx_valid_in(rx_valid),
        .framing_error_in(framing_error)
    );

    uart_tx #(
        .CLK_FREQ_HZ(CLK_FREQ_HZ),
        .BAUD_RATE(BAUD_RATE)
    ) u_tx (
        .clk(clk),
        .rst_n(rst_n),
        .tx_start(tx_start),
        .tx_data(tx_data),
        .tx(tx_serial),
        .busy(tx_busy),
        .tx_done(tx_done)
    );

    uart_rx #(
        .CLK_FREQ_HZ(CLK_FREQ_HZ),
        .BAUD_RATE(BAUD_RATE)
    ) u_rx (
        .clk(clk),
        .rst_n(rst_n),
        .rx(rx_serial),
        .rx_data(rx_data),
        .rx_valid(rx_valid),
        .framing_error(framing_error)
    );

endmodule
