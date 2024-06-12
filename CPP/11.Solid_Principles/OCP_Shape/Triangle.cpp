#include "Triangle.h"

Triangle::Triangle(double base , double height): m_base(base) , m_height(height)
{
}


double Triangle::Area() const
{
    constexpr float x = 0.5 ;
    return x * m_base * m_height ;
}