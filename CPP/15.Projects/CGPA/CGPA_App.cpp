#include "courses.h"
#include "CourseFactory.h"
#include "CGPAFileIO.h"
#include <vector>


int main ()
{
    
    std::vector<Courses> courses;
    std::uint16_t numCourses;
    // calculate GPA
    std::uint16_t totalCredits = 0 ;
    double totalGradePoints = 0.0 ;

    double GPA = 0 , CGPA = 0 ;
    double previousCGPA;
    int totalPreviousCredits;

    //Input number of courses with error handling
    std::cout << "Enter the number of courses: " ;
    while (!(std::cin >> numCourses) || numCourses <= 0)
    {
        std::cerr << "Error: Invalid number of courses. please enter a positive intefer: " ;
    }

    for (int i = 0 ; i < numCourses; i++)
    {
        std::cout << "\n**Enter details for course " << i + 1 << " **\n" ;
        courses.push_back(CourseFactory::CreatCourse());
    }


    for (const auto& course : courses)
    {
        totalCredits += course.GetCredit();
        totalGradePoints += course.GetCredit() * course.CalculateGradePoints();
    }
    GPA = (totalCredits == 0) ? 0.0 : totalGradePoints / totalCredits;



    std::cout << "Enter previous CGPA: " ;
    std::cin >> previousCGPA;
    std::cout << "Enetr total previous credits: " ;
    std::cin >> totalPreviousCredits;

    CGPA = CalculateCGPA(previousCGPA, totalPreviousCredits, GPA, totalCredits);

    std::cout << "CGPA: " << CGPA << std::endl ;

    CGPAFileIO& cgpaFileIO = CGPAFileIO::GetInstance();


    
    return 0 ;
}