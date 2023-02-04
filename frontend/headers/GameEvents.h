#pragma once

#include "../headers/GSIHandler.h"
#include "../headers/TextLabel.h"
#include "../headers/overlay.h"
#include "Drawer.h"

class GameEvents
{
private:
    GSIHandler _gsi;
    Overlay overlay;
    Drawer *drawer;
public:
    GameEvents(GSIHandler *gsi, Overlay overlay, Drawer *drawer);
    void RunesListener();
};

