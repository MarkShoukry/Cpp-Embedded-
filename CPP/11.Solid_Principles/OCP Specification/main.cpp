#include "SizeAndColorSpacification.h"
#include "Findproduct.h"


int main ()
{
    Product apple { "Apple" , Color::Green , Size::Small} ;
    Product Car   { "Car"   , Color::Blue  , Size::Large} ;
    Product tree  { "Tree"  , Color::Green , Size::Large} ;
    Product tree2 { "Tree"  , Color::Green , Size::Large} ;

    ColorSpecification green{Color::Green};
    SizeSpecification large{Size::Large};

    SizeAndColorSpacification SizeColor{large, green};

    Findproduct fp ;
    
    std::vector<Product*> allproducts {&apple, &tree , &Car , &tree2};

    auto results = fp.Find(allproducts, SizeColor);
    
    for(auto& i : results)
    {
        std::cout << i->m_Name << " : is " 
                  << vColor[(int)i->m_Color].c_str()
                  << std::endl ;
    }

    return 0 ;
}