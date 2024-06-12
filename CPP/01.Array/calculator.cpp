#include <iostream>

namespace calculator
{
    std::int16_t add (float num1, float num2)
    {   return num1 + num2 ;    }

    std::int16_t sub (float num1, float num2)
    {   return num1 - num2 ;    }

    std::int16_t mul (float num1, float num2)
    {   return num1 * num2 ;    }

    std::int16_t div (float num1, float num2)
    {   float result = num1 / num2 ;
        if (num2 == 0)
        {std::cout << "ERROR,Infinity "<< std::endl ;}
        return result;
    }
    std::int16_t models (std::int16_t num1, std::int16_t num2)
    {  
        std::int16_t result = num1 % num2 ;
        return result ;
    }
}


int main ()
{
    double num1=0.0 ,num2=0.0 ,result =0.0;
    char op;
    std::uint16_t index = 0; 
    while (index < 5)
    {
    std::cout << "Please Enter number 1 , operation , number 2" <<std::endl ; 
    std::cin >> num1 >> op >> num2 ;


        switch (op)
    {
    case '+':
       result = calculator::add(num1 , num2);
        break;

    case '-':
        result = calculator::sub(num1 , num2) ;    
        break;

    case '*':
        result = calculator::mul(num1 , num2) ;
        break;

    case '/':
        result = calculator::div(num1 , num2) ;
        break;

    case '%':
        result = calculator::models(num1 , num2) ;
        break;

    default:
    std::cout << "Error, Tr Again" <<std::endl;
        break;
    }

    std::cout << num1 <<" "<< op <<" " << num2 <<" = " << result << std::endl ;
    index ++;

    }

    return 0;
}