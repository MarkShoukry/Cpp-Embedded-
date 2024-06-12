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

// selection sort function
template <typename T>
void SelectionSort (array<T,5> &arr )
{
    T outer_idx, inner_idx , min_idx ;
    // one by one move boundary of unsorting subarray
    for (outer_idx = 0 ; outer_idx < arr.size() -1 ; outer_idx++ )
    {
        //find the minimum element in unsorted array
        min_idx = outer_idx;
        for(inner_idx = outer_idx +1; inner_idx < arr.size() ; inner_idx++)
        {
            if (arr[inner_idx] < arr[min_idx])
            { min_idx = inner_idx ; }

            //swap the found minimum element with the first element
            Swap(&arr[min_idx] , &arr[outer_idx]);
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
    cout << "Sorted array \n" ;
    SelectionSort(array_);
    PrintArray(array_);

    array<double , 5> arr2 = {52.5 ,63.3, 23.5 , 22.1, 11.4 };
    cout << "\nArray of double\n" ; 
    SelectionSort(arr2);
    PrintArray(arr2);
   
    
    return 0;
}