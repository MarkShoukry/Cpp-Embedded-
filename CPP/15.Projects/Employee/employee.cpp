#include <iostream>
#include "employee.h"


Employee::Employee()
{

}

Employee::Employee(std::uint16_t id
            ,std::uint16_t salary
            ,std::string firstname
            ,std::string lastname
            ,bool state) 
            :mID(id), mSalary(salary), mFullName(firstname+" " + lastname) ,mState(state)
{
    
}

void Employee::SetID (std::uint16_t id)
{
    this->mID =id ;
}
std::uint16_t Employee::GetId()
{
    return this->mID ;
}


void Employee::SetSalary(std::uint16_t salary)
{
    this->mSalary = salary;
}
std::uint16_t Employee::GetSalary()
{
    return this->mSalary ;
}

void Employee::SetFullName (std::string firstname, std::string lastname)
{
    this->mFullName = firstname + " " + lastname ;
}
std::string Employee::GetFullName ()
{
    return this->mFullName ;
}

void Employee::Display() const 
{
    std::cout << "Employee ID: " << mID
              << " -Full Name: " << mFullName
              << " -Salary: " << mSalary
              << " -State " << mState << std::endl ;
}