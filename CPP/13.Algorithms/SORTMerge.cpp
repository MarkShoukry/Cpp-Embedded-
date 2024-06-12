#include <iostream>
#include <array>
using namespace std ;

/*
Merges two subarrays of array[]
first subarray is arr[begin.mid]
second subarray is arr[mid+1.end]
*/
void Merge (int array[], int const left, int const mid, int const right)
{
    auto const subArrayOne = mid - left + 1 ;
    auto const subArrayTwo = right - mid ;
    
    //creat temp arrays
    auto *leftArray = new int[subArrayOne] ,
        *rightArray = new int [subArrayTwo];
    
    // copy data to temp arrays leftArray[] and rightArray[]
    for (auto i =0 ; i < subArrayOne; i++)
    {  leftArray[i] = array[left + i] ;    }
    
    for (auto j=0 ; j < subArrayTwo; j++)
    {  rightArray[j] = array[mid + 1 + j] ;  }

    auto indexOfSubArrayOne = 0 , // initial index of first subArray
         indexOfSubArrayTwo = 0 ; // initial index of second subArray
    int indexOfMergeArray = left; // initial index of merge array

    // Merge the temp arrays back into array[left..right]
    while (indexOfSubArrayOne < subArrayOne && indexOfSubArrayTwo < subArrayTwo)
    {
        if (leftArray[indexOfSubArrayOne] <= rightArray[indexOfSubArrayTwo])
        {
            array[indexOfMergeArray] = leftArray[indexOfSubArrayOne] ;
            indexOfSubArrayOne++;
        }
        else
        {
            array[indexOfMergeArray] = rightArray[indexOfSubArrayTwo];
            indexOfSubArrayTwo++;
        }
        indexOfMergeArray++;
    }
    
    // copy the remining elements of left[] if there ara any
    while (indexOfSubArrayOne < subArrayOne)
    {
        array[indexOfMergeArray] = leftArray[indexOfSubArrayOne];
        indexOfSubArrayOne++;
        indexOfMergeArray++;
    }
    // copy the remining elements of right[] if there ara any
    while (indexOfSubArrayTwo < subArrayTwo)
    {
        array[indexOfMergeArray] = rightArray[indexOfSubArrayTwo];
        indexOfSubArrayTwo++;
        indexOfMergeArray++;
    }

    delete[] leftArray;
    delete[] rightArray;
}


/*
Begin is for left index and end is right index of 
the subArray of arr to sorted
*/

void MergeSort(int array[] , int const begin, int const end)
{
    if(begin >= end)
    { return ;    }   // returns recursively

    auto mid = begin + (end - begin) / 2;
    MergeSort(array , begin , mid) ; // left 
    MergeSort(array , mid +1 , end) ; //right
    Merge(array, begin , mid , end) ;
}

// Utilty function : fn. to print an array
void PrintArray(int arr[], int size)
{
    for (int i=0 ; i < size ; i++)
    {
        cout << arr[i] << " " ;
    }
}


//Driver code
int main ()
{
    int array_[] = {12, 11 ,13, 5, 6 ,7};
    //array<int,6> array_ = {12, 11 ,13, 5, 6 ,7};
    auto arr_size = sizeof(array_) / sizeof(array_[0]);

    cout << "Gioven array is \n" ;
    PrintArray(array_ , arr_size);

    MergeSort(array_ , 0 , arr_size -1);
    cout << "\nSorted Array is \n";
    PrintArray(array_ , arr_size);

    return 0 ;
}