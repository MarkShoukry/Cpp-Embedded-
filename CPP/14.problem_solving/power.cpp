/*
https://www.codewars.com/kata/57a083a57cb1f31db7000028        (codewars)
Complete the function that takes a non-negative integer n as input, 
and returns a list of all the powers of 2 with the exponent ranging from 0 to n ( inclusive ).

Examples
n = 0  ==> [1]        # [2^0]
n = 1  ==> [1, 2]     # [2^0, 2^1]
n = 2  ==> [1, 2, 4]  # [2^0, 2^1, 2^2]
*/

#include <iostream>
#include <vector>
#include <cstdint>
#include <cmath>
using namespace std;



std::vector<uint64_t> powers_of_two(int n) 
{
    vector<uint64_t> result ;
    for (auto i = 0 ; i <= n ; i++)
    {
        result.push_back(pow(2,i)) ;
    }
  return result;
}


int main ()
{
    //Testing
    vector<uint64_t> numbers1 = powers_of_two(0);
    vector<uint64_t> numbers2 = powers_of_two(1);
    vector<uint64_t> numbers3 = powers_of_two(2);
    vector<uint64_t> numbers4 = powers_of_two(4);
    vector<uint64_t> numbers5 = powers_of_two(8);
    vector<uint64_t> numbers6 = powers_of_two(10);


    for(auto num : numbers1)
    {
        cout << num << " " ;
    }
    cout << "\n" ;


    for(auto num : numbers2)
    {
        cout << num << " " ;
    }
    cout << "\n" ;

    for(auto num : numbers3)
    {
        cout << num << " " ;
    }
    cout << "\n" ;


    for(auto num : numbers4)
    {
        cout << num << " " ;
    }
    cout << "\n" ;
    
    for(auto num : numbers5)
    {
        cout << num << " " ;
    }
    cout << "\n" ;

    for(auto num : numbers6)
    {
        cout << num << " " ;
    }
    cout << "\n" ;


    return 0;
}