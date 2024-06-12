#include <iostream>
using namespace std;

class Singleton
{
public:
    static Singleton * GetInstance();
private:
    Singleton(){}
    Singleton(const Singleton&);
    const Singleton& operator=(const Singleton&);
    static Singleton* instance;
};

Singleton* Singleton::instance = 0 ;

Singleton* Singleton::GetInstance()
{
    if(!instance)
    {
        instance = new Singleton();
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
    Singleton *s1 = Singleton::GetInstance();
    Singleton *s2 = Singleton::GetInstance();

    return 0;
}