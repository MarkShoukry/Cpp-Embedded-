#pragma once 
#include <iostream>
#include <string>

class Courses 
{
public:
    Courses(std::string name, std::uint16_t credit , char grade) ;
    std::string& GetName ()   ;
    std::uint16_t GetCredit() const ;
    double CalculateGradePoints () const ;

private:
    std::string mName;
    std::uint16_t CreditHours ;
    char mGrade;
};
