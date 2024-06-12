#include <iostream>
#include <array>
using namespace std;


int main ()
{
    std::array<int,5> data = {10, 5, 8, 9, 17};
    std::uint16_t key = 0 ;
    cin >> key ;

    // worst case = O(n)  best case = O(1)
    for (int i = 0 ; i < data.size() ; i++)
    {
        if (data[i] == key)
        {
            cout << "Found the key at " << i << endl ;
          
        }
    } 
    


    return 0 ; 
}