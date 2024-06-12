#include <iostream>

using namespace std;


namespace mystd
{
template <class T>
class Smart_ptr
{
    T* ptr ;  // Actual pointer
public:
    Smart_ptr() {}  //default
    // Constructor
    // for use of explicit keyword to prevent implicit conversions
    explicit Smart_ptr (T* p) :ptr(p)
    {}
    
    ~Smart_ptr ()
    {  delete ptr ;}

    T& operator*()
    {
        return *ptr ;
    }
};

}

int main ()
{
    mystd::Smart_ptr<int> smart(new int()) ;
    *smart = 20 ;
    printf("%d", *smart) ;


    return 0;
}