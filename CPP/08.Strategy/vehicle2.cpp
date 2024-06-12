//using Templet in context to compile time:

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
template<class T>
class Vehicle 
{
public:
    Vehicle(T *_strategy) : strategy(_strategy)
    {
    }

    void VehicleSpeed()
    {
        strategy->CalculateSpeed();
    }
private:
//Ptr to implementation : pimpl idiom 
    T *strategy ;

};


int main ()
{
    BMW bmw ;
    Mini_coper mini;
    Strategy * str = &bmw ;
    
    Vehicle<BMW> E36(&bmw) ;
    E36.VehicleSpeed() ;

    Vehicle<Mini_coper>car2(&mini);
    car2.VehicleSpeed() ;



    return 0;
}