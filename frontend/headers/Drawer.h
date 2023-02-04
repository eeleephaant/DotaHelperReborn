#pragma once

#include "TextLabel.h"
#include "TextPlaceholder.h"
#include "overlay.h"
#include <X11/X.h>
#include <X11/Xlib.h>
#include <X11/Xutil.h>

class Drawer
{
private:
    Overlay *overlay;
    cairo_t *cr;
    cairo_surface_t *surf;
    cairo_text_extents_t extents;

public:
    Drawer(Overlay *overlay);
    void DrawTextX11(TextPlaceholder text);
    void DrawLabel(TextLabel text);
    void ClearLabel(TextLabel text);
};
