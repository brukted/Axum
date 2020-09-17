
#include "Utils/Log/Log.h"
#include "MApplication.h"
#include "Utils/PathUtils/PathUtils.h"

int main(int argc, char *argv[]) {
  Axum::Utils::PathUtils::getPaths(argv[0]);
  Axum::Utils::Log::getInstance().Startup();
  AX_LOG_EDITOR_INFO("Application path : {}", Axum::Utils::PathUtils::excutablePath)
  auto app = Axum::MApplication();
  AX_LOG_EDITOR_INFO("Application created.")
  app.activate();
  return app.run();
}