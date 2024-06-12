//using shared_ptr
#include <iostream>
#include <memory>


class GasolineSource
{
public:
    virtual void FuelUp() = 0;
    virtual ~GasolineSource() = default;
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
        std::cout << "Pumping gas from fuel can" << std::endl;
    }
};

class Car
{
private:
    std::shared_ptr<GasolineSource> gasolineService;

public:
    Car(std::shared_ptr<GasolineSource> service) : gasolineService(std::move(service))
    {
        if (gasolineService == nullptr)
        {
            throw std::invalid_argument("service must not be null");
        }
    }

    void getGasoline()
    {
        std::cout << "Car needs more gasoline!" << std::endl;
        gasolineService->FuelUp();
    }
};

int main()
{
    std::shared_ptr<GasolineSource> stationService = std::make_shared<GasStation>();
    std::shared_ptr<GasolineSource> canService = std::make_shared<FuelCan>();

    std::shared_ptr<Car> raceCar = std::make_shared<Car>(std::move(stationService));
    raceCar->getGasoline();

    Car duneBuggy(std::make_shared<FuelCan>());
    duneBuggy.getGasoline();

    return 0;
}
