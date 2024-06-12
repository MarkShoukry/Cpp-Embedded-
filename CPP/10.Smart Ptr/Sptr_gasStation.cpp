//using unique_ptr :
#include <iostream>
#include <memory>



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
        std::cout << "Pumping gas at gas station" << std::endl;
    }
};


class FuelCan : public GasolineSource
{
public:
    void FuelUp() override
    {
        std::cout << "Pumping gas from fuel can" << std::endl ;
    }
};



class Car
{
private:
    std::unique_ptr<GasolineSource>gasolineService;

public:
    Car(std::unique_ptr<GasolineSource>service) :gasolineService(std::move(service))
    {
        if(gasolineService == nullptr)
        {
            throw std::invalid_argument("service must not be null");
        }
    }

    void getGasoline()
    {
        std::cout << "Car needs more gasoline!" << std::endl ;
        gasolineService->FuelUp();
    }
};





int main ()
{
    std::unique_ptr<GasolineSource> stationService = std::make_unique<GasStation>();
    std::unique_ptr<GasolineSource> canService = std::make_unique<FuelCan>();

    std::unique_ptr<Car> rececar = std::make_unique<Car>(std::move(stationService));
    rececar->getGasoline();
    
    Car duneBuggy(std::make_unique<FuelCan>());
    duneBuggy.getGasoline();

    
    
    return 0 ;
}