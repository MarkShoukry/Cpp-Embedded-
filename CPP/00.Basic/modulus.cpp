//program to check even or odd :

#include <iostream>
using namespace std;

int main()
{
    int16_t num = 0;
    constexpr int16_t num_of_mod = 2;
    constexpr int16_t zero_num = 0 ;
   
    // for (int i =0 ; i <2 ; i++)
    // {
    // cout << "please Enter Number To check" << endl;
    // cin >> num ;
    // if (num % num_of_mod == zero_num)
    // {cout << "This number is Even" << endl;}
    // else
    // {cout << "This number is Odd" << endl;}
    //   } 
    int i = 0;
    while (i < 2)
    {
        cout << "please Enter Number To check" << endl;
    cin >> num ;
    if (num % num_of_mod == zero_num)
    {cout << "This number is Even" << endl;}
    else
    {cout << "This number is Odd" << endl;}
    i++;
    }
    

    return 0;
}