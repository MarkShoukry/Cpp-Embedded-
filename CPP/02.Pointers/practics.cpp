#include <iostream>
#include <array>
using namespace std;


int main ()
{
    constexpr int size = 13;
    array<int, size> arr = { 3, 3, 3, 4,5 , 2, 10, 4 ,9, 2 , 10 , 9 , 5  };
    int freq{0} ; 
    array<int, size>::iterator ptr;          // ....?
    array<int,12> check;
    check.fill(0);

    for(int index =0 ; index < size ; index++ )
    {
        //To make the arra of unique elements
        if (check[index] == 1 ) {continue;}
        else 
        {
            check[index] = 1;
            freq - 1;
        }


        for (int index2 = index+1 ; index2 < size ; index2++)
        {
            if (arr[index2] == arr[index])
            {
                check[index2] = 1;
                freq++;
            }

        }
        

        cout << "The number " << arr[index] << " \t repeated: " << freq << endl;
        freq = 0;

    }


    return 0;
}