#include <iostream>
using namespace std;

void welcome (string str)  // int welcome (char * str)
{
    cout << str << endl;
}

void Comeback (char * str)
{
    cout << str << endl;
}

int main ()
{

    welcome("Hello");
    Comeback("Mark");   //warning

    //function pointer
    void(*fn_ptr)(string) = & welcome;
    void(*fn_ptr2)(char *) = & Comeback;

    fn_ptr("cairo");
    fn_ptr2("Egypt");

    return 0;
}

