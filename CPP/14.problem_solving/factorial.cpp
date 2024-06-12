#include <iostream>
using namespace std;

uint16_t factorial (uint16_t num) ;



int main ()
{

    auto num = 0 ;
    cout << "Please Enter number: " ;
    cin >> num ;
    auto result = factorial (num);
    cout << "Factorial of (" << num << ") is " << result << endl ;

    return 0;
}

uint16_t factorial (uint16_t num)
{
    uint16_t result = 1 ;
    for (uint16_t i = num ; i > 0 ; i-- )
    {
        result = result * i ;
    }
    return result ;
}
