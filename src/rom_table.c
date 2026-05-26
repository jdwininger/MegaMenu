#include "rom_table.h"

// Replace these placeholders with your actual game offsets within the 4MB image.
const RomEntry gRomTable[] = {
    {"Game 1", 0x080000, 0x100000, 0},
    {"Game 2", 0x180000, 0x100000, 0},
    {"Game 3", 0x280000, 0x100000, 0},
};

const u16 gRomCount = sizeof(gRomTable) / sizeof(gRomTable[0]);
