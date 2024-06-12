#include <iostream>
#include <map>
#include <algorithm>
#include <vector>



int main ()
{
    // vector to elements
    std::vector <int> v = {3, 3, 5, 8, 9, 8, 9, 1, 17, 10,3, 11, 17, 10};

    //sort elements by using lambda function
    std::sort(v.begin() , v.end() , [](int a , int b)->bool
    {
        return a < b ;
    } ) ;

    //using map to store frequency of elements
    std::map<int, int> freq ;

    //calculate frequency in elements
    for (auto element : v)
    {
        freq[element]++ ;       
    }

    // print elements and frequancy
    std::cout << "Element\tFrequency\n" ;
    for (auto element : freq )
    {
        std::cout << element.first << '\t' << element.second << '\n' ;
    }

    return 0;
}