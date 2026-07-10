module uart_tx #(
    parameter int CLK_FREQ_HZ = 50_000_000,
    parameter int BAUD_RATE   = 115_200
) (
    input  logic       clk,
    input  logic       rst_n,
    input  logic       tx_start,
    input  logic [7:0] tx_data,
    output logic       tx,
    output logic       busy,
    output logic       tx_done
);

    localparam int DIVISOR = CLK_FREQ_HZ / BAUD_RATE;
    localparam int CNT_W   = (DIVISOR <= 1) ? 1 : $clog2(DIVISOR);
    localparam logic [CNT_W-1:0] DIVISOR_M1 = CNT_W'(DIVISOR - 1);

    typedef enum logic [2:0] {IDLE, START, DATA, STOP, DONE} state_t;
    state_t state;

    logic [CNT_W-1:0] baud_cnt;
    logic             baud_tick;
    logic [2:0]       bit_idx;
    logic [7:0]       shreg;

    always_ff @(posedge clk or negedge rst_n) begin
        if (!rst_n) begin
            state     <= IDLE;
            baud_cnt  <= '0;
            baud_tick <= 1'b0;
            bit_idx   <= '0;
            shreg     <= '0;
            tx        <= 1'b1;
            busy      <= 1'b0;
            tx_done   <= 1'b0;
        end else begin
            tx_done   <= 1'b0;
            baud_tick <= 1'b0;

            if (baud_cnt == DIVISOR_M1) begin
                baud_cnt  <= '0;
                baud_tick <= 1'b1;
            end else begin
                baud_cnt <= baud_cnt + 1'b1;
            end

            case (state)
                IDLE: begin
                    tx   <= 1'b1;
                    busy <= 1'b0;
                    if (tx_start) begin
                        state <= START;
                        busy  <= 1'b1;
                        shreg <= tx_data;
                    end
                end

                START: begin
                    if (baud_tick) begin
                        tx      <= 1'b0;
                        bit_idx <= 3'b000;
                        state   <= DATA;
                    end
                end

                DATA: begin
                    if (baud_tick) begin
                        tx    <= shreg[0];
                        shreg <= {1'b0, shreg[7:1]};
                        if (bit_idx == 3'd7) begin
                            state <= STOP;
                        end else begin
                            bit_idx <= bit_idx + 1'b1;
                        end
                    end
                end

                STOP: begin
                    if (baud_tick) begin
                        tx    <= 1'b1;
                        state <= DONE;
                    end
                end

                DONE: begin
                    tx_done <= 1'b1;
                    state   <= IDLE;
                end

                default: begin
                    state <= IDLE;
                end
            endcase
        end
    end

endmodule
