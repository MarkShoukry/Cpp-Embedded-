/*
This C++ program differentiates between the concrete and abstract class. 

An abstract class is meant to be used as a base class where some or
all functions are declared purely virtual and hence can not be instantiated. 

A concrete class is an ordinary class which has no purely virtual functions and hence can be instantiated.


Here is the source code of the C++ program which differentiates between the concrete and abstract class. 
*/

/*
* C++ Program to differentiate between concrete class and abstract class
*/
#include <iostream>
#include <string>
using namespace std;


class Abstract 
    {
    private:
        string info;
    public:
        virtual void printContent() = 0;
    };

class Concrete 
    {
    private:
        string info;
    public:
        Concrete(string s) : info(s) { }
        void printContent() 
        {
        cout << "Concrete Object Information\n" << info << endl;
        }
    };


int main()
{   
    /*
    * Abstract a;
    * Error : Abstract Instance Creation Failed
    */

    string s;
    s = "Object Creation Date : 23:26 PM 15 Dec 2013";
    Concrete c(s);
    c. printContent();

}
