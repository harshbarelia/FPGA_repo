module uart_rx #(
    parameter int CLK_FREQ_HZ = 50_000_000,
    parameter int BAUD_RATE   = 115_200
) (
    input  logic       clk,
    input  logic       rst_n,
    input  logic       rx,
    output logic [7:0] rx_data,
    output logic       rx_valid,
    output logic       framing_error
);

    localparam int DIVISOR = CLK_FREQ_HZ / BAUD_RATE;
    localparam int CNT_W   = (DIVISOR <= 1) ? 1 : $clog2(DIVISOR);
    localparam logic [CNT_W-1:0] DIVISOR_M1 = CNT_W'(DIVISOR - 1);
    localparam logic [CNT_W-1:0] MID_COUNT   = CNT_W'(DIVISOR / 2);

    typedef enum logic [1:0] {IDLE, START, DATA, STOP} state_t;
    state_t state;

    logic [CNT_W-1:0] cnt;
    logic [2:0]       bit_idx;
    logic [7:0]       shreg;
    logic             rx_s1, rx_s2;

    always_ff @(posedge clk or negedge rst_n) begin
        if (!rst_n) begin
            state         <= IDLE;
            cnt           <= '0;
            bit_idx       <= '0;
            shreg         <= '0;
            rx_data       <= '0;
            rx_valid      <= 1'b0;
            framing_error <= 1'b0;
            rx_s1         <= 1'b1;
            rx_s2         <= 1'b1;
        end else begin
            rx_valid      <= 1'b0;
            framing_error <= 1'b0;

            rx_s1 <= rx;
            rx_s2 <= rx_s1;

            case (state)
                IDLE: begin
                    cnt     <= '0;
                    bit_idx <= '0;
                    if (!rx_s2) begin
                        state <= START;
                    end
                end

                START: begin
                    if (cnt == MID_COUNT) begin
                        if (!rx_s2) begin
                            cnt     <= '0;
                            bit_idx <= '0;
                            shreg   <= '0;
                            state   <= DATA;
                        end else begin
                            state <= IDLE;
                        end
                    end else begin
                        cnt <= cnt + 1'b1;
                    end
                end

                DATA: begin
                    if (cnt == DIVISOR_M1) begin
                        cnt   <= '0;
                        shreg <= {rx_s2, shreg[7:1]};
                        if (bit_idx == 3'd7) begin
                            state <= STOP;
                        end else begin
                            bit_idx <= bit_idx + 1'b1;
                        end
                    end else begin
                        cnt <= cnt + 1'b1;
                    end
                end

                STOP: begin
                    if (cnt == DIVISOR_M1) begin
                        cnt           <= '0;
                        rx_data       <= shreg;
                        rx_valid      <= 1'b1;
                        framing_error <= !rx_s2;
                        state         <= IDLE;
                    end else begin
                        cnt <= cnt + 1'b1;
                    end
                end

                default: begin
                    state <= IDLE;
                end
            endcase
        end
    end

endmodule
