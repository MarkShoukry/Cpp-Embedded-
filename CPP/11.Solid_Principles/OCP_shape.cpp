#include <iostream>
#include <vector>
#include <memory>
using namespace std;

//Base Class
class Shape
{
public:
    virtual ~Shape() = default;
    virtual double Area() const = 0 ; //pure virtual function
};

// Concrete derived classes
class Circle : public Shape
{
public:
    Circle(double radius) :m_radius(radius)
    {
    }
    double Area() const override
    {
        constexpr double PI = 3.14 ;
        return PI * m_radius * m_radius ;
    }
private:
    double m_radius;
};

class Rectangle : public Shape
{
public:
    Rectangle(double height , double width) :m_height(height) , m_width(width)
    {
    }
    double Area () const override
    {
        return m_height * m_width ;
    }
private:
    double m_height ;
    double m_width;
};

class Triangle : public Shape
{
public:
    Triangle(double base, double height) : m_base(base) , m_height(height)
    {
    }
    double Area() const override
    {
        constexpr float _const = 0.5 ;
        return _const * m_base * m_height ;
    }
private:
    double m_base;
    double m_height;
};


// adding a new shape without modifying existing code
class Square : public Shape 
{
public:
    Square(double side) :m_side(side)
    {
    }
    double Area() const override
    {
        return m_side * m_side ;
    }
private:
    double m_side;
};


typedef std::vector<std::shared_ptr<Shape>> &AllShape ;


void PrintShape(const AllShape &v)
{
    for (const auto& element : v  )
    {
        cout << "Area is " << element->Area() << '\n';
        
    }
}


int main()
{
    Circle cir(5);
    Rectangle rec(5, 5);
    Triangle tri(5, 5);
    Square sq(5);

    std::vector<std::shared_ptr<Shape>> all_shape ;
    all_shape.push_back(std::make_shared<Circle>(cir));
    all_shape.push_back(std::make_shared<Rectangle>(rec));
    all_shape.push_back(std::make_shared<Triangle>(tri));
    all_shape.push_back(std::make_shared<Square>(sq));

    PrintShape(all_shape);
    return 0;
}
