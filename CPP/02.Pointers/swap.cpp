#include <iostream>
using namespace std;


//function prototype 
void swap (int &r1 , int &r2);


int main ()
{
    int num1 , num2 ;
    int *ptr1 = &num1;
    // Enter value of number 1 and number 2 
    cout << "Please enter number 1 and number 2 to swap: " << endl ;
    cin >> num1 >> num2;
    
    //print the defferant of address and value of nuumber 1 and that pointer
    printf("Address of num1 is %x , Address of that pointer to %x \n" , &num1 , ptr1);    //address 
    printf("Value of num1 is %d , Value of that pointer to %d \n" , num1 , *ptr1);        //value
    printf("Address of Pointer is %x \n", &ptr1);                                         //address of pointer
    cout << endl;
   
    //function of swap
    cout << "Before swapping: num1 = " << num1 << " num2 = " << num2 << endl;
    swap(num1 , num2);
    cout << "After swapping: num1 = " << num1 << " num2 = " << num2 << endl;


    return 0;
}





//function of swap
// void swap (int *num1 , int *num2)
// {
//     int temp = *num1 ;
//     *num1 = *num2 ;
//     *num2 = temp ;

// }

void swap (int &r1 , int &r2)
{
    int temp = r1 ;
    r1 = r2 ;
    r2 = temp ;

}
