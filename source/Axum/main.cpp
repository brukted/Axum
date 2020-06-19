#include "Log.h"
#include "MApplication.h"
#include "PathUtils.h"

using namespace Axum::Utils;

int main(int argc, char *argv[]) {
  PathUtils::getPaths(argv[0]);
  Log::getInstance().Startup();
  AX_LOG_EDITOR_INFO("Application path : {}", PathUtils::excutablePath)
  auto application = Axum::MApplication::create();
  AX_LOG_EDITOR_INFO("Application created.")
  return application->run(argc, argv);
}
