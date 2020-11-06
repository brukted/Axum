/**
 * Project Material Lab
 * @author Bruk Tedla
 */

#ifndef _AXUM_MANAGERS_WINDOW_MANAGER_H_
#define _AXUM_MANAGERS_WINDOW_MANAGER_H_

#include "UI/MainWindow.h"
#define GLFW_INCLUDE_NONE // GLFW including OpenGL headers causes ambiguity or
                          // multiple definition errors.
#include <GLFW/glfw3.h>

namespace Axum::Manager {
class WindowManager {
public:
  static WindowManager &getInstance() {
    static WindowManager instance;
    return instance;
  }

  UI::MainWindow mainWin;

private:
  WindowManager(){};
  static void glfwErrorCallback(int error, const char *description);
  GLFWwindow *window;

public:
  WindowManager(WindowManager const &) = delete;
  void operator=(WindowManager const &) = delete;

  void Startup();

  void Shutdown();

  void iterate();

  void mainLoop();
};
} // namespace Axum::Manager

/**
 * @brief Shortcut to the instance of WindowManager.
 *
 */
#define Window_Manager Axum::Manager::WindowManager::getInstance()
#endif //_AXUM_MANAGERS_WINDOW_MANAGER_H_
