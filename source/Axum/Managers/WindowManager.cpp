/**
 * Project Material Lab
 * @author Bruk Tedla
 */

#include "WindowManager.h"

/**
 * WindowManager implementation
 *
 * Manages Windows and editors layout also can be used to add  new editor into
 * the specified window.
 */

namespace Axum::Manager {

/**
 * @param window
 */
void WindowManager::AddWindow(Gtk::Window window) {}

void WindowManager::Startup() {}

void WindowManager::Shutdown() {}

void WindowManager::AddShowMainWindow() {
  windows.push_back(new UI::Window::MainWindow());
  auto MainWin = windows.at(0);
  this->app->add_window(*MainWin);
  MainWin->present();
  MainWin->set_title("Axum");
}

} // namespace Axum::Manager