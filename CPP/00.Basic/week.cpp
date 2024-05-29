// program to defines an enumeration representing the days of the week and 
//calculates the day of the week after ten days, starting from a given day. 
#include <iostream>
using namespace std;


int main ()
{
    enum week
    {
        MONDAY =1,
        TUESDAY,
        WEDNESDAY,
        THURSDAY,
        FRIDAY,
        SATURDAY,
        SUNDAY,
        MAX_WEEK_DAYS = 7
    };
    uint16_t current_day = SATURDAY;
    // unsigned short current_day ;
    // cout << "Please Enter Current day Capital Litters" <<endl;
    // cin >> current_day ;
    uint16_t day_after_ten_days = (current_day + 10) % MAX_WEEK_DAYS;
    string day ;
    /*
    if (day_after_ten_days == MONDAY)
    {day = "Monday";}
    else if (day_after_ten_days == TUESDAY)
    {day = "Tuesday";}
    else if (day_after_ten_days == WEDNESDAY)
    {day = "Wednesday";}
    else if (day_after_ten_days == THURSDAY)
    {day = "Thursday";}
    else if (day_after_ten_days == FRIDAY)
    {day = "Friday";}
    else if (day_after_ten_days == SATURDAY)
    {day = "Saturday";}
    else if (day_after_ten_days == SUNDAY)
    {day = "Sunday";}
    else 
    {cout << "Error";}
    cout << "Starting from Friday then the day after ten days is  "
    << day << endl;
*/

    // Switch and break:
    switch (day_after_ten_days)
    {
    case MONDAY:
        day = "Monday" ;
        break;

    case TUESDAY:
        day = "Tuesday";
        break;    

    case WEDNESDAY:
        day = "Wednesday";
        break;

    case THURSDAY:
        day = "Thursday";
        break;

    case FRIDAY:
        day = "Friday";
        break;

    case SATURDAY:
        day = "Saturday";
        break;

    case SUNDAY:
        day = "Sunday";
        break;        

    default:
        day = "";
        cout << "Error";
    break;
    }
    cout << "Starting from Friday then the day after ten days is "
    << day << endl;

    return 0;
}
