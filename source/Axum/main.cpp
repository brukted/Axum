#include <iostream>
#include"MApplication.h"

int main(int argc, char* argv[])
{
auto application = MApplication::create();
  std::cout<<"Hello World!"<<std::endl;
return application->run(argc, argv);
}
