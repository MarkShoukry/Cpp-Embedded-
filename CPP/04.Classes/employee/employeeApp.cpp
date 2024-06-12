#include <iostream>
#include "employee.h"


int main ()
{
    Employee employeeOne;
    employeeOne.setid(1);
    employeeOne.setsalary(250);
    employeeOne.setname("Mark Shokry");

    employeeOne.display();



    return 0;
}


/*
To terminal :
    PS C:\0_M\C++\Project\04.classes\employee>     g++ -o employee employee.cpp employeeApp.cpp
    PS C:\0_M\C++\Project\04.classes\employee>     ./employee

*/