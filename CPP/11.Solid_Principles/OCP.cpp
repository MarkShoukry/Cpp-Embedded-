#include <iostream>
#include <vector>
#include <string>

std::string vColor[] = { "Red", "Green" , "Blue" } ;
enum class Color
{
    Red,
    Green,
    Blue
};

std::string vSize[] = { "large" , "Medium" , "Small" } ;
enum class Size
{
    Large,
    Medium,
    Small
};

struct Product
{
    std::string    m_Name;
    Color          m_Color ;
    Size           m_Size ;
};


typedef std::vector<Product*> Items;

template <typename T>
struct ISpecification
{
    virtual ~ISpecification() =default ;
    virtual bool is_specification(T* item) = 0 ;
};

struct ColorSpecification : public ISpecification<Product>
{
    Color color;

    explicit ColorSpecification(Color c_color) : color(c_color)
    {
    }
    bool is_specification (Product* s) override
    {
        return (s->m_Color == color);
    }
};

struct SizeSpecification : public ISpecification<Product>
{
    Size size;

    explicit SizeSpecification(Size s_size) : size(s_size)
    {
    }

    bool is_specification (Product* s) override
    {
        return(s->m_Size == size);
    }
};


struct SizeAndColorSpacification : public ISpecification<Product>
{
    SizeSpecification size ;
    ColorSpecification color ;

    explicit SizeAndColorSpacification(SizeSpecification& s_size , ColorSpecification& c_color) 
    : size(s_size) , color(c_color)
    {
    }

    bool is_specification (Product* s)override
    {
        return(size.is_specification(s) && color.is_specification(s));
    }
};


template <typename T>
struct IFind
{
    virtual std::vector<T*>Find(std::vector<T*> items ,ISpecification<T>& spac) = 0;
};


struct FindProduct : public IFind<Product>
{
    virtual std::vector<Product*>Find(std::vector<Product*> items , ISpecification<Product>& spac)
    {
        Items results;
        for (auto& p : items)
            {
                if (spac.is_specification(p))
                        { results.push_back(p) ; } 
            }

            return results ;
       

    }
};


int main ()
{   
    Product apple { "Apple" , Color::Green , Size::Small} ;
    Product Car   { "Car"   , Color::Blue  , Size::Large} ;
    Product tree  { "Tree"  , Color::Green , Size::Large} ;
    Product tree2 { "Tree"  , Color::Green , Size::Large} ;

    ColorSpecification green{Color::Green} ;
    // ColorSpecification red{Color::Red};
    // ColorSpecification blue{Color::Blue};

    SizeSpecification large{Size::Large};

    SizeAndColorSpacification size_color{large, green} ;

    FindProduct fp ;

    std::vector<Product*> allproducts {&apple, &tree , &Car , &tree2};

    auto results = fp.Find(allproducts, size_color);
    for(auto& i : results)
    {
        std::cout << i->m_Name << " : is " 
                  << vColor[(int)i->m_Color].c_str()
                  << std::endl ;
    }


    return 0 ; 
}