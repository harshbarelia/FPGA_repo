# Block Diagram (text form - redraw in draw.io / Excalidraw for GitHub README)

```
                 +----------------------+
 10GbE PHY ----->|  eth_udp_parser.sv   |---- RX timestamp -----+
                 +----------------------+                       |
                            |                                   v
                            v                          +-------------------+
                 +----------------------+               | latency_timestamp |
                 |  feed_handler_fsm    |               |      _unit        |
                 +----------------------+               +-------------------+
                            |                                   ^
                            v                                   |
                 +----------------------+                       |
                 |   sg_dma_engine.sv   |<--- descriptors -------+
                 +----------------------+
                            |
                            v
                 +----------------------+
                 |  AXI4 Master I/F     |
                 +----------------------+
                            |
                            v
                 +----------------------+
                 | PCIe TLP / XDMA Core |
                 +----------------------+
                            |
                            v
                    Host Memory (via
                  Linux kernel driver,
                    mmap'd to user)
```
