/*
Hacker rank :problem solving
conditional statements

Output:
If 1 <= n <= 9  then print the lowercase English word
corresponding to the number otherwise, print Greater than 9.
*/

#include <iostream>
using namespace std;
#include <array>


int main ()
{
    int16_t num =0;
    string arr[]= {"one","two","three","four","five","six","seven","eight","nine"};
    cout << "please enter number\n" ;
    cin >> num;

    if (num >= 1 && num <=9)
    {
        cout  << arr[num-1];
    }
    else if (num > 9)
    {
        cout << "Greater than 9" << endl;
    }


    return 0;
}