/*
    Description: Program to compute area of a circle
    input : redius
    formula: radius * radius * pi
    output : display area

*/

#include <iostream>
using namespace std;

int main ()
{
    float redius = 0.0 ;
    float area = 0.0 ;
    constexpr float Pi = 3.14;
    cout << "Please Enter Redius of a circle:" <<endl;
    cin >> redius;
    area = redius * redius * Pi ;
    cout << "Area of a circle is " << area <<endl;

    return  0 ;

}