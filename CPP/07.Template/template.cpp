#include <iostream>

using namespace std;


template<typename T>
T max_function(const T& first , const T& second)
{
    return first > second ? first : second ;
}

int main ()
{
    float x = 0 ;
    float y = 0 ; 

    cout << "Please Enter First and Second number :" << endl ;
    cin >> x >> y ;


    cout << "max_fun = " << max_function(x, y) << endl ;


    return 0 ;
}