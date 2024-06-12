//Sadeen_strategy
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std; 

class Students
{
    public :
    string Name;
    string Address ;
    uint16_t ID;
};




int main ()
{
    vector<Students>student(2);
    student[0].Name = "Mark Shokry" ;
    student[0].Address = "Cairo" ;
    student[0].ID = 1 ;

    student[1].Name = "Omar Khaled" ;
    student[1].Address = "New Cairo" ;
    student[1].ID = 2 ;

    Students last , S1 ;
    last.Name = "Ali Mohmed" ;
    last.Address = "Gieza";
    last.ID = 8;


    S1.Name = "Omnia Ibrahim" ;
    S1.Address = "Cairo";
    S1.ID = 6 ;

    student.push_back(last) ;
    student.push_back(S1) ;


    sort(student.begin() , student.end(), [](Students a , Students b) 
    {
        return a.ID < b.ID ; 
    });
    for (auto elements : student)
    {
        cout <<"Name: " <<  elements.Name << " ---Address: " << elements.Address << " ---ID: " << elements.ID   ;
        cout << endl ;
    }

     


    return  0 ;
}