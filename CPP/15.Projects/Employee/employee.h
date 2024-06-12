#pragma once 
#include <string>



class Employee
{
public:
    Employee();
    Employee(std::uint16_t id
            ,std::uint16_t salary
            ,std::string firstname
            ,std::string lastname
            ,bool state);
    
    void SetID(std::uint16_t  id);
    std::uint16_t GetId();

    void SetSalary(std::uint16_t salary);
    std::uint16_t GetSalary();

    void SetFullName (std::string firstname, std::string lastname);
    std::string GetFullName ();

    void Display() const ;


private:
    std::uint16_t mID;
    std::uint16_t mSalary;
    std::string  mFullName;
    bool mState;


};