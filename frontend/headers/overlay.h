#pragma once

#include <X11/X.h>
#include <X11/Xlib.h>
#include <X11/Xos.h>
#include <X11/Xutil.h>
#include <X11/extensions/Xcomposite.h>
#include <X11/extensions/Xfixes.h>
#include <X11/extensions/shapeconst.h>
#include <assert.h>
#include <stdio.h>

struct RESOLUTION
{
    int x, y;
};

class Overlay
{
public:
    Display *display;
    Window rootwindow;
    Window overlaywindow;
    XSetWindowAttributes attrs;
    XVisualInfo vinfo;
    unsigned long valuemask;
    XGCValues values;
    GC gc;
    int screen;
    const char *appname = "dotahelper";
    RESOLUTION screenRes;
    void initWindow();
    void destroyWindow();
    Overlay();
};