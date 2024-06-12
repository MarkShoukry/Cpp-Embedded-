#include <iostream>
using namespace std;
#include <array>
int main ()
{
    array<int, 5> arr = {1, 2, 3, 4, 5};
    
    
    //To print address of array
    printf("address: %x \n" ,arr );
    
    cout <<"Array 1 element: " ;
    //To found number in array
    for (int element : arr)
    {
        if (element == 0)
        {
            cout << "key is found" << element << endl;
        }
        //To print array
        cout << element << " " ;
    }
    
    cout << endl;
   


    // Auto element , element ===> data type of any index in array
    array<float,3> arr2 = {2.4 , 4.9 , 1.2};

    printf("address: %x \n" ,arr2 );
    cout <<"Array 2 element: " ;
    for (auto element: arr2)
    {
        cout  << element << " " ;
        // sizeof(element)
        cout << "size is("<< sizeof(element ) << "), ";
    }
    
    return 0;
}