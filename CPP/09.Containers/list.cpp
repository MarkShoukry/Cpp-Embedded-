#include <iostream>
#include <forward_list>




int main ()
{
    std::forward_list<int>_list(10), second_list ;


//dunctions overloading:
//same fn. 3 methods
    _list.assign({1,2,3}) ;
    second_list.assign(4, 10);
    second_list.assign(_list.begin() , _list.end());

   

    for (auto elements : second_list)
    {
        std::cout << elements << " " ;
    }

    return 0;
}