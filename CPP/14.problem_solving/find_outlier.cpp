/*
Find The Parity Outlier:
https://www.codewars.com/kata/5526fc09a1bbd946250002dc/train/cpp   (codewars)
You are given an array (which will have a length of at least 3, but could be very large) containing integers. 
The array is either entirely comprised of odd integers 
or entirely comprised of even integers except for a single integer N. 
Write a method that takes the array as an argument and returns this "outlier" N.

Examples
[2, 4, 0, 100, 4, 11, 2602, 36] -->  11 (the only odd number)

[160, 3, 1719, 19, 11, 13, -21] --> 160 (the only even number)

*/


#include <iostream>
#include <vector>
using namespace std;



int FindOutlier(std::vector<int> arr)
{
    int result;
    int no_oddconut = 0 , no_evencount = 0 ;
    int no_odd = 0 , no_even = 0 ;

    for (auto array : arr)
    {
        if (array % 2 == 0)
        {
            no_evencount++;
            no_even = array ;    
        }
        else 
        {
            no_oddconut++;
            no_odd = array ;
        }
    }
    return (no_evencount == 1) ? no_even : no_odd ;
}






int main ()
{

    vector<int> arr = {160, 3, 1719, 19, 11, 13, -21} ;
    auto result =  FindOutlier(arr) ;
    cout << result ;
    return 0;
}