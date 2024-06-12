#include <iostream>
using namespace std;


template <class T>
class Counted_ptr
{
public :
    long *count;
    T* ptr ;

    Counted_ptr(T* p) : ptr(p)
    {
        count = new long(1) ;
    }
    //copy constructor
    Counted_ptr(const Counted_ptr& other)
    {
        this->ptr = other.ptr ;
        this->count = other.count;
        (*count)++;
    }
    //deferance operator
    T& operator*()    {   return *ptr ;   }
    T& operator->()   {  return *ptr ;    }

    //desreuctor
    ~Counted_ptr()
    {
        delete ptr;
        (*count)--;
        if(*count == 0)
        {
            delete ptr ;
            delete count ;
        }
    }

};


int main ()
{
    Counted_ptr<int> s1(new int {5});
    Counted_ptr<int> s2(s1);

    std::cout << *s2 << std::endl;

    return 0;
}