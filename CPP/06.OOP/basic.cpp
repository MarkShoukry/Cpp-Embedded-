/*
Inheritance:

       is_a :-
*Private inheritance
*Multiple inheritance
*Public inheritance


UML : Unified Modeling Language (Strong Containment) 
1- Inheritance (is_a) 
2- Accosiation (has_a) (strong/weak)_Containment


super_Class <----is_a-------  Sub_Class
Animal <-------is_a--------- Cat

*/




#include <iostream>


class super
{
public:
    virtual void method1()
    {
        std::cout << "Super" << std::endl ; 
    }
};

class sub :public super
{
public:
    virtual void method2 () 
    {
        std::cout << "sub is a super" <<std::endl ;
    }
};



int main ()
{   
    super *p = new super() ;
    p->method1() ;

    p = new sub();
    p->method1();
    //p->method2();              //     ......Error ('class super' has no member named 'method2')
    ((sub *)p)->method1();
    ((sub *)p)->method2(); 

    return 0 ;
}