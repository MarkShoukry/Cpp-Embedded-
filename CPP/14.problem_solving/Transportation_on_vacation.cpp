/*
codewars : https://www.codewars.com/kata/568d0dd208ee69389d000016/train/cpp

After a hard quarter in the office you decide to get some rest on a vacation. 
So you will book a flight for you and your girlfriend and try to leave all the mess behind you.

You will need a rental car in order for you to get around in your vacation. 
The manager of the car rental makes you some good offers.

Every day you rent the car costs $40. 
If you rent the car for 7 or more days, you get $50 off your total. 
Alternatively, if you rent the car for 3 or more days, you get $20 off your total.

Write a code that gives out the total amount for different days(d).

*/

#include <iostream>

// int rental_car_cost2(int d){
//   return d >= 7? d * 40 - 50:  d >= 3? d * 40 - 20: d * 40;
// }
int rental_car_cost(int d)
{
    constexpr int Car_cost_per_Day = 40 ;
    int Total = d * Car_cost_per_Day ;

    if (d >= 7)
    {
        Total = Total - 50;    
    }
    else if (d < 7 && d >= 3 )
    {
        Total = Total - 20 ;
    }
    else if (d < 3 && d >= 1 )
    {
        Total ;
    }
    else 
    {
        std::cout << "Error, Please Try Again\n" ;
    }

  return Total ;
}

int main ()
{
    int day = 0 ;
    std::cout  << "How many Days you rent a car ? \n";
    std::cin >> day ;
    std::cout << "Bill = " << rental_car_cost(day) << " $";
    
    return 0 ; 
}