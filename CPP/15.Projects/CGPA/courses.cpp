#include "courses.h" 




    Courses::Courses(std::string name, std::uint16_t credit , char grade)
            : mName(name) , CreditHours(credit) , mGrade(grade) 
    {

    }

    std::string& Courses::GetName() 
    {
        return this->mName ;
    }

    std::uint16_t Courses::GetCredit() const
    {
        return CreditHours ;
    }


    double Courses::CalculateGradePoints() const
    {   
        // Assuming a standard 4.0 scale
        // Convert the grade to grade points
        switch (mGrade)     
        {
            case 'A': return 4.0;
            case 'B': return 3.0;
            case 'C': return 2.0;
            case 'D': return 1.0;
            default:throw std::invalid_argument("Invalid Grade. ");
        }  
    }



