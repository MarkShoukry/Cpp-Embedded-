#include "employee.h"
#include <vector>



int main ()
{
    std::vector<Employee> employeelist ;
    Employee emp1(1 , 1500 , "Mark" , "Shokry" , true);
    Employee emp2(2, 1000 , "Abanob" , "Ramy" , true);
    Employee emp3(3, 0 , "Mina" , "Malak" , false) ;


    employeelist.push_back(emp1);
    employeelist.push_back(emp2);
    employeelist.push_back(emp3);

    for (const auto element : employeelist)
    {   
        element.Display() ;
    } 

    return 0 ;
}