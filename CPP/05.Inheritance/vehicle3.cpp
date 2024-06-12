#include <iostream>
#include <vector>

class Control
{
public:
    Control (){}
    virtual void ManualContriol()
    {
    }
    void AutoControl()
    {
    }

private:

};


class MotorCycle : public Control
{
public:
    MotorCycle()
    {
        ManualContriol();
    }
private:

};

class Vehicle
{
public:
    Vehicle(){}
    void run()
    {
        std::cout << "Vehicle Run " << std::endl ;
    }
    
    virtual void run(int speed)
    {
        std::cout << "Run" << speed << std::endl ; 
    }
    void stop ()
    {
        std::cout << "Stop" << std::endl ;
    }

};

class Car : public Vehicle , public Control
{
public:
    Car()
    {
        stop();
        AutoControl();
    }
private:
};

class Bike : public Vehicle 
{
public:
    Bike ()
    {
        stop();
    }

    virtual void run (int speed)
    {
        std::cout <<"Bike Runs" << std::endl ;
    }
    void accelerate()
    {

    }

};

void detectVehicle(const std::vector<Vehicle*> &vehicles)
{
    //do something
}


int main()
{
    Vehicle *v = new Bike() ;
    v->run();
    v->run(25);

    Bike *bi = dynamic_cast<Bike*>(v);
    bi->accelerate();
   // bi->run();

    Bike bike;
    //bike.run();
    bike.run(20);

    return 0 ;
}