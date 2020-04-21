#include "SplashWindow.h"

SplashWindow::SplashWindow(int width,int height){
    this->set_size_request(width,height);
    this->set_decorated(false);
    this->set_resizable(false);
    this->set_position(Gtk::WIN_POS_CENTER_ALWAYS);
    this->set_type_hint(Gdk::WINDOW_TYPE_HINT_SPLASHSCREEN);
}
SplashWindow::SplashWindow(){
    this->set_size_request(500,500);
    this->set_decorated(false);
    this->set_resizable(false);
    this->set_position(Gtk::WIN_POS_CENTER_ALWAYS);
    this->set_type_hint(Gdk::WINDOW_TYPE_HINT_SPLASHSCREEN);
}