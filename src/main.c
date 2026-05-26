#include <genesis.h>
#include "menu.h"

int main(bool hardReset)
{
    (void)hardReset;

    JOY_init();
    VDP_setScreenWidth320();
    VDP_setPaletteColors(0, (const u16[]){0x000, 0xEEE}, 2);

    MENU_init();

    while (1)
    {
        MENU_update();
        SYS_doVBlankProcess();
    }

    return 0;
}
