#include <iostream>
#include <fstream>
#include <vector>
#include <limits>
#include <string>
#include <stdexcept>
#include <algorithm> // for find_if

using namespace std;

// Structure to represent a course
struct Course {
    string name;
    int credits;
    char grade;
};

// Function to convert letter grade to grade points (modify based on your grading system)
int getGradePoints(char grade) {
    switch (grade) {
        case 'A': return 4;
        case 'B': return 3;
        case 'C': return 2;
        case 'D': return 1;
        default: throw invalid_argument("Invalid grade entered.");
    }
}

// Function to display information for a single course
void displayCourseInfo(const Course& course) {
    cout << "Course Name: " << course.name << endl;
    cout << "Credits: " << course.credits << endl;
    cout << "Grade: " << course.grade << endl;
}

// Function to calculate GPA for a semester
pair<double, int> calculateGPA(const vector<Course>& courses) {
    int totalGradePoints = 0;
    int totalCredits = 0;

    for (const Course& course : courses) {
        totalGradePoints += course.credits * getGradePoints(course.grade);
        totalCredits += course.credits;
    }

    if (totalCredits == 0) {
        return make_pair(-1.0, 0); // Indicate error (no courses)
    } else {
        return make_pair(static_cast<double>(totalGradePoints) / totalCredits, totalCredits);
    }
}

// Function to read previous CGPA data from a file
double readPreviousCGPA(const string& filename) {
    ifstream CGPAFile(filename);
    if (!CGPAFile.is_open()) {
        throw runtime_error("Error: Could not open file for previous CGPA data.");
    }

    double CGPA;
    CGPAFile >> CGPA;
    CGPAFile.close();
    return CGPA;
}

// Function to write updated CGPA data to a file
void writeCGPA(const string& filename, double CGPA) {
    ofstream CGPAFile(filename);
    if (!CGPAFile.is_open()) {
        throw runtime_error("Error: Could not open file to write updated CGPA.");
    }

    CGPAFile << CGPA;
    CGPAFile.close();
}

// Function to validate course credits (positive integer)
bool validateCredits(int credits) {
    return credits > 0;
}

// Function to validate course name (avoid empty names)
bool validateCourseName(const string& name) {
    return !name.empty();
}

// Function to get user input for a course, handling validation
Course getCourseDetails() {
    Course course;

    cout << "Course Name: ";
    getline(cin, course.name);
    while (!validateCourseName(course.name)) {
        cerr << "Error: Course name cannot be empty. Please enter a valid name: ";
        getline(cin, course.name);
    }

    cout << "Credits: ";
    while (!(cin >> course.credits) || !validateCredits(course.credits)) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cerr << "Error: Invalid credits. Please enter a positive integer: ";
    }
    cin.ignore(); // Clear input buffer after reading credits

    cout << "Grade (e.g., A, B, C): ";
    cin >> course.grade;
  while (!(course.grade == 'A' || course.grade == 'B' || course.grade == 'C' || course.grade == 'D')) {
    cerr << "Error: Invalid grade. Please enter a valid letter grade (A, B, C, or D): ";
    cin >> course.grade;
}


    return course;
}

int main() {
    int numCourses;

    // Input number of courses with error handling
    cout << "Enter the number of courses: ";
    
    while (!(cin >> numCourses) || numCourses <= 0) {
        cerr << "Error: Invalid number of courses. Please enter a positive integer: ";
    }

    vector<Course> courses(numCourses);

    // Input course details with error handling
    for (int i = 0; i < numCourses; ++i) {
        cout << "\n** Enter details for course " << i + 1 << " **\n";
        courses[i] = getCourseDetails(); // Call function for validated input
    }

    // Calculate GPA
    pair<double, int> GPAAndCredits = calculateGPA(courses);
    double GPA = GPAAndCredits.first;
    int totalCredits = GPAAndCredits.second;

    // Display course information
    cout << "\n** Course Information **\n";
    for (const Course& course : courses) {
        displayCourseInfo(course);
        cout << endl;
    }

    // CGPA calculation (Optional)
    double CGPA = -1; // Initialize as invalid
    string fileName;

    cout << "\n** CGPA Calculation (Optional) **\n";
    cout << "Do you want to calculate CGPA (requires previous CGPA data)? (y/n): ";
    char choice;
    cin >> choice;

    if (tolower(choice) == 'y') {
        cout << "Enter the file name containing previous CGPA data: ";
        cin >> fileName;

        try {
            CGPA = readPreviousCGPA(fileName);
        } catch (const runtime_error& e) {
            cerr << e.what() << endl; // Handle file opening error
        }
    }

    if (GPA >= 0) { // Valid GPA
        if (CGPA >= 0) { // Valid previous CGPA
            try {
                CGPA = (CGPA * totalCredits + GPA) / (totalCredits + courses.size()); // Update CGPA
                cout << "\n** CGPA Updated. **\n";
            } catch (const invalid_argument& e) {
                cerr << "Error: Invalid grade encountered while calculating CGPA." << endl;
            }
        } else {
            CGPA = GPA; // First semester
        }

        cout << "\n** Semester GPA: " << GPA << " **\n";
        if (CGPA >= 0) {
            cout << "** CGPA: " << CGPA << " **\n";

            // Write updated CGPA to file (optional)
            string writeChoice;
            cout << "Do you want to write the updated CGPA to the file (" << fileName << ")? (y/n): ";
            cin >> writeChoice;

            if (tolower(writeChoice[0]) == 'y') {
                try {
                    writeCGPA(fileName, CGPA);
                    cout << "CGPA written to file successfully." << endl;
                } catch (const runtime_error& e) {
                    cerr << e.what() << endl; // Handle file writing error
                }
            }
        }
    } else {
        cerr << "Error: Could not calculate GPA due to invalid course data." << endl;
    }

    return 0;
}
