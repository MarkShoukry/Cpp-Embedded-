#pragma once
#include "Shape.h"

class Rectangle : public Shape
{
public:
    Rectangle(double height, double width);
    double Area() const override ;

private:
    double m_height;
    double m_width ;
};