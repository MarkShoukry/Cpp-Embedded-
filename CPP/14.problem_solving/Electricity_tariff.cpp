/*
Unit tarrif  :
100  1.25 per unit
200  2 per unit
300  3 per unit
*/
#include <iostream>

class Electricitity
{
private:
    int m_comsumption ;

public:
    Electricitity(int comsumption) : m_comsumption(comsumption)
    {}
    float calculateBill()
    {
        if (m_comsumption <= 100)
            {   return m_comsumption * 1.25 ;   }
        else if (m_comsumption <=200 && m_comsumption >100)
            {   return m_comsumption * 2 ;      }
        else if (m_comsumption <=300 && m_comsumption > 200)
            {   return m_comsumption * 3 ;      }
            else {}
    }

};

int main()
{
    Electricitity bill(25);
    std::cout << "100 Tarrif: The Bill is " << bill.calculateBill()   << " LE" << std::endl ;
    bill = 150 ;
    std::cout << "200 Tarrif: The Bill is "  << bill.calculateBill()  << " LE" << std::endl ;
    bill = 250;
    std::cout << "300 Tarrif: The Bill is "  << bill.calculateBill()  << " LE" << std::endl ;
    return 0 ;
}