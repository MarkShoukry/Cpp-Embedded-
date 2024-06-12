#include "Circle.h"

Circle::Circle(double r) : radius(r)
    {
    }

double Circle::Area() const  
    {
        return Pi * radius * radius ;
    }
