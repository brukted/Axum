#include "MApplication.h"
#include "Log.h"
#include "pathUtils.h"
#include <gdlmm.h>

int main(int argc, char *argv[])
{
    Gdl::init();
    Log::getInstance().Startup();
    PathUtils::getPaths(argv[0]);
    AX_LOG_EDITOR_INFO("Application path : {}", PathUtils::excutablePath)
    auto application = MApplication::create();
    AX_LOG_EDITOR_INFO("Application created.")
    return application->run(argc, argv);
}
