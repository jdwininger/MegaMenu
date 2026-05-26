# Session Log - 2026-05-26

## Project

- Repo: https://github.com/jdwininger/MegaMenu
- Local path used in this session: `/Volumes/T7/Source/MegaMenu`
- Target: Sega Mega Drive/Genesis multi-ROM menu (SGDK C), 4MB FlashKit workflow.

## Current Git State

- Branch: `main`
- HEAD: `6a26c99`
- Recent commits:
  - `6a26c99` Remove macOS sidecar artifact and ignore AppleDouble files
  - `fc2da80` Initial SGDK MegaMenu scaffold

## What Was Created

- Project scaffold:
  - `src/`, `inc/`, `res/`, `tools/`, `docs/`, `.vscode/`, `.github/`
- Core code:
  - Menu loop and input handling (`src/menu.c`)
  - Program entry (`src/main.c`)
  - ROM table placeholders (`src/rom_table.c`, `inc/rom_table.h`)
  - Mapper launch hook stubs (`src/flashkit_mapper.c`, `inc/flashkit_mapper.h`)
- Build and docs:
  - SGDK Makefile (`Makefile`, default `GDK ?= /opt/sgdk`)
  - Build task (`.vscode/tasks.json`)
  - Setup and workflow docs (`README.md`, `docs/flashkit-4mb-notes.md`)
  - ROM list generator script (`tools/build_romlist.py`)
- Setup checklist tracking:
  - `.github/copilot-instructions.md` updated with step-by-step completion summaries.

## Known Blocker

Build is currently blocked because SGDK is not installed on this macOS machine at `/opt/sgdk`.

Observed failure:

```text
Makefile:10: /opt/sgdk/makefile.gen: No such file or directory
make: *** No rule to make target `/opt/sgdk/makefile.gen'.  Stop.
```

## Resume Plan (Windows Machine)

1. Clone repo and open workspace.
2. Install SGDK and set `GDK` to SGDK root path.
3. Run build task `SGDK Build MegaMenu` or run `make`.
4. Implement mapper-specific bank switching and jump logic in `src/flashkit_mapper.c`.
5. Replace placeholder entries in `src/rom_table.c` with real ROM offsets/sizes from packed 4MB image.
6. Build, test in emulator/hardware, and iterate on launch flow.

## Suggested First Commands on Windows

```sh
git clone https://github.com/jdwininger/MegaMenu.git
cd MegaMenu
set GDK=C:\path\to\sgdk
make
```

(If using PowerShell, use `$env:GDK="C:\path\to\sgdk"`.)

## Notes for Next Model

- Launch step is intentionally still pending in `.github/copilot-instructions.md` until SGDK build succeeds.
- Project was moved from a path containing spaces to avoid SGDK path/include issues.
- AppleDouble sidecar files are now ignored via `.gitignore` entry `._*`.
