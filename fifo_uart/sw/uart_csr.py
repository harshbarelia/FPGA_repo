class MockMMIO:
    def __init__(self):
        self.regs = {}

    def write(self, offset, value):
        self.regs[offset] = value & 0xFFFFFFFF

    def read(self, offset):
        return self.regs.get(offset, 0)


class UARTCSR:
    CTRL    = 0x00
    STATUS  = 0x04
    TX_DATA = 0x08
    RX_DATA = 0x0C

    CTRL_RX_ENABLE = 1 << 1

    STATUS_TX_BUSY     = 1 << 0
    STATUS_TX_FULL     = 1 << 1
    STATUS_TX_EMPTY    = 1 << 2
    STATUS_RX_FULL     = 1 << 3
    STATUS_RX_EMPTY    = 1 << 4
    STATUS_FRAMING_ERR = 1 << 5

    def __init__(self, mmio):
        self.mmio = mmio

    def write_reg(self, offset, value):
        self.mmio.write(offset, value & 0xFFFFFFFF)

    def read_reg(self, offset):
        return self.mmio.read(offset) & 0xFFFFFFFF

    def enable_rx(self, enable=True):
        ctrl = self.read_reg(self.CTRL)
        if enable:
            ctrl |= self.CTRL_RX_ENABLE
        else:
            ctrl &= ~self.CTRL_RX_ENABLE
        self.write_reg(self.CTRL, ctrl)

    def send_byte(self, value):
        self.write_reg(self.TX_DATA, value & 0xFF)

    def tx_busy(self):
        return bool(self.read_reg(self.STATUS) & self.STATUS_TX_BUSY)

    def tx_full(self):
        return bool(self.read_reg(self.STATUS) & self.STATUS_TX_FULL)

    def tx_empty(self):
        return bool(self.read_reg(self.STATUS) & self.STATUS_TX_EMPTY)

    def rx_full(self):
        return bool(self.read_reg(self.STATUS) & self.STATUS_RX_FULL)

    def rx_empty(self):
        return bool(self.read_reg(self.STATUS) & self.STATUS_RX_EMPTY)

    def framing_error(self):
        return bool(self.read_reg(self.STATUS) & self.STATUS_FRAMING_ERR)

    def read_rx_byte(self):
        return self.read_reg(self.RX_DATA) & 0xFF
