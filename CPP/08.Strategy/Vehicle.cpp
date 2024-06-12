//virtual class(run time) dynamic polymorphism
#include <iostream>
using namespace std;

//Abstract Class
class Strategy
{
public:
//Algorithm Interface
    virtual void CalculateSpeed() = 0 ;
};

class BMW :  public Strategy
{
public:
    void CalculateSpeed()  override
    {
        cout << "BMW Speed\n" ;
    }
};

class Mini_coper : public Strategy
{
public:
    void CalculateSpeed() override
    {
        cout << "Mini Coper Speed\n" ;
    }

};

//context
class Vehicle 
{
public:
    Vehicle(Strategy *_strategy) : strategy(_strategy)
    {
    }

    void VehicleSpeed()
    {
        strategy->CalculateSpeed();
    }
private:
//Ptr to implementation : pimpl idiom 
    Strategy *strategy ;

};


int main ()
{
    BMW bmw ;
    Mini_coper mini;
    Strategy * str = new BMW() ;
    str->CalculateSpeed(); // BMW

    str = &mini ;
    str->CalculateSpeed(); //Mini_Coper

    Vehicle E36(&bmw) ;
    E36.VehicleSpeed() ;

    Vehicle car2(&mini);
    car2.VehicleSpeed() ;



    return 0;
}