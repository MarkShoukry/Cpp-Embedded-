/*
* Given a sorted Array in ascending order need to square every element in this array
* and maintain the sorting in the same order.
* input:  {1,5 ,6 ,7 ,8 ,9 }
* output: {1,25,36,49,64,81}
* Space complexity should be O(1)
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> sortedSquaredArray(vector<int> arr);


int main ()
{
    vector<int> arr = {1,5 ,6 ,7 ,8 ,9 } ;
    vector<int> result = sortedSquaredArray(arr);

    for (auto elemnets : result)
    {
        cout << elemnets << " " ;
    }

    return 0;
}

vector<int> sortedSquaredArray(vector<int> arr)
{


    transform(arr.begin(), arr.end(), arr.begin(), [](int element)->int 
    {
        return (element * element) ;
    });

    sort(arr.begin() , arr.end());
    return arr ;
}