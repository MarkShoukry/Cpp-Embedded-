#pragma once
#include "ISpecification.h"

struct SizeSpecification :  ISpecification<Product>
{
    Size S_size ;
    explicit SizeSpecification(Size size) ;
    bool is_specification(Product* s) override;
};
