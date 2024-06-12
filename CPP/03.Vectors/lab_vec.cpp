#include <iostream>
#include <vector>
#include <iomanip>
#include <stdexcept>
using namespace std;

void outputvector (const vector<int> &);
void inputvector (vector<int>&);


int main ()
{
    vector<int> num1(7);
    vector<int> num2(10);

    cout << "Size of vector num1 is " << num1.size() 
         << "\nVector after initialization: " << endl;
    
    outputvector(num1);

    cout << "Size of vector num2 is " << num2.size() 
         << "\nVector after initialization: " << endl;
    
    outputvector(num2);


    // input and print num1 & num2 
    cout << "Please Enter 17 number:" << endl ;
    inputvector(num1);
    inputvector(num2);


    cout << "The vector (num1) contain " << endl;
    outputvector(num1);
    cout << "The vector (num2) contain " << endl;
    outputvector(num2);


    //use equality (==) operator with vector objects
    cout << "\nEvaluating: num1 == num2" << endl; 

    if (num1 == num2)
        {cout <<"num1 and num2 are equal" << endl; }
    
    cout << "\nnum1[5] is " << num1[5];

    cout << "\n\nAssigning 1000 to num[5]" << endl;
    num1[5] = 1000;
    cout << "num1" << endl;
    outputvector(num1) ;

    //attempt to use out-of-range subscript
    try
    {
        cout << "\nAttempt to display num1.at(15)" << endl;
        cout << num1.at(15) << endl;   //Error:out of range
    }
    catch(out_of_range &ex)
    {
        cerr << "An exception occurred: "<< ex.what() << '\n';
    }
    

    //chamging the size of a vector
    vector<int>num3;
    cout << "\nCurrent num3 size is: " <<num3.size() << endl;
    num3.push_back(1000);
    cout <<"New num3 size is: " << num3.size() << endl;
    cout << "num3 now contains: " ;
    outputvector(num3);


    return 0;
}


void outputvector (const vector<int> &array)
{
    for (auto element : array)
        {    cout << element << " " ;        }
    cout << endl;
}


void inputvector (vector<int>&array)
{
    for (auto & element : array)
        {     cin >> element ;     }
}