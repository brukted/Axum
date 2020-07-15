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

void WindowManager::AddWindow(Gtk::Window window) {}

void WindowManager::Startup() {}

void WindowManager::Shutdown() {}

void WindowManager::AddShowMainWindow() {
  MainWin = new UI::Window::MainWindow();
  windows.push_back(MainWin);
  app->add_window(*MainWin);
  MainWin->set_title("Axum");
  MainWin->present();
}

} // namespace Axum::Manager