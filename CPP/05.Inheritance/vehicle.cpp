#include <iostream>

class Vehicle
{
public:
    Vehicle()
    {

    }
    void Stop()
    {
        std::cout << "Stop" << std::endl;
    }
    void Run()
    {
        std::cout <<"Run" << std::endl ;
    }

private:

};

class Bike : public Vehicle
{
public:
    Bike()
    {
        Stop();
    }



private:

};



int main ()
{

    Bike bike;
    bike.Run();


    return 0;
}