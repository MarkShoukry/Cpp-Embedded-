/*
    array based loop
*/
 #include <iostream>
 using namespace std;
 #include <array>
 #include <algorithm>



 int main ()
 {
     int arr1[5] = {0, 15, 25, 74, 9};
     // std::sort(arr1.begin() , arr1.end());      Error compiler
     for (int i=0; i<5 ; i++)
         {
             cout << "Array1 of index (" << i << ") is " << arr1[i] << endl;
         }
    
     //static arry
     cout << "Array 2 element:" << endl;
     array<int, 5> arr2 = {50,26, 13, 3,10};
     std::sort(arr2.begin() , arr2.end());

     for (int element : arr2)            //for (int i=0 ; i < arr2.size() ; i++) {}
     {
         cout <<  element << endl;
     }
     return 0;
}