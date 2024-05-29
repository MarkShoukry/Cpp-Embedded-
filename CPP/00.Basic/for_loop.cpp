#include <iostream>
// #include <cstdio>
#include <array>
using namespace std;


// enum NUM
// {
//     one =1,
//     two,
//     three,
//     four,
//     five,
//     six,
//     seven,
//     eight,
//     nine 
// };



int main() 
{
    int num1=0, num2=0 ;
    cin >> num1 >> num2 ;
    
    string arr[9]= {"one","two","three","four","five","six","seven","eight","nine" };

    for (int16_t i = num1 ; i <= num2 ; i++)
    {
        if (i <= 9)
            {  cout << arr[i-1] << endl ;  }
       
        else if (i > 9)
            {
                    if (i % 2 == 0)
                        {cout << "even";}
                    else 
                        {cout << "odd";}   
            }
    else
    {}
    }
    return 0;
}
