#pragma once
#include "ISpecification.h"
#include "SizeSpecification.h"
#include "ColorSpecification.h"

struct SizeAndColorSpacification :  ISpecification<Product>
{
    ColorSpecification C_color;
    SizeSpecification S_size ;

    explicit SizeAndColorSpacification
        (SizeSpecification& size ,ColorSpecification& color )
        : S_size(size) ,C_color(color)
{
}


    bool is_specification (Product* s) override
    {
        return (S_size.is_specification(s) && C_color.is_specification(s)) ;

    }

};

