#pragma once
#include "Shape.h"

class Square : public Shape
{
public:
    Square(double side);
    double Area() const override ;

private:
    double m_side;

};