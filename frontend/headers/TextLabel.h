#pragma once
#include "../headers/overlay.h"

#include "cairo/cairo-xlib.h"
#include "cairo/cairo.h"
#include <string>

class TextLabel
{
private:
public:
  _cairo_font_slant slantFont;
  _cairo_font_weight weightFont;
  double x, y;
  std::string text;
  double red, green, blue, alpha;
  int fontsize;
  const char *fontface;
  TextLabel(double x, double y, std::string text, double red,
            double green, double blue, double alpha,
            _cairo_font_slant slantFont, _cairo_font_weight weightFont,
            int fontsize, const char *fontface);
};
