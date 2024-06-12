/*
this is pair (1,20) - (2,30) - (3,10) - (4,40) - (5,90)
--------------
1   |   20
2   |   30
3   |   10
4   |   40
5   |   90
--------------
*/




template <class T1 , class T2>
struct pair
{
    typedef T1 first_type ;
    typedef T2 second_type ;
    T1 first ;
    T2 second ;
    pair() ;
    pair(const T1& x , const T2& y );
};

//_______________________________________________________________________________________________
//_______________________________________________________________________________________________

#include <utility>

template <class T1, class T2>
pair<T1, T2> make_pair(const T1& x , const T2& y)
{
    return pair<T1, T2>(x, y);
}


