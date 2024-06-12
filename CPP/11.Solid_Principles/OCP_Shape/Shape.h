#pragma once

#include <iostream>
#include <vector>
#include <memory>

class Shape
{
public:
    virtual ~Shape() = default ;
    virtual double Area() const = 0 ;
};


void PrintShape(const std::vector<std::shared_ptr<Shape>> &v) ;

