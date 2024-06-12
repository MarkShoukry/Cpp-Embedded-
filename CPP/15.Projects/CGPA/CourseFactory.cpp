#include "CourseFactory.h"

Courses CourseFactory::CreatCourse() 
{
    std::string name;
    int credits;
    char grade;


    std::cout << "Course Name: ";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::getline(std::cin, name);

    std::cout << "Credits: " ;
    std::cin >> credits;

    std::cout << "Grade (A, B, C, D): " ;
    std::cin >> grade;

    return Courses(name, credits, grade) ;

}

