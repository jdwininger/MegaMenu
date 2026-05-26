#include <genesis.h>
#include "menu.h"
#include "rom_table.h"
#include "flashkit_mapper.h"

#define MAX_VISIBLE_ITEMS 18

static u16 sSelectedIndex = 0;
static u16 sPrevButtons = 0;

static void drawMenu(void)
{
    u16 i;

    VDP_clearTextArea(0, 2, 40, 26);
    VDP_drawText("MULTI-ROM MENU", 1, 0);
    VDP_drawText("A: Launch   D-Pad: Select", 1, 1);

    for (i = 0; i < gRomCount && i < MAX_VISIBLE_ITEMS; i++)
    {
        if (i == sSelectedIndex)
        {
            VDP_drawText(">", 1, i + 3);
        }
        else
        {
            VDP_drawText(" ", 1, i + 3);
        }

        VDP_drawText(gRomTable[i].title, 3, i + 3);
    }
}

void MENU_init(void)
{
    sSelectedIndex = 0;
    sPrevButtons = 0;
    drawMenu();
}

void MENU_update(void)
{
    const u16 buttons = JOY_readJoypad(JOY_1);
    const u16 pressed = buttons & (u16)(~sPrevButtons);

    if ((pressed & BUTTON_UP) && sSelectedIndex > 0)
    {
        sSelectedIndex--;
        drawMenu();
    }

    if ((pressed & BUTTON_DOWN) && (sSelectedIndex + 1) < gRomCount)
    {
        sSelectedIndex++;
        drawMenu();
    }

    if (pressed & BUTTON_A)
    {
        FK_prepareLaunch(
            gRomTable[sSelectedIndex].romOffset,
            gRomTable[sSelectedIndex].romSize,
            gRomTable[sSelectedIndex].mapperFlags);
        FK_launchSelectedRom();
    }

    sPrevButtons = buttons;
}
