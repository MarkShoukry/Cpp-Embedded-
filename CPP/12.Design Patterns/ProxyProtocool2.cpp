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
    Proxy(Protocool* P) :m_protocool(P)
    {
    }
    ~Proxy()
    {
        delete m_protocool;
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
    Protocool* m_protocool;
};

void Run()
{
    Proxy p(new VehicleToInfrastructure());
    p.Request();

    Proxy proxy_v2v(new VehicleToVechicle());
    proxy_v2v.Request();

}



int main() 
{
	Run();
}