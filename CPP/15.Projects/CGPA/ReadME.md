# CGPA Calculator
A student’s cumulative grade point average (CGPA) can be determined using the C++ program CGPA Calculator. The user’s input is used to compute the CGPA, which includes information like the number of courses taken and the grades earned in each one. The program also shows each student’s overall course grade. CGPA Calculator calculates a student’s Cumulative Grade Point Average (CGPA) from the given exam results. The program can show the individual grades of each course, calculate total credits and total grade points achieved, determine the GPA for the semester, and based on all the data, it can generate and present the CGPA of the student. 

Technologies Required: C++ programming language, Data Structures, Basic Searching & Sorting algorithms, Basic Arithmetic Operations and formulas, and File Handling ( I/O Streams ).

------
------

## 1. Define the Data Structures:
- You'll need data structures to store information about each course, such as course name, credits, and grade obtained. You can use structures or classes for this purpose.

## 2.Input Module:
- Create a module to take input from the user. This input will include the number of courses, course details (name, credits, grade), and possibly other relevant information like the grading scale.

## 3.Calculate Total Grade Points and Credits:
- Calculate the total grade points earned by multiplying the grade obtained in each course with the credits of that course.
- Calculate the total credits by summing up the credits of all courses.

## 4.Calculate GPA for the Semester:
- Divide the total grade points earned by the total credits to get the GPA for the semester.

## 5.File Handling:
- Optionally, you can implement file handling to store the input data or the calculated CGPA in a file for future reference.

## 6.CGPA Calculation:
- If you want to calculate CGPA, you need to keep track of cumulative total grade points and cumulative total credits across multiple semesters.
- You can add functionality to read previous CGPA from a file, if available, and update it with the current semester's GPA to get the new CGPA.
- Finally, you can write the updated CGPA back to the file.

## 7.Display Module:
- Create a module to display the individual grades of each course, total credits, total grade points, GPA for the semester, and CGPA (if required).

## 8.Searching & Sorting (Optional):
- Depending on the requirements, you might need to implement searching and sorting algorithms for tasks such as searching for a particular course or sorting the courses based on credits or grades.