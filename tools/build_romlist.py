#!/usr/bin/env python3
"""Generate a C ROM table from a JSON manifest.

Manifest format example:
[
  {"title": "Game 1", "offset": 524288, "size": 1048576, "flags": 0},
  {"title": "Game 2", "offset": 1572864, "size": 1048576, "flags": 0}
]
"""

import json
import sys
from pathlib import Path


def main() -> int:
    if len(sys.argv) != 3:
        print("usage: build_romlist.py <manifest.json> <output.c>")
        return 1

    manifest_path = Path(sys.argv[1])
    output_path = Path(sys.argv[2])

    entries = json.loads(manifest_path.read_text(encoding="utf-8"))

    lines = [
        '#include "rom_table.h"',
        "",
        "const RomEntry gRomTable[] = {",
    ]

    for row in entries:
        title = str(row["title"]).replace('"', '\\"')
        offset = int(row["offset"])
        size = int(row["size"])
        flags = int(row.get("flags", 0))
        lines.append(f'    {{"{title}", 0x{offset:06X}, 0x{size:06X}, {flags}}},')

    lines += [
        "};",
        "",
        "const u16 gRomCount = sizeof(gRomTable) / sizeof(gRomTable[0]);",
        "",
    ]

    output_path.write_text("\n".join(lines), encoding="utf-8")
    print(f"wrote {output_path}")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
