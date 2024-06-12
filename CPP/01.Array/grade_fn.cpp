/*
* print grade of students as literels:
+ if grade 50 to 65 than student has passed
+ if grade 65 to 75 than student has good
+ if grade 75 to 85 than student has very good
+ if grade 85 to 100 than student has excellent
*/
#include <iostream>

// namespace 
namespace Evalaution
{
    std::uint16_t grade =0;
    std::string evalaution = ""; //evalaution ("")

    void getEvalauat ()
    {
        // Get input from user
    std::cout << "Please Enter Grade of student" << std::endl;
    std::cin >> Evalaution::grade;

    //evaluate grade
    if (Evalaution::grade >= 50 && Evalaution::grade < 65)
        {
            Evalaution::evalaution = "Passed";
        }
    else if (Evalaution::grade >= 65 && Evalaution::grade < 75)
        {
            Evalaution::evalaution = "Good";
        }     
    else if (Evalaution::grade >= 75 && Evalaution::grade < 85)
        {
            Evalaution::evalaution = "Very Good";
        }     
    else if (Evalaution::grade >= 85 && Evalaution::grade <= 100)
        {
            Evalaution::evalaution = "Excellant" ;
        } 
    else if (Evalaution::grade < 50)
        {
            Evalaution::evalaution = "Failed";
        }    
    else
        {
           Evalaution::evalaution = "try again" ;
        }     


    //print the outcome
    std::cout << "Grade of student is " << Evalaution::evalaution << std::endl; 


    }

}


int main ()
{   
    std::uint16_t index =0;
    
    
    while ( index < 5)
    {
    
        Evalaution::getEvalauat();
    
    index++;
    }
   

    return 0;
}


