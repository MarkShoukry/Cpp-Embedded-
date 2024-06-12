#include <iostream>
#include <vector>

class Shape 
{
public:
    Shape(std::uint16_t height , std::uint16_t width) : m_Height(height) , m_Width(width) 
    {

    }
    void setHeight(std::uint16_t height)
    {
        this->m_Height = height;
    }
    void setWidth(std::uint16_t width)
    {
        this->m_Width = width;
    }
    std::uint16_t getArea()
    {
        return m_Height * m_Width;
    }

    void display()
    {
        std::cout << "Area is " << getArea() <<std::endl ;
    }

private:
    std::uint16_t m_Height;
    std::uint16_t m_Width;

};

    void ShapeDataBase(std::vector<Shape> &DataBase)
    {
        for (auto Shape : DataBase)
        {
            Shape.display();
        }
    }


int main ()
{
    std::vector<Shape> data_base ;
    Shape Square(10,10);
    Shape Rectangular(10,20);

    data_base.push_back(Square);
    data_base.push_back(Rectangular);

    ShapeDataBase(data_base);

    // std::cout << "Square Area = " << Square.getArea() << std::endl
    //           << "Rectangular Area = " << Rectangular.getArea() << std::endl;
    return 0 ;
}