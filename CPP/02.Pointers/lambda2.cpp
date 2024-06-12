#include <iostream>
#include <array>
#include <algorithm>
using namespace std;




int main ()
{   
    array<int, 10> list = { 7, 5 , 9 , 1 , 0 , 3 , 11 , 2 , 8 , 12 }; 
    //lambda fn. multibly
    auto multibly_lambda = [](int &element) ->void 
    {
        element *= 2 ;
    };
    //to use fn. multibly_lambda on element of array
    for_each (list.begin(), list.end(), multibly_lambda);
    //print element
    for(auto element : list)
    {
        cout << element << " " ;
    }
    cout << endl;
    
    // to arrange element  Progressive
    sort(list.begin() , list.end(),[](int a, int b)
    {
        return a < b ;
    });
    for_each (list.begin(), list.end(), multibly_lambda);
    //print element
    for(auto element : list)
    {
        cout << element << " " ;
    }
    cout << endl;

    return 0;
}