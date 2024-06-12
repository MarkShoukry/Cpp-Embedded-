#pragma once
#include "ISpecification.h"

struct SizeSpecification :  ISpecification<Product>
{
    Size S_size ;
    explicit SizeSpecification(Size size) 
            : S_size(size)
{
}
    bool is_specification(Product* s) override
    {
    return (s->m_Size == S_size);
    }
};



