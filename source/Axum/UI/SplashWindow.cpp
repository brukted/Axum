#include "SplashWindow.h"

namespace Axum::UI::Window {

SplashWindow::SplashWindow(int width, int height) {
  this->set_default_size(width, height);
  this->set_decorated(false);
  this->set_resizable(false);
  this->set_position(Gtk::WIN_POS_CENTER_ALWAYS);
  this->set_type_hint(Gdk::WINDOW_TYPE_HINT_SPLASHSCREEN);
}

SplashWindow::SplashWindow() : SplashWindow(945, 750) {}

}