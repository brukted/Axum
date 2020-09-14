/**
 * Project Material Lab
 * @author Bruk Tedla
 */

#include "MApplication.h"

/**
 * MApplication implementation
 */

namespace Axum {

MApplication::MApplication() {}

MApplication::~MApplication() {
  AX_LOG_EDITOR_TRACE("Shutting down Window manager")
  Manager::WindowManager::getInstance().Shutdown();

  AX_LOG_EDITOR_TRACE("Shutting down Render manager")
  Manager::RenderManager::getInstance().Shutdown();

  AX_LOG_EDITOR_TRACE("Shutting down Package manager")
  Manager::PackageManager::getInstance().Shutdown();

  AX_LOG_EDITOR_TRACE("Shutting down Undo manager")
  Manager::UndoManager::getInstance().Shutdown();

  AX_LOG_EDITOR_TRACE("Shutting down Addon manager")
  Manager::AddonManager::getInstance().Shutdown();

  AX_LOG_EDITOR_TRACE("Shutting down Preference manager")
  Manager::PreferenceManager::getInstance().Shutdown();
}

void MApplication::activate() {
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
  Manager::WindowManager::getInstance().Startup();
  Window_Manager.iterate();
  // Addon Manager is started at last because it has reference to all aspects of
  // the software
  AX_LOG_EDITOR_TRACE("Starting up Addon manager")
  Manager::AddonManager::getInstance().Startup();
}

int MApplication::run() {
  Window_Manager.mainLoop();
  return 0;
}

} // namespace Axum