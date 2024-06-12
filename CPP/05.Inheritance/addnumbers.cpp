/*
function of add numbers by function overloading (polymorphism)
*/
#include <iostream>
using namespace std;

int add(int a, int b)
{
    return a + b ;
}

int add (int a , int b , int c)
{
    return a + b + c ;
}

double add (double a , double b)
{
    return a + b ;
}


int main ()
{
    int a = 5 , b = 7 , c = 10 ;
    double n1 = 2.13 , n2 = 5.86 ;

    cout << "a + b = "       << add (a,b)      << endl ;
    cout << "a + b + c = "   << add (a,b,c)    << endl ; 
    cout << "n1 + n2 = "     << add (n1, n2)   << endl ;


    return 0;
}