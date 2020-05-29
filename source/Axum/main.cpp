#include "MApplication.h"
#include "Log.h"
#include "pathUtils.h"

int main(int argc, char *argv[])
{
    Log::getInstance().Startup();
    getPaths(argv[0]);
    AX_LOG_EDITOR_INFO(fmt::format("Application path : {}", excutablePath))
    auto application = MApplication::create();
    AX_LOG_EDITOR_INFO("Application created.")
    return application->run(argc, argv);
}
