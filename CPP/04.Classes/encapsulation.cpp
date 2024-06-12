#include <iostream>


struct Fruit
{
    void setPrice(std::uint16_t price)
    {
        this->price_Kg = price ;
    }
    void setWeight(std::uint16_t Weight)
    {
        this->Weight = Weight ;
    }

    std::uint16_t getPrice ()
    {
        Total_price = price_Kg * Weight;
        return this->Total_price ;
    }

    std::uint16_t price_Kg;
    std::uint16_t Weight;
    std::uint16_t Total_price ;


};


int main ()
{
    Fruit orange; 
    orange.setPrice(10);
    orange.setWeight(5);

    std::cout << "Total Price: " << orange.getPrice() << std::endl;


    return 0 ;
}