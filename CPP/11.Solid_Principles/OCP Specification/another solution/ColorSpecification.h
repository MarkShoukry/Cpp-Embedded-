#pragma once
#include "ISpecification.h"


struct  ColorSpecification : ISpecification<Product>
{
    Color C_color;
    explicit ColorSpecification(Color color)
     :C_color(color)
{
}

    bool is_specification(Product* s) override 
    {
    return (s->m_Color == C_color) ;
    }
};
