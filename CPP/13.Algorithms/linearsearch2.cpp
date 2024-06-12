/*
* list = [ 1 , 8 ,20 , 6 , 18]
* search for a given key from console.
________________________________________
case : best found at the first
    O(1)

case : average
    O(n)

case : worst

    O(n)

    ____________
    O(n*n) = O(n^2)

*/
#include <iostream>
#include <array>
#include <queue>
#include <stack>
using namespace std;


template <class T>
T LinearSearch (std::array<T,5> list , T key)
{
     for(T i = 0 ; i < list.size() ; i++)
    {
        if(list[i] == key)
        {
            cout << "Key value is found at index " << i << endl ;
            return i ; 
            //break;
        }
    }
    return -1;
}



int main()
{
    std::array<int , 5> list = {1, 8 , 20, 6, 18} ;
    int key = 0 ;

    std::cout << "please enter the key search element\n";
    cin >> key ;

    auto result = LinearSearch(list , key) ;
    if (result == -1)
    {
        cout << "Element isn't found\n" ;
    }

    queue<char> xqueue ;
    xqueue.push('h') ;

    stack<int> xstack ;
    xstack.push(8);
    xstack.size();

    cout << '\n' ;
   // cout << xqueue.size() ;
    cout << xstack.size() ;
   
    return 0 ;
}