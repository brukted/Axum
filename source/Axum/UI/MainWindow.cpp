/**
 * Project Material Lab
 * @author Bruk Tedla
 */

#include "MainWindow.h"

namespace Axum::UI::Window {

/**
 * MainWindow implementation
 */

MainWindow::MainWindow() {
  this->set_position(Gtk::WindowPosition::WIN_POS_CENTER);
  this->set_size_request(960, 540);
  maximize();
}
}