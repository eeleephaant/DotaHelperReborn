#pragma once

extern const char *fontInclines[];
extern const char *fontSaturations[];
extern const char *fontWidths[];
extern const char *fontProportionalitys[];

enum class FontSaturation
{
    Bold = 0,
    Demibold = 1,
    Medium = 2,
    Regular = 3,
    Standart = 4
};

enum class FontIncline
{
    Cursive = 0,
    Italics = 1,
    Direct = 2,
    Standart = 3
};

enum class FontWidth
{
    Normal = 0,
    Semicondensed = 1,
    Condensed = 2,
    Standart = 3
};

enum class FontProportionality
{
    Monospace_C = 0,
    Monospace_M = 1,
    Proportional = 2,
    Standart = 3
};

struct FontInfo
{
    const char *collection = "*";
    const char *family = "*";
    FontSaturation saturation = FontSaturation::Standart;
    FontIncline incline = FontIncline::Standart;
    FontWidth width = FontWidth::Standart;
    const char *adstyle = "*";
    const char *pixelsize = "*";
    const char *dotsize = "*";
    const char *resx = "*";
    const char *resy = "*";
    FontProportionality proportion = FontProportionality::Standart;
    const char *avgcharwidth = "*";
    const char *encoding = "*";
    const char *langaffil = "*";
};