# MegaMenu (Mega Drive Multi-ROM Starter)

Starter SGDK project for a Mega Drive/Genesis multi-ROM cartridge menu targeting a 4MB flash image for Krikzz FlashKit workflows.

## What is included

- Menu UI with D-Pad selection and A-button launch flow.
- ROM table placeholders in `src/rom_table.c`.
- Mapper launch hooks in `src/flashkit_mapper.c`.
- SGDK build config in `Makefile`.
- Helper script to generate ROM table entries from JSON.

## Folder layout

- `src/` C sources for menu, ROM list, and launch hooks.
- `inc/` Header files.
- `res/` SGDK resource definitions.
- `tools/` Utility scripts.
- `docs/` Hardware and image layout notes.

## Prerequisites (macOS)

1. Install SGDK in a path without spaces (recommended: `/opt/sgdk`).
2. Export `GDK` if your SGDK path differs from `/opt/sgdk`.

Example:

```sh
export GDK=/opt/sgdk
```

## Build

```sh
make
```

Output ROM is generated in `out/` and project root depending on SGDK version.

## Flash with Krikzz FlashKit

1. Build the menu ROM.
2. Pack menu + game ROM payloads into a single 4MB image.
3. Ensure offsets in `src/rom_table.c` match packed image offsets.
4. Flash final image with your FlashKit tool.

## Important TODO

Implement mapper-specific bank switching and jump logic in `src/flashkit_mapper.c` before attempting to boot payload games.

## Optional ROM table generation

Create a JSON manifest and run:

```sh
python3 tools/build_romlist.py rom_manifest.json src/rom_table.c
```
