#include <iostream>
#include "IEngine.h"
#include "V7Engine.h"
#include "V8Engine.h"
#include "Car.h"


int main ()
{
    auto engine_V7 = std::make_unique<V7Engine>();
    Car MiniCoper(std::move(engine_V7)); //dependency injection
    MiniCoper.Drive();

    Car Bmw_E36(MakeV8Engine()); //dependency injection
    Bmw_E36.Drive();
    Bmw_E36.Stop();

    return 0 ;
}



//To terminal:
//g++ -o AppCar Car.cpp V8Engine.cpp AppCar   then ./AppCar  or ./Car