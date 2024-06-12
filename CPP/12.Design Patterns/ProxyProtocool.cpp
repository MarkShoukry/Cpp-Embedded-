#include <iostream>
#include <memory>
using namespace std; 

class Protocool
{
public:
    virtual void DefineProtocool() = 0 ;
    virtual void Request() = 0 ;
    virtual ~Protocool() = default ;
};

class VehicleToInfrastructure : public Protocool
{
public:
    void DefineProtocool() override
    {
    
    }
    void Request() override
    {
        cout << "RealSubject.Request()" << endl ;
    }
};


class VehicleToVechicle : public Protocool
{
public:
    void DefineProtocool() override
    {
    
    }
    void Request() override
    {
        cout << "RealSubject.Request()" << endl ;
    }
};


class Proxy : public Protocool
{
public:
    Proxy(shared_ptr<Protocool>P) :m_protocool(P)
    {
    }
    
    void DefineProtocool() override
    {
        m_protocool->DefineProtocool();
    }
    void Request() override
    {
        m_protocool->Request();
    }
private:
    //Protocool* m_protocool;
    shared_ptr<Protocool> m_protocool;
};

void Run()
{
    Proxy p(make_shared<VehicleToInfrastructure>());
    p.Request() ;

    Proxy prox_ptr = make_shared<VehicleToVechicle>() ;
    Proxy sp = std::make_shared<VehicleToVechicle>();
    std::shared_ptr<Proxy> V = make_shared<VehicleToVechicle>(move (p));


}


int main ()
{
    Run() ;
}