/*
using + operator to add complex numbers  
Complex is real + "i" imag
*/

#include <iostream>
using namespace std ;

class Complex 
{
public:
    Complex (float real = 0  , float imag = 0)  : m_real(real) , m_imag(imag)
    {

    }

    Complex operator +(Complex const &obj)
    {
        Complex result ;
        result.m_real = m_real + obj.m_real ;
        result.m_imag = m_imag + obj.m_imag ;
        return result ;
    }

    void display ()
    {
        cout <<"Result = " << m_real << " + i " << m_imag << endl;
    }

private:
    float m_real;
    float m_imag;

};

int main ()
{
    Complex c1(2.8 , 8 ) , c2(3 , 9.1 ) , c3 ;
    c3 = c1 + c2 ;
    c3.display() ;
    c1.display();


    return 0 ;
}