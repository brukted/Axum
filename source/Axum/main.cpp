
#include "Utils/Log/Log.h"
#include "MApplication.h"
#include "Utils/PathUtils/PathUtils.h"
/**
 * Dummy placeholder macro for internationalization with gettext. Will be
 *replaced with #include <glibmm/i18n.h> in future for true
 *internationalization.
 **/
#define _(text) text

void load_resources();

int main(int argc, char *argv[]) {
  Axum::Utils::PathUtils::getPaths(argv[0]);
  Axum::Utils::Log::getInstance().Startup();
  load_resources();
  AX_LOG_EDITOR_INFO("Application path : {}", Axum::Utils::PathUtils::excutablePath)
  auto app = Axum::MApplication();
  AX_LOG_EDITOR_INFO("Application created.")
  app.activate();
  return app.run();
}

/**
 * @brief Loads resources embedded or bundled with glib
 * compile resources tool.
 *
 */
void load_resources() {
  /*
  AX_LOG_EDITOR_DEBUG("Loading resource.")
  GError *err = NULL;
  std::string rPath = PathUtils::resourcesPath + "/resources.bin";
  GResource *r = g_resource_load(rPath.c_str(), &err);
  if (r == NULL) {
    AX_LOG_EDITOR_CRITICAL("Can't load resources.")
    AX_LOG_EDITOR_CRITICAL(err->message)
    return;
  } else {
    g_resources_register(r);
  }
  AX_LOG_EDITOR_DEBUG("Finshed loading resource.")
  */
}
