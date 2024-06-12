#include "V8Engine.h"
#include <iostream>

void V8Engine::Start()
{
    std::cout << "Start V8 Engine\n";
}

void V8Engine::Stop()
{
    std::cout << "Stop V8 Engine\n" ;
}


std::unique_ptr<IEngine> MakeV8Engine() 
{
    return std::make_unique<V8Engine>() ;
}
