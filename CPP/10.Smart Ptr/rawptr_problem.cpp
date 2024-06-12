// a problem of pointers so use smart_ptr
//damgling ptr
//memory leak problem 
//double delete ptr

#include <iostream>
using namespace std;

char* fun()
{
    char *ptr = new char[10] ; //heap 
    delete ptr ;

    return ptr ; // dangling poiner
}




int main ()
{
    while (1)
    {
        
    
    auto *p = fun() ; // memory leak problem
    }
    return 0;
}