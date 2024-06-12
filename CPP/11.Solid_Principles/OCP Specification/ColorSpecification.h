#pragma once
#include "ISpecification.h"


struct  ColorSpecification : ISpecification<Product>
{
    Color C_color;
    explicit ColorSpecification(Color color) ;
    bool is_specification(Product* s) override ;
};