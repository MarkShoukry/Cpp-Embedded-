#pragma once 
#include <string>
#include <iostream>
#include <vector>
#include "memory"

std::string vColor[] = { "Red" , "Green" , "Blue" } ;
enum class Color
{
    Red,
    Green,
    Blue
};

std::string vSize[] = { "Large" , "Medium" , "Small"};
enum class Size
{   
    Large,
    Medium,
    Small
};

struct Product
{
   std::string m_Name;
    Color  m_Color;
    Size m_Size;
};


template <class T>
struct ISpecification
{
    virtual ~ISpecification() = default;
    virtual bool is_specification(T* item) = 0 ;
};

using Items = std::vector<Product*> ;

// typedef std::vector<std::shared_ptr<Product*>>(Items) ;

// typedef std::vector<Product*> I_Items ;