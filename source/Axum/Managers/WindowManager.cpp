/**
 * Project Material Lab
 * @author Bruk Tedla
 */

#include "WindowManager.h"

/**
 * WindowManager implementation
 * 
 * Manages Windows and editors layout also can be used to add  new editor into the specified window.
 */

/**
 * @param window
 */
void WindowManager::AddWindow(Window window)
{
}

void WindowManager::Startup()
{
}

void WindowManager::Shutdown()
{
}

void WindowManager::ShowMainWindow()
{
    auto win = new MainWindow();
    this->MainWin = win;
    this->app->add_window(*win);
    this->MainWin->present();
    this->MainWin->set_title("Axum");
}