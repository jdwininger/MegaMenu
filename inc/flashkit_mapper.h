#ifndef FLASHKIT_MAPPER_H
#define FLASHKIT_MAPPER_H

#include <genesis.h>

void FK_prepareLaunch(const u32 romOffset, const u32 romSize, const u16 mapperFlags);
void FK_launchSelectedRom(void);

#endif
