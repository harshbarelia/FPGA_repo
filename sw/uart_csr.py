class MockMMIO:
    def __init__(self):
        self.regs = {}

    def write(self, offset, value):
        self.regs[offset] = value & 0xFFFFFFFF

    def read(self, offset):
        return self.regs.get(offset, 0)


class UARTCSR:
    CTRL   = 0x00
    STATUS = 0x04
    TX_DATA = 0x08
    RX_DATA = 0x0C

    CTRL_TX_START = 1 << 0
    CTRL_RX_ENABLE = 1 << 1

    STATUS_TX_BUSY = 1 << 0
    STATUS_RX_VALID = 1 << 1
    STATUS_FRAMING_ERR = 1 << 2

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
        ctrl = self.read_reg(self.CTRL)
        ctrl |= self.CTRL_TX_START
        self.write_reg(self.CTRL, ctrl)

    def tx_busy(self):
        return bool(self.read_reg(self.STATUS) & self.STATUS_TX_BUSY)

    def rx_valid(self):
        return bool(self.read_reg(self.STATUS) & self.STATUS_RX_VALID)

    def framing_error(self):
        return bool(self.read_reg(self.STATUS) & self.STATUS_FRAMING_ERR)

    def read_rx_byte(self):
        return self.read_reg(self.RX_DATA) & 0xFF

    def clear_rx_valid(self):
        self.write_reg(self.STATUS, self.STATUS_RX_VALID)

    def clear_framing_error(self):
        self.write_reg(self.STATUS, self.STATUS_FRAMING_ERR)

    def clear_status(self):
        self.write_reg(self.STATUS, self.STATUS_RX_VALID | self.STATUS_FRAMING_ERR)


if __name__ == "__main__":
    mmio = MockMMIO()
    uart = UARTCSR(mmio)

    uart.enable_rx(True)
    uart.send_byte(0xA5)

    print(f"CTRL   = 0x{uart.read_reg(UARTCSR.CTRL):08X}")
    print(f"TX_DATA = 0x{uart.read_reg(UARTCSR.TX_DATA):08X}")
    print("This is a software register helper example; real TX/RX status changes come from hardware.")
