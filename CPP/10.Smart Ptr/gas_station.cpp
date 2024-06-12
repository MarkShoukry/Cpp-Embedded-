//just pointer
#include <iostream>
using namespace std ;

class GasolineSource
{
public:
    virtual void FuelUp() = 0;
    virtual ~GasolineSource() = default ;
};

class GasStation : public GasolineSource
{
public:
    void FuelUp() override
    {
        cout << "Pumping gas at gas station" << endl;
    }
};


class FuelCan : public GasolineSource
{
public:
    void FuelUp() override
    {
        cout << "Pumping gas from fuel can" << endl ;
    }
};



class Car
{
private:
    GasolineSource *gasolineService = nullptr ;

public:
    Car(GasolineSource *service) :gasolineService(service)
    {
        if(gasolineService == nullptr)
        {
            throw std::invalid_argument("service must not be null");
        }
    }

    void getGasoline()
    {
        cout << "Car needs more gasoline!" << endl ;
        gasolineService->FuelUp();
    }
};





int main ()
{
    GasolineSource *stationService = new GasStation() ;
    GasolineSource *canService = new FuelCan() ;

    Car rececar(stationService);
    rececar.getGasoline();

    Car duneBuggy(canService);
    duneBuggy.getGasoline();


    delete canService;
    delete stationService ;
    
    
    return 0 ;
}