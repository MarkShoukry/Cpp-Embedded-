#pragma once
#include "ISpecification.h"
#include "SizeSpecification.h"
#include "ColorSpecification.h"

struct SizeAndColorSpacification :  ISpecification<Product>
{
    ColorSpecification C_color;
    SizeSpecification S_size ;

    explicit SizeAndColorSpacification
        (SizeSpecification& size ,ColorSpecification& color );

    bool is_specification (Product* s) override ;

};
