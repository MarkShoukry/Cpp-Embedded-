#include <iostream>
#include <algorithm>
#include "temp_stack_only.h"
using namespace std ;


int main ()
{ 

    std::vector<int>v = {12 , 4 , 9 , 18 , 20} ;
    std::sort(v.begin() , v.end() , [](int a , int b) ->bool
    {
        return a > b ;
    });
    for (auto element : v)
    {
        cout << element << " " ;
    }
    cout << endl ;




    Stack<int> ds(8) ;
    Stack<float> fs(5) ;
    Stack<double> n(4);

   
//stack<float>
    float f = 1.1 ;
    cout << "Pushing elements onto fs" << endl ;

    fs.push(5.5);
    fs.pop(f);
    cout << f << endl ;

    while (fs.push(f))
    {
        cout << f << ' ' ;
        f += 1.1 ;
    }
    cout << endl << "Stack full." << endl << endl 
         << "Popping elements from fs" << endl ;


    while (fs.pop(f))
    {    cout << f << ' ' ; }
    cout << "\nstack Empty" << endl << endl ;
    


//stack<int> Stack<int> ds(8)
    
    int l = 1 ;
    cout <<"Pushing elements onto is" << endl ;

    while(ds.push(l))
    {
        cout << l << ' ' ;
        l += 1 ;
    }
    cout << endl << "Stack Full" << endl << endl 
         << "Popping elements from is" << endl ;

    while (ds.pop(l))
    {cout << l << ' ' ;}    
    cout << "\nstack Empty" << endl << endl ;







//stack<double>
    //Stack<double> n(4);
    double i =1.001 ;
    cout <<"Pushing elements onto is" << endl ;

    while(n.push(i))
    {
        cout << i << ' ' ;
        i += 1 ;
    }
    cout << endl << "Stack Full" << endl << endl 
         << "Popping elements from is" << endl ;

    while (n.pop(i))
    {cout << i << ' ' ;}    
    cout << "\nstack Empty" << endl << endl ;



    return 0;
}