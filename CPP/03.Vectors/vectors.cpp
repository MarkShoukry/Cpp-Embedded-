#include <iostream>
#include <vector>



int main ()
{
    std::vector<int> nums = {1, 3, 9};
    //print element of vectors
    std::cout << "nums: " ;
    for (auto element : nums)
    {   std::cout << element << " " ;    }


    std::cout << "\nnums after push_back: \n" ;
    nums.push_back(5);
    for (auto element : nums)
    {   std::cout << element << " " ;    }


    std::cout << "\nchange num 3 to 7" << std::endl ;
    for (auto it =nums.begin() ; it != nums.end() ; ++it)
    { 
        if (*it == 3)
        {
            *it = 7;
        }
    }
    for (auto element : nums)
    {   std::cout << element << " " ;    }


    std::vector<int>::iterator it;
    std::cout << "\nchange num 3 to 7" << std::endl ;
    for ( it =nums.begin() ; it != nums.end() ; ++it)
    { 
        if (*it == 7)
        {
            *it = nums.at(0);
        }
    }
    for (auto element : nums)
    {   std::cout << element << " " ;    }

    

    return 0;
}