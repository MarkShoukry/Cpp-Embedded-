    #include <iostream>
    #include "employee.h"   

    
    Employee::Employee ()
    {

    }

    void Employee::setid (std::uint16_t id)
    {
        this->m_id = id ;
    } 
    std::uint16_t Employee::getid ()
    {
        return this->m_id ;
    }

    void Employee::setsalary (std::uint16_t salary)
    {
        this->m_salary = salary ;
    }
    std::uint16_t Employee::getsalary ()
    {
        return this->m_salary ;
    }

    void Employee::setname (std::string name)
    {
        this->m_name = name ; 
    }
    std::string Employee::getname ()
    {
        return this->m_name ;
    }

    void Employee::display () const
    {
        std::cout << "Employee Id: "     << m_id       << std::endl
                  << "Employee Name: "   << m_name     << std::endl
                  << "Employee Salay: "  << m_salary   << std::endl;
    }