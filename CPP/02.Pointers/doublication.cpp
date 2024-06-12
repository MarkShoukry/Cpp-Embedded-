#include <iostream>
#include <array>
#include <algorithm>
using namespace std;


int main ()
{
    //array elements is int
    array<int, 10> data = {10, 6 , 7 , 12 , 17 , 9, 8 , 0 , 13 , 15};
    //lambda fn. multibly
    auto multibly_data = [](int & element) ->void 
    {
        element *= 2;
    };
    //use fn. lambda multibly in for_each
    for_each(data.begin(), data.end(), multibly_data);
    //print element of array
    for (auto element : data)
    {
        cout << element << " ";
    }
    cout << endl;
    //arrange array (Progressive)
    sort(data.begin(), data.end(), [](int a , int b)
    {
        return a < b;
    });
    //print element
    for (auto element : data)
    {
        cout << element << " ";
    }
    cout << endl;

    return 0;
}