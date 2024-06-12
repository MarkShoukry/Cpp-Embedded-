#pragma once
#include "IFind.h"

struct Findproduct : IFind<Product>
{
   virtual std::vector<Product*>Find(std::vector<Product*> items , ISpecification<Product>& spac)
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
};



