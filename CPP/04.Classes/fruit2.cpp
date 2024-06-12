#include <iostream>


class fruit_2 
{
public:
    //parameterized constructor
    fruit_2(std::uint16_t price , std::uint16_t weight) : m_price_kg(price) , m_weight2(weight)
    {
    }
     void setPrice(std::uint16_t price)
    {
        this->m_price_kg = price;
    }
    void setWeight(std::uint16_t weight)
    {
        this->m_weight2 = weight;
    }
    std::uint16_t getTotal_price()
    {
        Total2_price = m_price_kg * m_weight2; 
        return this->Total2_price;
    }
   

private:
    std::uint16_t m_price_kg;
    std::uint16_t m_weight2;
    std::uint16_t Total2_price;

};


int main ()
{
    fruit_2 Banana(10 , 2);
    std::cout << "Total Price of Banana = " << Banana.getTotal_price() << std::endl;

    return 0;
}