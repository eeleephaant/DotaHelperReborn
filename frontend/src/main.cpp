#include "../headers/DBManager.h"
#include "../headers/GSIHandler.h"
#include "../headers/TextLabel.h"
#include "../headers/overlay.h"
#include "../headers/GameEvents.h"
#include "../headers/LobbyInfoParser.h"

#include "cairo/cairo-xlib.h"
#include "cairo/cairo.h"

#include <chrono>
#include <thread>

int main()
{
    GSIHandler gsi;
    // std::thread threadGSI(&GSIHandler::Init, &gsi);
    // threadGSI.detach();

    LobbyInfoParser sss;
    sss.Parse();
    const char *ptrSad = "GPM";
    const char **ptrptrptrSad = &ptrSad;

    const char *ptrHero = "Hero:";
    const char **ptrptrHero = &ptrHero;

    Overlay overlay;
    overlay.initWindow();

    Drawer drawer(&overlay);

    GameEvents events(&gsi, overlay, &drawer);
    std::thread threadEvents(&GameEvents::RunesListener, events);
    threadEvents.detach();

    TextLabel gpmLabel(20, 20, "chlen: ", 1, 1, 0, 1, CAIRO_FONT_SLANT_NORMAL, CAIRO_FONT_WEIGHT_NORMAL, 24, (char *)"google sans");
    std::thread label(&Drawer::DrawLabel, drawer, gpmLabel);
    label.detach();

    TextLabel heroLabel(20, 60, "chlen: ", 1, 1, 0, 1, CAIRO_FONT_SLANT_NORMAL, CAIRO_FONT_WEIGHT_NORMAL, 24, (char *)"google sans");
    std::thread label1(&Drawer::DrawLabel, drawer, heroLabel);
    label1.detach();


    std::string aaa;

    while (1)
    {
        fflush(stdout);
        sleep(1);
        // aaa = gsi.maptime;
        ptrSad = aaa.c_str();
        // ptrHero = gsi.heroname.c_str();
    }

    return 0;
}