#include <iostream>
using namespace std; 

// Function to track maximum temperature using a static variable
int Max_temp(int temp)
{
    static int max = 0 ;  // Static variable to retain the maximum temperature
    max = max > temp ? max : temp ;
    return max ;
}

// Function to track maximum temperature without using a static variable
int maxTemp(int mtemp)
{
    int max = 0 ; // Local variable to track maximum temperature
    max = max > mtemp ? max : mtemp ;
    return max ;
}

int main ()
{
    // Demonstration with static variable
    cout << "With Static:" << endl  ;
    int temperature = 80 ;
    int max = Max_temp(temperature) ;
    cout << max << endl ; 
    temperature = 50 ;
    max = Max_temp(temperature) ;
    cout << max << endl ; 

    // Demonstration without static variable
    cout << "Without Static:" << endl  ;
    int temperature1 = 100 ;
    int max1 = maxTemp(temperature) ;
    cout << max1 << endl ; 
    temperature1 = 40 ;
    max = maxTemp(temperature1) ;
    cout << max1 << endl ; 

    return 0 ;
}