# Front-End Parser Plan

The raw Ethernet/IPv4/UDP front end is intentionally strict in v1. The next
defensive-hardening step is to add explicit checksum and malformed-frame
handling to make failures visible and testable.

## Added hardening targets

- IPv4 header checksum validation.
- UDP length consistency checks.
- Explicit malformed-frame classifications (short Ethernet, short IPv4,
  short UDP, payload truncation).
- Byte-offset assertions in the parser unit testbench so the exact placement
  of Ethernet, IP, UDP, and ITCH bytes is checked directly.
- A malformed-frame test vector that deliberately violates header and length
  rules to prove errors are flagged rather than silently ignored.

## Integration goal

Once these checks pass, the parser can be treated as a reliable framing
boundary for the market-data pipeline rather than just a minimal extractor.
