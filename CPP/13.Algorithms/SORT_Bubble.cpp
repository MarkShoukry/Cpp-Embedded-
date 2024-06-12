#include <iostream>
#include <array>
using namespace std; 

//swap function
template <typename T>
void Swap(T *first, T *second)
{
    T temp = *first  ;
    *first = *second ;
    *second = temp   ;
}

// Bubble sort function
template <typename T>
void BubbleSort (array<T,5> &arr )
{
    T outer_idx, inner_idx  ;
    // one by one move boundary of unsorting subarray
    for (outer_idx = 0 ; outer_idx < arr.size() -1 ; outer_idx++ )
    {
        
        for(inner_idx = 0 ; inner_idx < arr.size() - outer_idx - 1 ; inner_idx++)
        {
            if (arr[inner_idx] > arr[inner_idx + 1])
            { 
            //swap the found minimum element with the first element
            Swap(&arr[inner_idx] , &arr[inner_idx + 1 ]);
            }
        }
    }

}

//function to print an array
template <typename T >
void PrintArray (array<T,5> arr)
{
    for (std::uint16_t i = 0 ; i < arr.size() ; i++)
    {   cout << arr[i] << " " ;    }
    cout << '\n' ;
}


//driver program 
int main ()
{
    array<int,5> array_ = {64, 25, 12, 22, 11};
    cout << "Sorted array using Bubble Sort\n";
    BubbleSort(array_);
    PrintArray(array_);

    array<double , 5> arr2 = {52.5 ,63.3, 23.5 , 22.1, 11.4 };
    cout << "\nArray of double\n" ; 
    BubbleSort(arr2);
    PrintArray(arr2);
   
    
    return 0;
}