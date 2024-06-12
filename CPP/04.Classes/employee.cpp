/*
* create a class of employee which has proberties of
  ---> id , fullname (firstname , lastname) , salary , hiringstatus

* and behaviors of :
   ---> setId, getId  , setSalary, getSalary  , setStatus, getStatus
*/

#include <iostream>

class Employee
{
public:
    Employee()
    {

    }

    //function of id
    void setId (std::uint16_t id)
    {
        this->mId = id;
    }
    std::uint16_t getId ()
    {
        return this->mId;
    }
    //function of salary
    void setSalary (std::uint16_t salary)
    {
        this->mSalary = salary ;
    }
    std::uint16_t getSalary ()
    {
        return this->mSalary;
    }


    //function of fullname
    void setName (std::string firstname , std::string lastname)
    {
        this->mFullname = firstname + " " + lastname;
    }
    std::string getName()
    {
        return this->mFullname;
    }


private:
    std::uint16_t mId;
    std::uint16_t mSalary;
    std::string mFullname;
    bool mstatus;

};


int main ()
{
    constexpr bool HIRED = true;
    Employee employeeOne;
    employeeOne.setId(1);
    employeeOne.setSalary(250);
    employeeOne.setName("Mark", "Shokry");

    std::cout << "Employee Id: "    << employeeOne.getId()     << ", " 
              << "Employee Name: "  << employeeOne.getName()   << ", "
              << "Employee Salay: " << employeeOne.getSalary() << std::endl;

    return 0;
}