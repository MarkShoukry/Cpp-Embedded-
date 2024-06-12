#include <iostream>


//template for class
template<class T1 , class T2>
struct pair
{   
    pair (T1 first , T2 second) : m_first(first) , m_second(second)
    {
    }


    T1 m_first ;
    T2 m_second;

};
 
//template for function
template<class T1, class T2>
pair<T1, T2> make_pair(T1 first, T2 second)
{
    pair<T1, T2>temp(first, second) ;
    return temp ;
}



int main ()
{
    pair <int,std::string> table =  make_pair<int,std::string>(1,"Mark") ;


    std::cout <<"First: " << table.m_first << " , Second: " << table.m_second << std::endl ; 

    return 0 ;
}