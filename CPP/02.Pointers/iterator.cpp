#include <iostream>
#include <array>



int main ()
{
    std::array<int , 5> intNum = {1 , 2 , 3 , 4 , 5};

    std::array<int, 5>::iterator it;

    for (it =intNum.begin() ; it != intNum.end() ; ++it)
    {
        std::cout << *it << " " ;
    }
    std::cout << std::endl;


    //swap
    std::array<int , 5> zeros;
    auto element = intNum.at(1) ;
    zeros.fill(0);
    intNum.swap(zeros);
    std::cout << element << std::endl ;
    for (auto element : intNum)
    {
        std::cout << element << " " ;
    }
    std::cout << std::endl;
    for (auto element : zeros)
    {
        std::cout << element << " " ;
    }

    std::cout << std::endl << std::endl ;

    bool elem = zeros.empty() ;
    for (auto elem : zeros)
    {
        std::cout << elem << ", " ;
    }


    return 0;
}