#include <iostream>
#include <memory>

class Rectangle
{
public:
    Rectangle(int height , int width) :m_height(height), m_width(width)
    {
    }
    int area()
    {
        return m_height * m_width ;
    }

private:
    int m_height ;
    int m_width ;
};


int main ()
{
    // std::unique_ptr<Rectangle> P1(new Rectangle(10, 5));
    // std::unique_ptr<int> intPTR(new int[10]);
    auto p1 = std::make_unique<Rectangle>(10,5);
    std::cout << "p1: " << p1->area() << std::endl;

    //std::unique_ptr<Rectangle> p2(p1); //error
    std::unique_ptr<Rectangle> p2(std::move(p1));
    std::cout <<"p2: " << p2->area() << std::endl;

    return 0 ;
}