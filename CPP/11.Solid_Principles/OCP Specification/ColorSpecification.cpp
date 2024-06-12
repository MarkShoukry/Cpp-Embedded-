#include "ColorSpecification.h"

ColorSpecification::ColorSpecification(Color color) 
                        :C_color(color)
{
}


bool ColorSpecification::is_specification(Product *s)
{
    return (s->m_Color == C_color) ;
}