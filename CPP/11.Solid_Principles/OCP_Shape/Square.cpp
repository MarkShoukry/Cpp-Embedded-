#include "Square.h"

Square::Square(double side) :m_side(side)
{
}

double Square::Area() const
{
    return m_side * m_side ;
}