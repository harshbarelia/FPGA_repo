module uart_top #(
    parameter int CLK_FREQ_HZ = 1_000_000,
    parameter int BAUD_RATE   = 100_000
) (
    input  logic       clk,
    input  logic       rst_n,

    input  logic       tx_start,
    input  logic [7:0] tx_data,
    output logic       tx_busy,
    output logic       tx_done,

    input  logic       rx_serial,
    output logic [7:0] rx_data,
    output logic       rx_valid,
    output logic       framing_error,

    output logic       tx_serial
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
