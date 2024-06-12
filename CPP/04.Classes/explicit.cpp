/*
explicit :
    used to mark constructors to not implicitly convert types.c
*/

#include <iostream>
using namespace std; 

// not explicit
class Complex
{
private:
    double real;
    double imag;
public:
    Complex(double r = 0.0 , double i = 0.0) :real(r) , imag(i)
    {}
    bool operator==(Complex rhs)
    {
        return (real == rhs.real && imag == rhs.imag) ;
    }
};

class ComplexExplicit
{
private:
    double real;
    double imag;
public:
    explicit ComplexExplicit(double r = 0.0 , double i = 0.0) :real(r) , imag(i)
    {}
    bool operator==(ComplexExplicit rhs)
    {
        return (real == rhs.real && imag == rhs.imag) ;
    }


};



int main ()
{
    Complex com1(3.0, 0.0);

    if(com1 == 3.0) cout << "Same\n" ;
    else cout << "Noy Same\n";


    //compiler Error : no match for operator== in com2== 3.0e +0
    // if(com2 == 3.0) cout << "Same\n" ;



    ComplexExplicit com2(3.0, 0.0);
    if (com2 == (ComplexExplicit)3.0) cout << "Same";
    else cout << "Noy Same\n";


    return 0 ;
}