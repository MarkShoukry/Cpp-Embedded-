/*
    Description: Program to get distance of miles by km
    input : distance by miles
    formula: distance by miles * 1.6
    output : distance by km

 
*/
#include <iostream>

int main ()
{
    int16_t Distance__Miles = 0;
    std::cout << "Please Enter Distance by miles" <<std::endl;
    std::cin >> Distance__Miles ;
    constexpr float Miles_To_Km = 1.6 ;

    float Distance__Km = Distance__Miles * Miles_To_Km ;

    std:: cout << "Distance by Km is " << Distance__Km <<std:: endl;  
    return 0 ;

}