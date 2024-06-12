#include "Car.h"
#include "V7Engine.h"
#include "V8Engine.h"

Car::Car(std::unique_ptr<IEngine>&& engine) : m_engine(std::move(engine))
{
}

void Car::Drive()
{
    m_engine->Start();
}

void Car::Stop()
{
    m_engine->Stop();
}
