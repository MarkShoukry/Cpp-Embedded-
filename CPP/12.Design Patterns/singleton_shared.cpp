#include <iostream>
#include <memory>
using namespace std;

class Singleton
{
public:
    static shared_ptr<Singleton> GetInstance();
    Singleton(){}
private:
   
    Singleton(const Singleton&) = delete ;
    const Singleton& operator=(const Singleton&);
    static shared_ptr<Singleton> instance;
};

shared_ptr<Singleton> Singleton::instance = 0 ;

shared_ptr<Singleton> Singleton::GetInstance()
{
    if(instance == nullptr)
    {
        instance = make_shared<Singleton>();
        cout << "GetInstance(): first instance\n" ;
        return instance ;
    }
    else {
        cout << "GetInstance(): previous instance\n" ;
        return instance;
    }
}




int main ()
{
    shared_ptr<Singleton> s1 = Singleton::GetInstance();
    shared_ptr<Singleton> s2 = Singleton::GetInstance();

    return 0;
}