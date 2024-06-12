#include <iostream>
#include <vector>
#include <memory>
#include <string>


class Employee
{
protected:
    std::string m_Name;
    double m_Salary;
public:
    Employee(const std::string name , double salary) 
        : m_Name(name) , m_Salary(salary)
    {
    }
    virtual ~Employee() = default ;
    virtual double CalculatePay() const = 0 ;
};

class FullTimeEmployee : public Employee
{
public:
    FullTimeEmployee(const std::string &name , double salary)
        : Employee(name , salary)
    {
    }
    double CalculatePay () const override
    {
        return m_Salary;
    }
};

class PartTimeEmployee : public Employee
{
public:
    PartTimeEmployee(const std::string &name , double h_worked , double h_rate)
        : Employee(name , 0) , hoursWorked(h_worked) , hoursRate(h_rate)
    {
    }
    double CalculatePay () const override
    {
        return hoursWorked * hoursRate ;
    }

private:
    double hoursWorked;
    double hoursRate;
};



class Contractor : public Employee
{
private:
    double hoursWorked;
    double hoursRate;
public:
    Contractor(const std::string& name, double h_worked, double h_rate)
        :Employee(name, 0 ) ,hoursWorked(h_worked) , hoursRate(h_rate)
        {
        }

    double CalculatePay() const override
    {
        return hoursWorked * hoursRate ;
    }
};



double totalPayroll(const  std::vector<std::shared_ptr<Employee>>& employees)
{
    double total = 0 ;
    for (const auto& emp : employees)
    {
        total += emp->CalculatePay();  //total = total + emp->CalculatePay();
    }
    return total ;
}

int main()
{
    std::vector<std::shared_ptr<Employee>> employees ;
    employees.push_back(std::make_shared<PartTimeEmployee>("Bob", 20, 15));
    employees.push_back(std::make_shared<FullTimeEmployee>("Alice" , 5000));
    employees.push_back(std::make_shared<Contractor>("Charlie", 30, 20));
    std::cout << "Total payroll: $"
              << totalPayroll(employees) << std::endl ;
    return 0 ;
}