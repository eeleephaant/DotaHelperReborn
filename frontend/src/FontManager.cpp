#include "../headers/FontManager.h"

FontManager::FontManager(Overlay *overlay)
{
    this->overlay = overlay;
}

void FontManager::ChangeFont(FontInfo fontinfo)
{
    fontname.append(fontinfo.collection);
    fontname.append("-");
    fontname.append(fontinfo.family);
    fontname.append("-");
    fontname.append(fontSaturations[(int)fontinfo.saturation]);
    fontname.append("-");
    fontname.append(fontInclines[(int)fontinfo.incline]);
    fontname.append("-");
    fontname.append(fontWidths[(int)fontinfo.width]);
    fontname.append("-");
    fontname.append(fontinfo.adstyle);
    fontname.append("-");
    fontname.append(fontinfo.pixelsize);
    fontname.append("-");
    fontname.append(fontinfo.dotsize);
    fontname.append("-");
    fontname.append(fontinfo.resx);
    fontname.append("-");
    fontname.append(fontinfo.resy);
    fontname.append("-");
    fontname.append(fontProportionalitys[(int)fontinfo.proportion]);
    fontname.append("-");
    fontname.append(fontinfo.avgcharwidth);
    fontname.append("-");
    fontname.append(fontinfo.encoding);
    fontname.append("-");
    fontname.append(fontinfo.langaffil);
    font = XLoadQueryFont(overlay->display, fontname.c_str());
    XSetFont(overlay->display, overlay->gc, font->fid);
}