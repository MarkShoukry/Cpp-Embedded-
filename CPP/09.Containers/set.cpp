#include <iostream>
#include <set>

using namespace std ;


int main ()
{
    set<int> myset ;
    int ne ;
    
    multiset<int> freq ;
    size_t nrElements = myset.count (12);
    
   while (cin >> ne)
   {
    myset.insert(ne) ;
   }
   set<int>::iterator itr ;
   for (itr = myset.begin() ; itr != myset.end() ; ++itr)
   {
    cout << *itr << ' ';
   }
   cout << endl ; 
   

    return 0 ;
}