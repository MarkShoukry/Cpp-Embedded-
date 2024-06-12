#include <iostream>
#include <array>
#include <algorithm>
using namespace std;




int main ()
{
    array<int, 5> list = {24 , 7 , 89 , 0 , 19 };

    //Arrange numbes Descending (from end to first)
    cout << "Arrange numbers Descending" << endl;
    sort (list.begin() , list.end() , [](int &a , int &b) ->bool     //By referance ------> //(int a , int b) by value
    {
        return a > b  ; //tarnary operator

    });
    //print element
    for (auto element : list)
    {
        cout << element << " " ;
    }
    cout << endl;


    //Arrange numbers Progressive (from first to end)
    cout << "Arrange numbers Progressive" << endl;
    //sort (list.begin() , list.end());
    sort (list.begin() , list.end() , [](int a , int b) ->bool     // By value
    {
        return a < b  ; //tarnary operator

    });
    //print element
    for (auto element : list)
    {
        cout << element << " " ;
    }
    cout << endl;


    //for_each  : to do something on all elements 
    cout << "All numbers double" << endl;
    for_each (list.begin(), list.end(), [](int &element) ->void
    {
        element *= 2 ; //element = element * 2
    });
    //print element
    for (auto element : list)
    {
        cout << element << " " ;
    }
    cout << endl;

    return 0;
}