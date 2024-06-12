#include <iostream>
#include <vector>
#include <string>
#include <limits>

class Course {
private:
    std::string name;
    int credits;
    double grade;

public:
    Course(const std::string& name, int credits, double grade)
        : name(name), credits(credits), grade(grade) {}

    std::string getName() const {
        return name;
    }

    int getCredits() const {
        return credits;
    }

    double getGrade() const {
        return grade;
    }

    double calculateGradePoints() const {
        // Assuming a standard 4.0 scale
        // Convert the grade to grade points
        if (grade >= 90) return 4.0;
        else if (grade >= 80) return 3.0;
        else if (grade >= 70) return 2.0;
        else if (grade >= 60) return 1.0;
        else return 0.0; // Fail
    }
};

bool validateGrade(double grade) {
    return (grade >= 0 && grade <= 100);
}

bool validateCredits(int credits) {
    return (credits > 0);
}

void clearInputBuffer() {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

Course inputCourseDetails(int courseNumber) {
    std::string name;
    int credits;
    double grade;

    std::cout << "\nEnter details for Course #" << courseNumber << ":" << std::endl;

    std::cout << "Enter course name: ";
    clearInputBuffer();
    std::getline(std::cin, name);

    std::cout << "Enter credits: ";
    while (!(std::cin >> credits) || !validateCredits(credits)) {
        std::cout << "Invalid input. Credits must be a positive integer. Please try again: ";
        clearInputBuffer();
    }

    std::cout << "Enter grade: ";
    while (!(std::cin >> grade) || !validateGrade(grade)) {
        std::cout << "Invalid input. Grade must be between 0 and 100. Please try again: ";
        clearInputBuffer();
    }

    return Course(name, credits, grade);
}

int main() {
    std::vector<Course> courses;

    int numCourses;
    std::cout << "Welcome to GPA Calculator" << std::endl;
    std::cout << "Enter the number of courses: ";
    while (!(std::cin >> numCourses) || numCourses <= 0) {
        std::cout << "Invalid input. Number of courses must be a positive integer. Please try again: ";
        clearInputBuffer();
    }

    for (int i = 1; i <= numCourses; ++i) {
        courses.push_back(inputCourseDetails(i));
    }

    // Calculate total grade points and total credits
    double totalGradePoints = 0.0;
    int totalCredits = 0;

    for (const auto& course : courses) {
        totalGradePoints += course.calculateGradePoints() * course.getCredits();
        totalCredits += course.getCredits();
    }

    // Calculate GPA for the semester
    double gpa = totalGradePoints / totalCredits;

    // Read previous CGPA from the user
    double previousCGPA;
    std::cout << "Enter previous CGPA: ";
    std::cin >> previousCGPA;

    // Calculate CGPA
    double cgpa = (previousCGPA * totalCredits + gpa * numCourses) / (totalCredits + numCourses);

    std::cout << "\nCGPA: " << cgpa << std::endl;

    return 0;
}
