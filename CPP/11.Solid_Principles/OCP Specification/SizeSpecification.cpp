#include "SizeSpecification.h"

SizeSpecification::SizeSpecification(Size size)
                    : S_size(size)
{
}

bool SizeSpecification::is_specification(Product* s)
{
    return (s->m_Size == S_size);
}