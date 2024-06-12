/*
codewars: https://www.codewars.com/kata/5899dc03bc95b1bf1b0000ad/train/cpp

Given a set of numbers, return the additive inverse of each. 
Each positive becomes negatives, and the negatives become positives.

[1, 2, 3, 4, 5] --> [-1, -2, -3, -4, -5]
[1, -2, 3, -4, 5] --> [-1, 2, -3, 4, -5]
[] --> []

*/
#include <iostream>
#include <vector>

std::vector<int> invert(std::vector<int> values)
{
    for (int i = 0 ; i < values.size() ; i ++)
    {
        values[i] *= - 1 ;
    }
    //for(int &a:values)   a = -a;
    //  transform(values.begin(), values.end(), values.begin(), std::negate<int>());;

    return values;
}

int main ()
{
    std::vector<int> values = {1, 2 , -3 , -4 , 5 };
    auto result = invert(values);
    for (auto element : result)
    {
        std::cout << element << " " ;
    }


    return 0 ; 
}