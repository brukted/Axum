
#include "Log.h"
#include "MApplication.h"
#include "PathUtils.h"
#include <gdlmm.h>
#include <gtkmm.h>
/**
 * Dummy placeholder macro for internationalization with gettext. Will be
 *replaced with #include <glibmm/i18n.h> in future for true internationalization.
 **/
#define _(text) text

using namespace Axum::Utils;

void load_resources();

int main(int argc, char *argv[]) {
  Gdl::init();
  PathUtils::getPaths(argv[0]);
  Log::getInstance().Startup();
  load_resources();
  AX_LOG_EDITOR_INFO("Application path : {}", PathUtils::excutablePath)
  auto application = Axum::MApplication::create();
  AX_LOG_EDITOR_INFO("Application created.")
  return application->run(argc, argv);
}

/**
 * @brief Loads resources embedded or bundled with glib
 * compile resources tool.
 *
 */
void load_resources() {
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
}
