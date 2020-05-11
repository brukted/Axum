#include "MApplication.h"
#include "Utils/Log/Log.h"

int main(int argc, char *argv[])
{
    Log::getInstance().Startup();
    auto application = MApplication::create();
    return application->run(argc, argv);
}
