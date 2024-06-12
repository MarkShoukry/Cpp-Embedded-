#include <iostream>

class Fruit 
{
public:
    Fruit ()
    {

    }
    void setPrice(std::uint16_t price)
    {
        this->m_price = price;
    }
    void setWeight(std::uint16_t weight)
    {
        this->m_weight = weight;
    }
    std::uint16_t getTotal_price()
    {
        Total_price = m_price * m_weight; 
        return this->Total_price;
    }
    

private:
    std::uint16_t m_price;
    std::uint16_t m_weight;
    std::uint16_t Total_price;
};








int main ()
{
    Fruit Orange ;
    Orange.setPrice(10);
    Orange.setWeight(5);

    

    std::cout << "Total Price of orange = " << Orange.getTotal_price() << std::endl; 

    return 0;
}


