#include "IEngine.h"
#include <iostream>


class V7Engine : public IEngine
{

    void Start() override
    {
        std::cout << "Start V7 Engine " << std::endl ;
    }

    void Stop() override
    {
        std::cout << "Stop V7 Engine " << std::endl ; 
    }
};