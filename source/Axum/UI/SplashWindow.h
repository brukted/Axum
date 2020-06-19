/**
 * Project Material Lab
 * @author Bruk Tedla
 */

#ifndef SPLASHWINDOW_H
#define SPLASHWINDOW_H

#include "Log.h"
#include "PathUtils.h"
#include "glibmm.h"
#include "gtkmm.h"
#include <gio\gio.h>

namespace Axum::UI::Window {

class SplashWindow : public Gtk::Window {
public:
  SplashWindow();
  SplashWindow(int width, int height);
};

} // namespace Axum::UI::Window
#endif /*SPLASHWIDOW_H*/