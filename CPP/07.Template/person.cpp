#include <iostream>
#include <string>


template<class T>
T max( T first ,  T second)
{
    T temp = first > second ;
    return temp ;
}

template<typename T>
void swap(T& first , T& second)
{
    T temp = first ;
    first = second ;
    second = temp ;
}






class Person 
{
public:
    Person(std::string name , std::uint16_t age) : m_name(name) , m_age(age)
    {
    }
    
    //copy constructor:
    Person(Person& personcopy)
    {
        this->m_name = personcopy.m_name ; 
        this->m_age = personcopy.m_age ;
    }
   
    //Assignment operator:
    Person& operator=(Person& rhs)
    { 
        this->m_name = rhs.m_name ;
        this->m_age = rhs.m_age ;
        return *this ;
    }

    bool operator>(Person& rhs) 
    {
        return m_age > rhs.m_age ;
    }


    //Error ? can't return person in (>) operator return bool
    // Person& operator>(Person& rhs)
    // {   return this->mAge > rhs.mAge? *this : rhs;    }


    
    std::string getname ()
    {
        return this->m_name ;
    }
    std::uint16_t getAge ()
    {
        return this->m_age ;
    }




private :
    std::string m_name ;
    std::uint16_t m_age ;
};




int main ()
{
    
    Person p1("Mark shokry" , 90);
    Person p2("Pola Maged" , 129);
        
    std::cout << "Befor swap:  " ;
    std::cout << "P1: " << p1.getname() << "     p2: " << p2.getname() << std::endl ;
   
   swap(p1,p2);
   
    std::cout << "After swap:  " ;
    std::cout << "P1: " << p1.getname() << "     p2: " << p2.getname() << std::endl ;


    auto older_person = p1 > p2 ? p1 : p2;

    std::cout << "Name: " << older_person.getname() 
              << " Age: " << older_person.getAge()
              << std::endl ;



    // auto max_person = max<Person>(p1 , p2);
   


    return 0 ;
}