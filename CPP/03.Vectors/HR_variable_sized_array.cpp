//Q Link:-
//https://www.hackerrank.com/challenges/variable-sized-arrays/problem


#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main()
{
    int n , q ;
    int *arr[n];
    
    cin >> n >> q ;

    for (int m = 0 ; m < n ; m++ )
    {
        int size ;
        cin >> size;

        arr[m] = new int[size]; ;
        
        for (int i = 0 ; i < size ; i++)
        {
            cin >> arr[m][i] ;
        }
    }

    for (int y = 0 ; y < q ; y++)
    {
        int i , j ;
        cin >> i >> j ;

        cout << arr[i][j] << endl ;
    }


return 0 ;
}

