## Production Timing Constraints for PCIe DMA HFT Feed Handler
## Target FPGA Architecture: Xilinx UltraScale+ / Virtex-7 (300 MHz User Clock, 156.25 MHz 10G MAC Clock)

# Primary Clocks
create_clock -period 3.333 -name pcie_user_clk [get_ports clk]
create_clock -period 6.400 -name eth_rx_clk     [get_ports eth_rx_clk]

# Asynchronous Clock Domain Relationships
set_clock_groups -asynchronous \
  -group [get_clocks pcie_user_clk] \
  -group [get_clocks eth_rx_clk]

# Clock Domain Crossing (CDC) Datapath Constraints
# Constrain Gray-coded pointer crossings in descriptor ring buffer and async FIFOs
set_max_delay -datapath_only 3.333 -from [get_clocks eth_rx_clk] -to [get_clocks pcie_user_clk]
set_max_delay -datapath_only 3.333 -from [get_clocks pcie_user_clk] -to [get_clocks eth_rx_clk]

# Set Bus Skew for multi-bit Gray pointers across domains
set_bus_skew -max 1.500 -from [get_cells -hierarchical -filter {NAME =~ *wr_ptr_r*}] \
                        -to   [get_cells -hierarchical -filter {NAME =~ *rd_ptr_r*}]

# False Paths for static configuration CSR registers
set_false_path -from [get_cells -hierarchical -filter {NAME =~ *enable_filter*}]
set_false_path -from [get_cells -hierarchical -filter {NAME =~ *target_udp_dport*}]
