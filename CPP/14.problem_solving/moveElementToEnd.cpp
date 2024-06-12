
/*
* Given an array has Integer values and include multiple values of the same element 
* need to move the a given integer value to the end of the array.
* example 1,2,3,2,10,9,2,27,30,17,8,9
* answer  1 3 10 9 27 30 17 8 9 2 2 2 
* Time complexity should be O(n)
*/

#include <iostream>
#include <vector>
using namespace std;

vector<int> moveElementToEnd (vector<int> arr ,int ToMove);


int main ()
{
    vector<int> data = {1,2,3,2,10,9,2,27,30,17,8,9};
    auto result = moveElementToEnd(data, 2);
    for (auto elements : result)
    {
        cout << elements << " " ;
    }
    
    return 0;
}



vector<int> moveElementToEnd (vector<int> arr ,int ToMove)
{
    int front = 0 , end = arr.size()-1 ;
    vector<int> out(arr.size(),0) ;

    for (int i = 0 ; i < arr.size() ; i ++ )
    {
        if (arr[i] == ToMove)
        {
            out[end] = ToMove ;
            end--;
        }
        else
        {
            out[front] = arr[i] ;
            front++ ;
        }
    }
    return out ;
}