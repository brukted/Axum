#include "SplashWindow.h"

namespace Axum::UI::Window {

SplashWindow::SplashWindow(int width, int height) {
  this->set_size_request(width, height);
  this->set_decorated(false);
  this->set_resizable(false);
  this->set_position(Gtk::WIN_POS_CENTER_ALWAYS);
  this->set_type_hint(Gdk::WINDOW_TYPE_HINT_SPLASHSCREEN);
  show_all();
  auto img = new Gtk::Image();
  auto bitmap = Gdk::Pixbuf::create_from_resource("/splash.png");
  bitmap = bitmap->scale_simple(width, height, Gdk::InterpType::INTERP_BILINEAR);
  img->set_size_request(width,height);
  img->property_pixbuf() = bitmap;
  img->property_expand() = false;
  add(*img);
  img->show_all();
}

SplashWindow::SplashWindow() : SplashWindow(945, 750) {}

} // namespace Axum::UI::Window