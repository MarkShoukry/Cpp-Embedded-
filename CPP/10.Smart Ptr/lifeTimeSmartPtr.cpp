#include <iostream>
#include <memory>


//a good function  
void asSmartPointerGood(std::shared_ptr<int> shr)
{
    //Returns the number of different shared_ptr (use_count())
    std::cout << "shr.use_count(): " << shr.use_count() << std::endl;
    //reset is function in 
    shr.reset(new int(2011));
    std::cout << "shr.use_count(): " << shr.use_count() << std::endl;
}

void asSmartPointerBad(std::shared_ptr<int>& shr)
{
    *shr += 19;
}



int main()
{
    std::cout << std::endl ;
    int value = 1998;
    std::shared_ptr<int> firsha(new int(value));

 //   auto firsha = std::make_shared<int>(1998);
    auto secsha = firsha ; //copy constructor

    std::cout << "firsha.use_count(): " << firsha.use_count() << std::endl ; // (1)
    std::cout << "firsha.use_count(): " << secsha.use_count() << std::endl ; 
    std::cout << std::endl ;

    asSmartPointerGood(firsha);
    std::cout << std::endl ;

    std::cout << "*firsha: " << *firsha << std::endl ;
    std::cout << "*firsha.use_count(): " << firsha.use_count() << std::endl;
    std::cout << std::endl;

    std::cout << "*secsha: " << *secsha << std::endl ;
    std::cout << "*secsha.use_count(): " << secsha.use_count() << std::endl;
    std::cout << std::endl;

    asSmartPointerBad(secsha) ;
    std::cout << "*secsha: " << *secsha << std::endl ;

    
    return 0 ;
}