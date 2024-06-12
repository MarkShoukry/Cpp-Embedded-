//multiple inheritance
#include <iostream>


class Control
{
public:
    Control()
    {

    }
    ~Control()
    {

    }
    void Automatic_Control ()
    {
        std::cout << "Auto Control" << std::endl;
    }

    void Manual_Control ()
    {
        std::cout << "Manual Control" << std::endl;
    }

private:


};
class Vehicle 
{
public:
    Vehicle()
    {

    }
    ~Vehicle ()
    {

    }
    void Stop ()
    {
        std::cout << "Stop" << std::endl;
    }

    void Run ()
    {
        std::cout << "Run" << std::endl;
    }
private:

};

//multiple inheritance
class Car : public Control , public Vehicle
{
public:
    Car()
    {
        Stop();
        Automatic_Control();
    }
    ~Car(){}

    
private:

};


class Bike : public Vehicle
{
public:
    Bike ()
    {
        Stop();
    }
private:

};


int main ()
{
    Car car_BMW ;
    car_BMW.Run();
    Bike bike; 
    bike.Run(); 
    return 0;
}
