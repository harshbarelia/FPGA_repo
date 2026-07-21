class dma_driver extends uvm_driver #(dma_seq_item);
    `uvm_component_utils(dma_driver)
    virtual dma_if drv_vif;

    function new(string name = "dma_driver", uvm_component parent = null);
        super.new(name, parent);
    endfunction

    function void build_phase(uvm_phase phase);
        super.build_phase(phase);
        if (!uvm_config_db#(virtual dma_if)::get(this, "", "dma_vif", drv_vif))
            `uvm_fatal("NOVIF", "dma_if not set for dma_driver")
    endfunction

    task run_phase(uvm_phase phase);
        dma_seq_item req;
        drv_vif.push_valid  <= 0;
        drv_vif.s_axis_tvalid <= 0;
        drv_vif.s_axis_tlast  <= 0;
        forever begin
            seq_item_port.get_next_item(req);
            drive_descriptor(req);
            drive_payload(req);
            seq_item_port.item_done();
        end
    endtask

    task drive_descriptor(dma_seq_item req);
        @(posedge drv_vif.clk);
        drv_vif.push_data  <= req.pack_desc();
        drv_vif.push_valid <= 1;
        do @(posedge drv_vif.clk); while (!drv_vif.push_ready);
        drv_vif.push_valid <= 0;
    endtask

    task drive_payload(dma_seq_item req);
        foreach (req.payload_q[i]) begin
            @(posedge drv_vif.clk);
            drv_vif.s_axis_tdata  <= req.payload_q[i];
            drv_vif.s_axis_tvalid <= 1;
            drv_vif.s_axis_tlast  <= (i == req.payload_q.size()-1);
            do @(posedge drv_vif.clk); while (!drv_vif.s_axis_tready);
        end
        @(posedge drv_vif.clk);
        drv_vif.s_axis_tvalid <= 0;
        drv_vif.s_axis_tlast  <= 0;
    endtask
endclass
