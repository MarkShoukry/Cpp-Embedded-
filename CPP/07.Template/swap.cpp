#include <iostream>




template <class T>
void swap (T& first , T& second)
{
    T temp = first ;  //copy constructor for temp
    first = second ; //assignment operator
    second = temp ;
}



class Person 
{
public:
    Person(std::string name) : m_name(name)
    {
    }
    
    // //copy constructor:
    // Person(Person& personcopy)
    // {
    //     this->m_name = personcopy.m_name ; 
    // }

    std::string getname ()
    {
        return this->m_name ;
    }

    
    // //Assignment operator:
    // Person& operator=(Person& rhs)
    // { this->m_name = rhs.m_name ;
    //     return *this ;
    // }
    


private :
    std::string m_name ;
};


int main ()
{
    int x = 23 , y = 45 ;
    std::cout << "Befor swap:  " ;
    std::cout << "X: " << x << " Y: " << y << std::endl ;

    swap(x , y) ;
    std::cout << "After swap:  " ;
    std::cout << "X: " << x << " Y: " << y << std::endl ;



    Person p1("Mark") ;
    Person p2("Pola") ;
    
    std::cout << "Befor swap:  " ;
    std::cout << "P1: " << p1.getname() << " p2: " << p2.getname() << std::endl ;
    swap(p1,p2) ;
    std::cout << "After swap:  " ;
    std::cout << "P1: " << p1.getname() << " p2: " << p2.getname() << std::endl ;


    return 0 ;
}