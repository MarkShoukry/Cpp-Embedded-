#include <iostream>



class Employee1
{
public:
    Employee1(std::uint16_t id,
              std::uint16_t Salary,
              std::string Fullname,
              bool status) : mId(id) ,mSalary(Salary) , mFullname(Fullname) , mstatus(status)
    
    {
        std::cout << "Employee Id: "      << mId          << ", "
                  <<"Employee Name: "     << mFullname    << ", "
                  <<"Employee Salary: "   << mSalary      << ", "
                  <<"Employee Status: "   << mstatus      << std::endl; 

    }

private:
    std::uint16_t mId;
    std::uint16_t mSalary;
    std::string mFullname;
    bool mstatus;
};


int main ()
{
    Employee1 employeeOne (1, 250 , "Mark Shokry" , true);
    Employee1 employeetwo (2, 270 , "Silvey Shokry" , true);

    return 0;
}