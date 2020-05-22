#include "MApplication.h"
#include "Log.h"

int main(int argc, char *argv[])
{
    Log::getInstance().Startup();
    auto application = MApplication::create();
    AX_LOG_EDITOR_INFO("Application created.")
    return application->run(argc, argv);
}
