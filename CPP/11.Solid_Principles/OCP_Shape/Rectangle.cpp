#include "Rectangle.h"

Rectangle::Rectangle(double height, double width) :m_height(height), m_width(width)
{
}

double Rectangle::Area() const
{
    return m_height * m_width ;
}