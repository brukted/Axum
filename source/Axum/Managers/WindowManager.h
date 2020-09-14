/**
 * Project Material Lab
 * @author Bruk Tedla
 */

#ifndef _WINDOWMANAGER_H
#define _WINDOWMANAGER_H

#include "UI/MainWindow.h"
#include "Utils/Log/Log.h"
#include <imgui.h>
#include <imgui_impl_glfw.h>
#include <imgui_impl_opengl3.h>
#define GLFW_INCLUDE_NONE // GLFW including OpenGL headers causes ambiguity or
                          // multiple definition errors.
#include <GLFW/glfw3.h>
#include <glbinding/gl/gl.h>
#include <glbinding/glbinding.h> // Initialize with glbinding::initialize()
#include <vector>

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
#endif //_WINDOWMANAGER_H
