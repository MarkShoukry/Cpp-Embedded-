#include <iostream>

namespace calculator
{
    //functions integer
    std::int16_t add (int16_t num1, int16_t num2)
    {   return num1 + num2 ;    }

    std::int16_t sub (int16_t num1, int16_t num2)
    {   return num1 - num2 ;    }

    std::int16_t mul (int16_t num1, int16_t num2)
    {   return num1 * num2 ;    }

    std::int16_t div (int16_t num1, int16_t num2)
    {   int16_t result = num1 / num2 ;
        if (num2 == 0)
        {std::cout << "ERROR,Infinity "<< std::endl ;}
        return result;
    }
    std::int16_t models (std::int16_t num1, std::int16_t num2)
    {  
        std::int16_t result = num1 % num2 ;
        return result ;
    }


    //functions double
     double add (double num1, double num2)
    {   return num1 + num2 ;    }

    double sub (double num1, double num2)
    {   return num1 - num2 ;    }

    double mul (double num1, double num2)
    {   return num1 * num2 ;    }

    double div (double num1, double num2)
    {   double result = num1 / num2 ;
        if (num2 == 0)
        {std::cout << "ERROR,Infinity "<< std::endl ;}
        return result;
    }
    
    



}




int main ()
{
    double num1=0.0 ,num2=0.0 ,result =0.0;
    char op;
    std::uint16_t index = 0; 
    while (index < 3)
    {
    std::cout << "Please Enter number 1 " << std::endl ;
    std::cin >> num1 ;
    std::cout << "Please Enter number 2 " << std::endl ;
    std::cin >> num2 ;
    std::cout << "Please Enter operator " << std::endl ;
    std::cin >> op ;


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