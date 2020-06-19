/**
 * Project Material Lab
 * @author Bruk Tedla
 */

#include "MApplication.h"

/**
 * MApplication implementation
 */

namespace Axum {

MApplication::MApplication()
    : Gtk::Application("com.bruk.tedla.Axum", Gio::APPLICATION_HANDLES_OPEN) {}

Glib::RefPtr<MApplication> MApplication::create() {
  return Glib::RefPtr<MApplication>(new MApplication());
}

MApplication::~MApplication() {
  // TODO: Currently shutdown sequence is  a reverse of startup sequence
  // consider adjusting the order.
  AX_LOG_EDITOR_TRACE("Shutting down Window manager")
  Manager::WindowManager::getInstance(this).Shutdown();

  AX_LOG_EDITOR_TRACE("Shutting down PackageManager")
  Manager::RenderManager::getInstance().Shutdown();

  AX_LOG_EDITOR_TRACE("Shutting down PackageManager")
  Manager::PackageManager::getInstance().Shutdown();

  AX_LOG_EDITOR_TRACE("Shutting down UndoManager")
  Manager::UndoManager::getInstance().Shutdown();

  AX_LOG_EDITOR_TRACE("Shutting down Preference manager")
  Manager::PreferenceManager::getInstance().Shutdown();
}

void MApplication::on_activate() {
  auto splashScreen = UI::Window::SplashWindow();
  this->add_window(splashScreen);
  splashScreen.present();
  while (gtk_events_pending()) {
    gtk_main_iteration();
  }
  // Start the Preference Manager first as it does not depend on anything
  AX_LOG_EDITOR_TRACE("Starting up Preference manager")
  Manager::PreferenceManager::getInstance().Startup();
  // Starts Undo Manager
  AX_LOG_EDITOR_TRACE("Starting up Undo manager")
  Manager::UndoManager::getInstance().Startup();
  // Starts the manager and initializes package related stuffs
  AX_LOG_EDITOR_TRACE("Starting up Package manager")
  Manager::PackageManager::getInstance().Startup();
  // Starts the manager and initialize render engines
  AX_LOG_EDITOR_TRACE("Starting up Render manager")
  Manager::RenderManager::getInstance().Startup();
  // Starts the manager and initializes the main window but won't show it
  AX_LOG_EDITOR_TRACE("Starting up Window manager")
  Manager::WindowManager::getInstance(this).Startup();
  // Addon Manager is started at last because it has reference to all aspects of
  // the software
  AX_LOG_EDITOR_TRACE("Starting up Addon manager")
  Manager::AddonManager::getInstance().Startup();
  Manager::WindowManager::getInstance().AddShowMainWindow();
}

void MApplication::on_open(const Gio::Application::type_vec_files &files,
                           const Glib::ustring &hint) {
  for (auto f : files) {
    Manager::PackageManager::getInstance().LoadPackage(f);
  }
}

} // namespace Axum