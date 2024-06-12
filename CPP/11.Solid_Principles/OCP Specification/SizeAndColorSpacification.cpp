#include "SizeAndColorSpacification.h"
#include "ISpecification.h"




SizeAndColorSpacification::SizeAndColorSpacification
        (SizeSpecification& size ,ColorSpecification& color )
        : S_size(size) ,C_color(color)
{
}


bool SizeAndColorSpacification::is_specification (Product* s) 
{
    return (S_size.is_specification(s) && C_color.is_specification(s)) ;
}