#pragma once
#include "ISpecification.h"



template <class T>
struct IFind 
{
    virtual std::vector<T*>Find(std::vector<T*> items , ISpecification<T>& spac) = 0 ;
};