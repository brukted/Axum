#include "Log.h"
#include "MApplication.h"
#include "PathUtils.h"
#include <gtkmm.h>

using namespace Axum::Utils;

void load_resources();

int main(int argc, char *argv[]) {
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
  GError *err = NULL;
  std::string rPath = PathUtils::resourcesPath + "/resources.bin";
  GResource *r = g_resource_load(rPath.c_str(), &err);
  if (r == NULL) {
    AX_LOG_EDITOR_CRITICAL("Can't load resources.")
    AX_LOG_EDITOR_CRITICAL(err->message)
  } else {
    g_resources_register(r);
  }
}
