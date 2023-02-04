#include "../headers/overlay.h"

Overlay::Overlay()
{
    display = XOpenDisplay(NULL);
    XMatchVisualInfo(display, DefaultScreen(display), 32, TrueColor, &vinfo);
    rootwindow = DefaultRootWindow(display);
    screen = DefaultScreen(display);
    attrs.override_redirect = true;
    attrs.colormap = XCreateColormap(display, rootwindow, vinfo.visual, AllocNone);
    attrs.background_pixel = 0;
    attrs.border_pixel = 0;
    valuemask = 0;
    screenRes.x = DisplayWidth(display, screen);
    screenRes.y = DisplayHeight(display, screen);
}

void Overlay::initWindow()
{
    overlaywindow = XCreateWindow(
        display, rootwindow,
        0, 0, screenRes.x, screenRes.y, 0,
        vinfo.depth, InputOutput,
        vinfo.visual,
        CWOverrideRedirect | CWColormap | CWBackPixel | CWBorderPixel, &attrs);
    XMapWindow(display, overlaywindow);
    XStoreName(display, overlaywindow, appname);
    XClassHint *classHint = XAllocClassHint();
    classHint->res_name = (char *)appname;
    classHint->res_class = (char *)appname;
    XserverRegion region = XFixesCreateRegion(display, NULL, 0);
    XFixesSetWindowShapeRegion(display, overlaywindow, ShapeBounding, 10, 10, 0);
    XFixesSetWindowShapeRegion(display, overlaywindow, ShapeInput, 0, 0, region);
    XFixesDestroyRegion(display, region);
    gc = XCreateGC(display, overlaywindow, valuemask, &values);
    XSync(display, False);
}

void Overlay::destroyWindow()
{
    XUnmapWindow(display, overlaywindow);
    XCloseDisplay(display);
}