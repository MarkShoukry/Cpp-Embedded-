/*
    program to convert a decimal number to binary number
    program to convert a decimal number to hexdecimal number
*/
#include <iostream>
using namespace std;


void Dec_To_Bin (int num);
void Dec_To_Hex(int num);


int main ()
{
    int16_t num = 0;
    cout << "Please Enter Number" << endl;
    cin >> num ;
    cout <<"Convet a decimal number (" << num << ") to binary is " ; 
    Dec_To_Bin(num);
    cout <<"Convet a decimal number (" << num << ") to hexdecimal is " ;
    Dec_To_Hex(num); 
    
    
    return 0;

}

//function to convert a decimal number to binary number

void Dec_To_Bin (int num)
{
    // Array to store binary number
    int16_t binarynum[32];

    // Counter for binary array
    int16_t i=0;
    while ((num > 0))
    {       
        // Storing remainder in binary
        binarynum[i]  = num % 2;
        num /= 2;
        i++;  
    }
        // Printing binary array in reverse
    for (int j = i - 1; j >= 0; j--)
    {
        cout << binarynum[j] ;
    }

}


//function to convert a decimal number to hexdecimal number
void Dec_To_Hex(int num)
{
    
}
