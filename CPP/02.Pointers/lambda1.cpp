#include <iostream>
using namespace std;

int main ()
{
    int var = 10;
    string name("Mark");
    //lambda function
    auto lambda = [&var , name]() ->void
    {
        cout << name << " " << var << endl;
    };
    lambda();

    return 0 ;
}