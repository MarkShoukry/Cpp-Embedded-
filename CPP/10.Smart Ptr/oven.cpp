#include <iostream>
using namespace std;

// static local variable 
// static global variable
// static function 
// static method (in class) : 
//method to be used without the need of constructing an object

static int default_temp = 25 ;

static int MaxTemp(int sensor_reading)
{
    static int max = 0 ;
    max = max > sensor_reading ? max : sensor_reading ;
    return max ; 
}


int main ()
{
    int sensor_reading = 10 ;     
    auto max = MaxTemp(sensor_reading) ;
    cout << "Max is " << max  << endl ;
    
    sensor_reading = 90 ;
    max =MaxTemp(sensor_reading);
    cout << "Max is " << max << endl;

    sensor_reading = 45 ;
    max =MaxTemp(sensor_reading);
    cout << "Max is " << max << endl ;

   

    return 0 ;
}