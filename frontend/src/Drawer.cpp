#include "../headers/Drawer.h"

Drawer::Drawer(Overlay *overlay)
{
    this->overlay = overlay;
    surf = cairo_xlib_surface_create(overlay->display, overlay->overlaywindow,
                                     overlay->vinfo.visual, overlay->screenRes.x,
                                     overlay->screenRes.y);
    XSelectInput(overlay->display, overlay->overlaywindow, ExposureMask);
    cr = cairo_create(surf);
}

void Drawer::DrawTextX11(TextPlaceholder text)
{
    XSetForeground(overlay->display, overlay->gc, WhitePixel(overlay->display, overlay->screen));
    XDrawString(overlay->display, overlay->overlaywindow, overlay->gc, text.x, text.y, text.text, (int)strlen(text.text));

    XFlush(overlay->display);
    XSync(overlay->display, False);
}

void Drawer::DrawLabel(TextLabel label)
{
    cairo_set_source_rgba(cr, label.red, label.green, label.blue, label.alpha);
    cairo_select_font_face(cr, label.fontface, label.slantFont, label.weightFont);
    cairo_set_font_size(cr, label.fontsize);
    cairo_move_to(cr, label.x, label.y);
    cairo_show_text(cr, label.text.c_str());
    XFlush(overlay->display);
}

void Drawer::ClearLabel(TextLabel label)
{
    cairo_text_extents(cr, label.text.c_str(), &extents);
    cairo_set_source_rgba(cr, 1, 1, 1, 0);
    cairo_set_operator(cr, CAIRO_OPERATOR_SOURCE);
    cairo_rectangle(cr, label.x, label.y + 5, extents.width, -extents.height);
    cairo_fill(cr);
    XFlush(overlay->display);
}
