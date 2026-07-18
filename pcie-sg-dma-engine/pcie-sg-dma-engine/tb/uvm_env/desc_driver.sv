//==============================================================================
// desc_driver.sv
// Drives desc_seq_item transactions onto the descriptor ring by writing
// descriptors into simulated host memory and advancing the insert pointer.
//==============================================================================
class desc_driver extends uvm_driver #(desc_seq_item);
    `uvm_component_utils(desc_driver)

    virtual desc_if vif;

    // Analysis port to broadcast driven items to the predictor
    uvm_analysis_port #(desc_seq_item) drv_ap;

    function new(string name, uvm_component parent);
        super.new(name, parent);
        drv_ap = new("drv_ap", this);
    endfunction

    function void build_phase(uvm_phase phase);
        super.build_phase(phase);
        if (!uvm_config_db#(virtual desc_if)::get(this, "", "vif", vif))
            `uvm_fatal("DRV", "Virtual interface not set -- did you forget uvm_config_db::set in the test/env?")
    endfunction

    task run_phase(uvm_phase phase);
        desc_seq_item item;

        // Wait for reset deassertion
        @(posedge vif.rst_n);
        @(posedge vif.clk);

        forever begin
            seq_item_port.get_next_item(item);

            // Pack descriptor into 256-bit format per interface_spec.md
            begin
                logic [255:0] desc_packed = '0;
                desc_packed[63:0]    = item.src_addr;
                desc_packed[127:64]  = item.dst_addr;
                desc_packed[159:128] = item.length;
                desc_packed[160]     = item.dir;
                desc_packed[162]     = item.irq_en;

                // Write into simulated host memory
                vif.write_host_mem(
                    vif.ring_base + ({48'd0, vif.cur_insert_idx[$clog2(128)-1:0]} * 32),
                    desc_packed
                );
            end

            // Advance insert pointer
            @(posedge vif.clk);
            vif.sw_insert_ptr_wr    <= vif.cur_insert_idx + 1;
            vif.sw_insert_ptr_wr_en <= 1;
            vif.cur_insert_idx      <= vif.cur_insert_idx + 1;
            @(posedge vif.clk);
            vif.sw_insert_ptr_wr_en <= 0;

            // Broadcast to predictor
            drv_ap.write(item);

            seq_item_port.item_done();
        end
    endtask
endclass
