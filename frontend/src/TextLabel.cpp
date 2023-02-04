#include "../headers/TextLabel.h"

TextLabel::TextLabel(double x, double y, std::string text,
                     double red, double green, double blue, double alpha,
                     _cairo_font_slant slantFont, _cairo_font_weight weightFont,
                     int fontsize, const char *fontface)
{
  this->x = x;
  this->y = y;
  this->text = text;
  this->red = red;
  this->green = green;
  this->blue = blue;
  this->alpha = alpha;
  this->slantFont = slantFont;
  this->weightFont = weightFont;
  this->fontsize = fontsize;
  this->fontface = fontface;
}