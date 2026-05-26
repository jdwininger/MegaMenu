#ifndef ROM_TABLE_H
#define ROM_TABLE_H

#include <genesis.h>

typedef struct
{
    const char *title;
    u32 romOffset;
    u32 romSize;
    u16 mapperFlags;
} RomEntry;

extern const RomEntry gRomTable[];
extern const u16 gRomCount;

#endif
