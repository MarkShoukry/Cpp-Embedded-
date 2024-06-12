#include "Findproduct.h"

std::vector<Product*>Findproduct::Find(std::vector<Product*> items , ISpecification<Product>& spac)
{
    Items results;

    for(auto& p : items)
    {
        if (spac.is_specification(p))
            {
                results.push_back(p) ;
            }
    }
    return results ;
}
