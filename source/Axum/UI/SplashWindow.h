/**
 * Project Material Lab
 * @author Bruk Tedla
 */

#ifndef SPLASHWINDOW_H
#define SPLASHWINDOW_H

#include "gtkmm-3.0\gtkmm.h"

class SplashWindow : public Gtk::Window
{
public:
    SplashWindow();
    SplashWindow(int width, int height);
};

#endif /*SPLASHWIDOW_H*/