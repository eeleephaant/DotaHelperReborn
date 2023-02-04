#include "../headers/GameEvents.h"

GameEvents::GameEvents(GSIHandler *gsi, Overlay overlay, Drawer *drawer)
{
    this->_gsi = *gsi;
    this->overlay = overlay;
    this->drawer = drawer;
}

void GameEvents::RunesListener()
{
    TextLabel notify(overlay.screenRes.x / 2 + 40, 60, "", 1, 1, 0, 1, CAIRO_FONT_SLANT_NORMAL, CAIRO_FONT_WEIGHT_NORMAL, 24, (char *)"google sans");
    while (1)
    {
        sleep(1);
        if (_gsi.maptime == "" || _gsi.maptime == "225")
        {
            notify.text = "Руны воды появятся через 15 секунд!";
            drawer->DrawLabel(notify);
            sleep(2);
            drawer->ClearLabel(notify);
        }
    }
}