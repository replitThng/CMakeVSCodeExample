#include <iostream>
#include "makeDirectory.h"
#include "HelloWorld.h"


void HelloWorld::SayHello()
{
    std::cout << "Library Say Hello;\n";

    //call subdirectory functions
    generalFunctions::makeDirectory();
}