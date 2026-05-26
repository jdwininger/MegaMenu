#include "flashkit_mapper.h"

static u32 sLaunchOffset = 0;
static u32 sLaunchSize = 0;
static u16 sLaunchFlags = 0;

void FK_prepareLaunch(const u32 romOffset, const u32 romSize, const u16 mapperFlags)
{
    sLaunchOffset = romOffset;
    sLaunchSize = romSize;
    sLaunchFlags = mapperFlags;
}

void FK_launchSelectedRom(void)
{
    // Mapper-specific bank setup goes here.
    // For Krikzz workflows, this function usually writes mapper registers,
    // then jumps to the selected ROM reset vector.

    (void)sLaunchOffset;
    (void)sLaunchSize;
    (void)sLaunchFlags;

    // TODO: Implement your mapper writes and branch-to-reset logic.
    while (1)
    {
        // Halt in placeholder mode to avoid accidental execution.
    }
}
