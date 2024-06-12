/*
                            |-----sub------|
|_________|<----------------|--|_________|-|
|__super__|                 |  |__super__|-|
|_________|<----------------|--|_________|-|
                            |______________|


*/




#include <iostream>


class super
{
public:
    virtual void method1() //final != virtual
    {
        std::cout << "Super" << std::endl ; 
    }
};

class sub :public super
{
public:
    virtual void method1 () 
    {
        std::cout << "sub is a super" <<std::endl ;
    }
};



int main ()
{   
    sub sub;
    super super = sub ;

    super.method1() ;
    sub.method1();
     

    return 0 ;
}