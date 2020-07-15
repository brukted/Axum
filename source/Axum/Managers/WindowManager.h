/**
 * Project Material Lab
 * @author Bruk Tedla
 */

#ifndef _WINDOWMANAGER_H
#define _WINDOWMANAGER_H

#include "UI/MainWindow.h"
#include <gtkmm.h>
#include <vector>

namespace Axum::Manager {

namespace UI = Axum::UI;

class WindowManager {
public:
  static WindowManager &getInstance(Gtk::Application *app = nullptr) {
    static WindowManager instance;
    if (app != nullptr)
      instance.app = app;
    return instance;
  }
  Gtk::Application *app;
  Gtk::Window *MainWin;

private:
  WindowManager(){};

public:
  WindowManager(WindowManager const &) = delete;
  void operator=(WindowManager const &) = delete;
  /**
   * @param window
   */
  void AddWindow(Gtk::Window window);

  void Startup();

  void Shutdown();

  void AddShowMainWindow();

private:
  std::vector<Gtk::Window *> windows;
};
} // namespace Axum::Manager

/**
 * @brief Shortcut to the instance of WindowManager.
 * 
 */
#define Window_Manager Axum::Manager::WindowManager::getInstance() 
#endif //_WINDOWMANAGER_H
