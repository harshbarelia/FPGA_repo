class dma_monitor extends uvm_component;
    `uvm_component_utils(dma_monitor)
    virtual dma_if mon_vif;
    uvm_analysis_port #(dma_seq_item) ap;

    function new(string name = "dma_monitor", uvm_component parent = null);
        super.new(name, parent);
        ap = new("ap", this);
    endfunction

    function void build_phase(uvm_phase phase);
        super.build_phase(phase);
        if (!uvm_config_db#(virtual dma_if)::get(this, "", "dma_vif", mon_vif))
            `uvm_fatal("NOVIF", "dma_if not set for dma_monitor")
    endfunction

    task run_phase(uvm_phase phase);
        dma_seq_item item;
        forever begin
            @(posedge mon_vif.clk);
            if (mon_vif.push_valid && mon_vif.push_ready) begin
                item = dma_seq_item::type_id::create("item");
                {item.host_addr, item.byte_len, item.ctrl} = mon_vif.push_data;
                ap.write(item);
            end
        end
    endtask
endclass
