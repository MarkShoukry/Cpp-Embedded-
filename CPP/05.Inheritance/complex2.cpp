#include <iostream>

/*
Access          same class      child        outside

-public           True          True           True

-protected        True          True           fasle

-private          True          false          false

*/


class Complex 
{
public:
    Complex (float real , float imag) :m_Real(real) , m_Imag(imag)
    {
    }


friend std::ostream& operator<<(std::ostream& output,Complex const& complex) ;


    void SetReal(float rl)
    {
        this->m_Real = rl ;
    }
    float GetReal()
    {
        return this->m_Real;
    }

    void SetImag(float ig)
    {
        this->m_Imag = ig ;
    }
    float GetImag()
    {
        return this->m_Imag;
    }


    Complex& operator+(Complex  &obj)
    {   
        // this->m_Imag = m_Imag + obj.m_Imag ;
        // this->m_Real = m_Real + obj.m_Real ;
        
        this->m_Imag+= obj.m_Imag;
        this->m_Real+= obj.m_Real;
        return *this ;
    }

    //copy assignment operator
    Complex& operator=(Complex const &rhs)
    {
        this->m_Imag = rhs.m_Imag ;
        this->m_Real = rhs.m_Real;
        return *this;
    }
    

private:
    float m_Real;
    float m_Imag;
};




std::ostream& operator<<(std::ostream& output,Complex const& complex)
{
    output << complex.m_Real << "+i" << complex.m_Imag << std::endl;
    return output ;
}





int main ()
{
    Complex c1(2.3 , 5);
    Complex c2(3.9 , 9.7);
    Complex c3(0.0 , 0.0);
    Complex cd(0,0);

    std::cout << c1 ; 

    c3 = c1 + c2 ;
    std::cout << c3.GetReal() << " +i " << c3.GetImag()  << std::endl;

    
    cd = c2 ;
    std::cout << cd.GetReal() << " +i " << cd.GetImag()  << std::endl;
    cd.SetImag(5) ;
    std::cout << cd.GetReal() << " +i " << cd.GetImag()  << std::endl << std::endl ;

    std::cout << c1 ;
    std::cout << c2 ;
    std::cout << c3 ;
    std::cout << cd ;


    
    return 0;
}