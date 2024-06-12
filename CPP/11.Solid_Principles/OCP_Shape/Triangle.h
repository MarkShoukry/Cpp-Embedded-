#pragma once
#include "Shape.h"


class Triangle : public Shape
{
public:
    Triangle(double base, double height) ;
    double Area() const override ;


private:
    double m_base;
    double m_height;
};