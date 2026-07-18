//==============================================================================
// xfer_engine_stub.sv
// Loopback stub for testing the descriptor engine FSM end-to-end without
// needing the full TLP stack. Accepts dispatch, waits LATENCY_CYCLES, then
// signals xfer_done.
//==============================================================================
`timescale 1ns/1ps

module xfer_engine_stub #(
    parameter int LATENCY_CYCLES = 5
)(
    input  logic clk,
    input  logic rst_n,

    input  logic dispatch_valid,
    output logic dispatch_ack,
    output logic xfer_done,
    output logic xfer_error
);

    typedef enum logic [1:0] {STUB_IDLE, STUB_ACK, STUB_WAIT, STUB_DONE} stub_state_t;
    stub_state_t state;

    int wait_count;

    always_ff @(posedge clk or negedge rst_n) begin
        if (!rst_n) begin
            state      <= STUB_IDLE;
            wait_count <= 0;
        end else case (state)
            STUB_IDLE: begin
                if (dispatch_valid) state <= STUB_ACK;
                wait_count <= 0;
            end
            STUB_ACK: state <= STUB_WAIT;
            STUB_WAIT: begin
                if (wait_count >= LATENCY_CYCLES - 1)
                    state <= STUB_DONE;
                else
                    wait_count <= wait_count + 1;
            end
            STUB_DONE: state <= STUB_IDLE;
            default:   state <= STUB_IDLE;
        endcase
    end

    assign dispatch_ack = (state == STUB_ACK);
    assign xfer_done    = (state == STUB_DONE);
    assign xfer_error   = 1'b0;

endmodule
