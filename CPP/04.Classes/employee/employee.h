#ifndef EMPLOYEE_H
#define EMPLOYEE_H

// #pragma once 


class Employee
{
public:
    Employee ();
    Employee (std::uint16_t id ,
             std::uint16_t salary,
             std::string name)
    {
        
    }


    void setid (std::uint16_t id);
    std::uint16_t getid ();

    void setsalary (std::uint16_t salary);
    std::uint16_t getsalary ();

    void setname (std::string name);
    std::string getname ();
    void display () const ;

private:
    std::uint16_t m_id;
    std::uint16_t m_salary;
    std::string m_name;
};

#endif