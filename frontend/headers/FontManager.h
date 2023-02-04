#pragma once

#include "../headers/FontEnums.h"
#include "../headers/overlay.h"
#include <X11/X.h>
#include <X11/Xlib.h>
#include <X11/Xutil.h>
#include <string>

class FontManager
{
private:
    Overlay *overlay;
    std::string fontname = "-";
    XFontStruct *font;

public:
    FontManager(Overlay *overlay);
    void ChangeFont(FontInfo fontinfo);
};
