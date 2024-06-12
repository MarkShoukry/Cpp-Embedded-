#include <iostream>
#include <limits>
#include <string>
#include <stdexcept>
#include <fstream>
#include <vector>

class Course {
private:
    std::string name;
    int credits;
    char grade;

public:
    Course(const std::string& name, int credits, char grade)
        : name(name), credits(credits), grade(grade) {}

    double calculateGradePoints() const 
    {
        switch (grade) {
            case 'A': return 4.0;
            case 'B': return 3.0;
            case 'C': return 2.0;
            case 'D': return 1.0;
            default: throw std::invalid_argument("Invalid grade.");
        }
    }

    const std::string& getName() const {
        return name;
    }

    int getCredits() const {
        return credits;
    }
};




class CourseFactory {
public:
    static Course createCourse() {
        std::string name;
        int credits;
        char grade;

        std::cout << "Course Name: ";
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::getline(std::cin, name);

        std::cout << "Credits: ";
        std::cin >> credits;

        std::cout << "Grade (e.g., A, B, C): ";
        std::cin >> grade;

        return Course(name, credits, grade);
    }
};

class CGPAFileIO 
{
private:
    CGPAFileIO() {} // Private constructor to prevent instantiation

public:
    static CGPAFileIO& getInstance() {
        static CGPAFileIO instance; // Static instance of CGPAFileIO
        return instance;
    }

    double readPreviousCGPA(const std::string& filename) const 
    {
        std::ifstream CGPAFile(filename);
        if (!CGPAFile.is_open()) {
            throw std::runtime_error("Error: Could not open file for previous CGPA data.");
        }

        double CGPA;
        CGPAFile >> CGPA;
        CGPAFile.close();
        return CGPA;
    }

    void writeCGPA(const std::string& filename, double CGPA) const 
    {
        std::ofstream CGPAFile(filename);
        if (!CGPAFile.is_open()) {
            throw std::runtime_error("Error: Could not open file to write updated CGPA.");
        }

        CGPAFile << CGPA;
        CGPAFile.close();
    }
};

// Function to calculate CGPA
double calculateCGPA(double previousCGPA, int totalPreviousCredits,
                     double currentGPA, int totalCurrentCredits) {
    return (previousCGPA * totalPreviousCredits + currentGPA * totalCurrentCredits) /
           (totalPreviousCredits + totalCurrentCredits);
}

int main() {
    int numCourses;

    // Input number of courses with error handling
    std::cout << "Enter the number of courses: ";
    while (!(std::cin >> numCourses) || numCourses <= 0) {
        std::cerr << "Error: Invalid number of courses. Please enter a positive integer: ";
    }

    std::vector<Course> courses;
    for (int i = 0; i < numCourses; ++i) {
        std::cout << "\n** Enter details for course " << i + 1 << " **\n";
        try {
            courses.push_back(CourseFactory::createCourse());
        } catch (const std::invalid_argument& e) {
            std::cerr << "Error: " << e.what() << std::endl;
            return 1;
        }
    }

    // Calculate GPA
    int totalCredits = 0;
    double totalGradePoints = 0.0;

    for (const Course& course : courses) {
        totalCredits += course.getCredits();
        totalGradePoints += course.getCredits() * course.calculateGradePoints();
    }

    double GPA = (totalCredits == 0) ? 0.0 : totalGradePoints / totalCredits;

    std::cout << "GPA for the semester: " << GPA << std::endl;

    // Calculate CGPA
    double previousCGPA;
    int totalPreviousCredits;
    std::cout << "Enter previous CGPA: ";
    std::cin >> previousCGPA;
    std::cout << "Enter total previous credits: ";
    std::cin >> totalPreviousCredits;

    double CGPA = calculateCGPA(previousCGPA, totalPreviousCredits, GPA, totalCredits);

    std::cout << "CGPA: " << CGPA << std::endl;

    // Optionally, handle CGPA calculation and file I/O using Singleton pattern
    CGPAFileIO& cgpaFileIO = CGPAFileIO::getInstance();
    // Further implementation for CGPA calculation and file I/O

    return 0;
}
