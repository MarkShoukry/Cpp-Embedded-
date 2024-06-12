#pragma once
#include "Shape.h"

class Circle : public Shape
{
public:
    Circle(double r) ;
    double Area() const override ;
    
private:
    double radius;
    static constexpr double Pi = 3.14 ;
};