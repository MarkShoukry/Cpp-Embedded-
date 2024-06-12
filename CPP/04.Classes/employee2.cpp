/*
    class empolyee by vector 
*/

#include <iostream>
#include <vector>
#include <string>


class Empolyee
{
public:
    Empolyee(std::uint16_t id ,
             std::uint16_t salary ,
             std::string firstname ,
             std::string lastname ,
             bool bHired) : m_id(id) ,m_salary(salary) ,m_firstName(firstname) ,m_lastName(lastname) ,bHired(bHired)
    {
    }

    

    void setID(std::uint16_t id)
    {
        this->m_id = id;
    }
    void setSalary(std::uint16_t salary)
    {
        this->m_salary = salary;
    }
    void setName(std::string firstname , std::string lastname)
    {
        this->m_firstName = firstname ;
        this->m_lastName = lastname;
    }
    std::uint16_t getId ()
    {
        return this->m_id;
    }
    std::uint16_t getSalary ()
    {
        return this->m_salary;
    }
    std::string getName()
    {
        fullName = m_firstName + " " + m_lastName ;
        return fullName;
    }
    bool getHired()
    {
        return bHired;
    }

    void display()
    {
        std::cout << "Employee Id: " << getId() << ", "
                  << "Employee Name: " << getName() << ", "
                  << "Employee Salary: " << getSalary() << ", "
                  << "Employee Status: " << getHired() << std::endl;
    }

private:
    std::uint16_t m_id;
    std::uint16_t m_salary;
    std::string m_firstName;
    std::string m_lastName;
    std::string fullName ;
    bool bHired;
};


void EmployeeDataBase(std::vector<Empolyee> &DataBase)
{
    for (auto employee : DataBase)
    {
        employee.display();
    }
}



int main ()
{
    std::vector<Empolyee> database;
    Empolyee empolyeeOne(1,2500,"Mark","Shokry" , true);
    Empolyee empolyeeTwo(2,2700,"Silvey","Shokry" , true);
    Empolyee empolyeeThree(3,2900,"Abanoub","Shokry" , false);

    database.push_back(empolyeeOne);
    database.push_back(empolyeeTwo);
    database.push_back(empolyeeThree);

    EmployeeDataBase(database);
               
    
    return 0 ;
}