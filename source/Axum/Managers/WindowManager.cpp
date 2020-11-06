/**
 * Project Material Lab
 * @author Bruk Tedla
 */

#include "Utils/Log/Log.h"
#include "WindowManager.h"
#include "imnodes.h"
#include <glbinding/gl43core/gl.h>
#include <glbinding/glbinding.h>
#include <imgui.h>
#include <imgui_impl_glfw.h>
#include <imgui_impl_opengl3.h>

/**
 * WindowManager implementation
 *
 * Manages Windows and editors layout also can be used to add  new editor into
 * the specified window.
 */

namespace Axum::Manager {
void WindowManager::glfwErrorCallback(int error, const char *description) {
  AX_LOG_EDITOR_ERROR("Glfw Error {} : {}", error, description)
}

void WindowManager::Startup() {
  glfwSetErrorCallback(glfwErrorCallback);
  if (!glfwInit())
    return;

#if __APPLE__
  const char *glsl_version = "#version 150";
  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE); // 3.2+ only
  glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT,
                 (int)(gl::GL_TRUE)); // Required on Mac
#else
  const char *glsl_version = "#version 130";
  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);  // 3.2+
  glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, (int)(gl::GL_TRUE)); // 3.0+ only
#endif

  window = glfwCreateWindow(1280, 720, "Axum", NULL, NULL);
  if (window == NULL)
    return;
  glfwMakeContextCurrent(window);
  glfwSwapInterval(1); // Enable vsync

  // Initialize OpenGL loader
  glbinding::initialize([](const char *name) {
    return (glbinding::ProcAddress)glfwGetProcAddress(name);
  });
  // Setup Dear ImGui context
  IMGUI_CHECKVERSION();
  ImGui::CreateContext();
  imnodes::Initialize();
  ImGuiIO &io = ImGui::GetIO();
  (void)io;
  // Enable Keyboard Controls
  io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;
  // Enable Gamepad
  // io.ConfigFlags |= ImGuiConfigFlags_NavEnableGamepad;
  // Controls
  // Enable Docking
  // io.ConfigFlags |= ImGuiConfigFlags_DockingEnable;
  // io.ConfigFlags |= ImGuiConfigFlags_ViewportsEnable;
  // Enable Multi-Viewport / Platform Windows io.ConfigViewportsNoAutoMerge =
  // true; io.ConfigViewportsNoTaskBarIcon = true;

  // Setup Dear ImGui style
  ImGui::StyleColorsDark();

  // When viewports are enabled we tweak WindowRounding/WindowBg so platform
  // windows can look identical to regular ones.
  ImGuiStyle &style = ImGui::GetStyle();
  /*
  if (io.ConfigFlags & ImGuiConfigFlags_ViewportsEnable) {
    style.WindowRounding = 0.0f;
    style.Colors[ImGuiCol_WindowBg].w = 1.0f;
  }*/

  // Setup Platform/Renderer bindings
  ImGui_ImplGlfw_InitForOpenGL(window, true);
  ImGui_ImplOpenGL3_Init(glsl_version);
}

void WindowManager::Shutdown() {
  ImGui_ImplOpenGL3_Shutdown();
  ImGui_ImplGlfw_Shutdown();
  imnodes::Shutdown();
  ImGui::DestroyContext();
  glfwDestroyWindow(window);
  glfwTerminate();
}

void WindowManager::iterate() {
  static ImVec4 clearColor = ImVec4(0.45f, 0.55f, 0.60f, 1.00f);
  // Poll and handle events (inputs, window resize, etc.)
  // You can read the io.WantCaptureMouse, io.WantCaptureKeyboard flags to tell
  // if dear imgui wants to use your inputs.
  // - When io.WantCaptureMouse is true, do not dispatch mouse input data to
  // your main application.
  // - When io.WantCaptureKeyboard is true, do not dispatch keyboard input data
  // to your main application. Generally you may always pass all inputs to dear
  // imgui, and hide them from your application based on those two flags.
  glfwPollEvents();

  // Start the Dear ImGui frame
  ImGui_ImplOpenGL3_NewFrame();
  ImGui_ImplGlfw_NewFrame();
  ImGui::NewFrame();

  mainWin.draw();

  // Rendering
  ImGui::Render();
  int display_w, display_h = 0;
  glfwGetFramebufferSize(window, &display_w, &display_h);
  gl::glViewport(0, 0, display_w, display_h);
  gl::glClearColor(clearColor.x, clearColor.y, clearColor.z, clearColor.w);
  gl::glClear(gl::GL_COLOR_BUFFER_BIT);
  ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

  // Update and Render additional Platform Windows
  // (Platform functions may change the current OpenGL context, so we
  // save/restore it to make it easier to paste this code elsewhere.
  //  For this specific demo app we could also call
  //  glfwMakeContextCurrent(window) directly)
  /*
  if (io.ConfigFlags & ImGui::ImGuiConfigFlags_ViewportsEnable) {
    GLFWwindow *backup_current_context = glfwGetCurrentContext();
    ImGui::UpdatePlatformWindows();
    ImGui::RenderPlatformWindowsDefault();
    glfwMakeContextCurrent(backup_current_context);
  }*/

  glfwSwapBuffers(window);
}

void WindowManager::mainLoop() {
  while (!glfwWindowShouldClose(window)) {
    iterate();
  }
}

} // namespace Axum::Manager