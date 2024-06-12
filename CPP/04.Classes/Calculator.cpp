#include <iostream>


class Calculator
{
public:
    Calculator(double num1 , double num2) : Num1(num1) , Num2(num2)
    {

    }
    double getAdd()
    {
        Result = Num1 + Num2;
        return Result;
    }
    double getSub()
    {
        Result = Num1 - Num2;
        return Result;
    }
    double getMul()
    {
        Result = Num1 * Num2;
        return Result;
    }
    double getDiv()
    {   
        Result = Num1 / Num2;
        return Result;  
    }

    void display()
    {
        std::cout << "Add = " << getAdd() << ", "
                  << "Sub = " << getSub() << ", " 
                  << "Mul = " << getMul() << ", " 
                  << "Div = " << getDiv() << std::endl;
    }


private:
    double Num1 ;
    double Num2 ;
    double Result ;


};


int main ()
{
    Calculator calc1(10 , 20);
    Calculator calc2 (2, 0);

    calc1.display();
    calc2.display();

    
    return 0 ;
}