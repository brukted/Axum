#include <iostream>
#include "MApplication.h"

int main(int argc, char *argv[])
{
    auto application = MApplication::create();
    return application->run(argc, argv);
}
