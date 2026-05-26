# Session Log

This is the rolling handoff file for the MegaMenu project.

## Current Snapshot (2026-05-26)

- Repo: https://github.com/jdwininger/MegaMenu
- Branch: main
- Last verified commit at creation time: 8b80b03
- Platform status: macOS setup complete; compile deferred to Windows machine with SGDK installed.

### Completed

- SGDK C project scaffold created for Mega Drive multi-ROM menu.
- Starter menu loop and input handling implemented.
- ROM table placeholders added.
- FlashKit mapper launch stubs added for later hardware-specific implementation.
- VS Code build task created.
- Date-stamped handoff log added at docs/session-log-2026-05-26.md.

### Blockers

- Build cannot run without SGDK at configured GDK path.

### Next Actions

1. On Windows, install SGDK and set GDK environment variable.
2. Run make (or VS Code task SGDK Build MegaMenu).
3. Implement mapper-specific bank-switch and reset-vector jump logic in src/flashkit_mapper.c.
4. Replace ROM placeholders with final packed-image offsets/sizes in src/rom_table.c.
5. Validate in emulator and on FlashKit hardware.

## Update Template

When ending each future session, append a new section using this format:

### Snapshot (YYYY-MM-DD)

- Branch:
- HEAD:
- What changed:
- Open blockers:
- Next 1-3 actions:
