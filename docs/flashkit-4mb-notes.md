# 4MB Cartridge Layout Notes

This project targets a 4MB (0x400000 bytes) flash image.

## Suggested image map

- 0x000000-0x07FFFF: Menu ROM (this project)
- 0x080000-0x3FFFFF: Game payload area

Adjust the split to match menu size and game count.

## Launch flow

1. Menu reads selected `RomEntry` from `gRomTable`.
2. `FK_prepareLaunch()` stores launch metadata.
3. `FK_launchSelectedRom()` must configure mapper/bank registers.
4. Control jumps to selected ROM reset vector.

## Krikzz FlashKit workflow

- Build menu ROM with SGDK.
- Build or gather each target game ROM.
- Use an image pack step to place each ROM at the offsets listed in `src/rom_table.c`.
- Flash final 4MB image using FlashKit.

Mapper register writes are hardware-specific and intentionally left as TODO in `src/flashkit_mapper.c`.
