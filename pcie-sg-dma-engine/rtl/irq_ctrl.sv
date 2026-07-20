
// irq_ctrl.sv
// MSI-X interrupt controller. Fires an interrupt pulse whenever an
// H2C or C2H transfer completes (if IRQ_EN is set), and tallies
// total completed descriptors for the DESC_CNT status register.
module irq_ctrl (
    input  logic clk,
    input  logic rst_n,
    input  logic irq_enable,
    input  logic h2c_done,
    input  logic c2h_done,
    output logic msix_irq,
    output logic [31:0] desc_completed_cnt
);

    logic irq_pulse;
    assign irq_pulse = irq_enable & (h2c_done | c2h_done);

    always_ff @(posedge clk or negedge rst_n) begin
        if (!rst_n) begin
            msix_irq <= 1'b0;
            desc_completed_cnt <= 32'd0;
        end else begin
            msix_irq <= irq_pulse;
            if (h2c_done || c2h_done)
                desc_completed_cnt <= desc_completed_cnt + 1'b1;
        end
    end

endmodule : irq_ctrl
