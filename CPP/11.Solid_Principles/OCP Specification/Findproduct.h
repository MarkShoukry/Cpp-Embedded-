#pragma once
#include "IFind.h"

struct Findproduct : IFind<Product>
{
   virtual std::vector<Product*>Find(std::vector<Product*> items , ISpecification<Product>& spac);
};
