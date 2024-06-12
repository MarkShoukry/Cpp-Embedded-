#include <iostream>


class Employee
{
public:
    virtual void print () const 
    {
        std::cout << "Employee"  << std::endl ;
    }   
};


class Manager : public Employee
{
public:
    virtual void print () const
    {
        std::cout << "Manager" ;
    }
};





int main ()
{
    Employee e1 ;
    Manager m1 ;
    Employee *p;
    e1.print();
    m1.print();
    
    std::cout << std::endl; 

    p = &e1 ;
    p->print();
    p= &m1 ;
    p->print();



    return 0 ;
}