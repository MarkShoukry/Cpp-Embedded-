#include <iostream>
using namespace std;


int GetValue()
{
    return 10;
}

int& GetValueRef ()
{
    static int value = 20 ; // data segment
    return value ;
}

void PrintName (string& Name) // &
{
    cout << "Left Value Referance " << Name << endl ;
}

void Print_Name (string&& mName) // rvalue referance
{
    cout << "Right Value Referance " << mName << endl ;
}







int main ()
{
    // var is lvalue , 10 is rvalue means it has no location
    int i = 10 ;
    i = GetValue(); // ok
    cout << "i = " << i  << endl ;

    int& var = GetValueRef();
    cout << "var = " << var << endl  ;
    // 10 = i; //you can't do that
    // GetValue() = 10;

    GetValueRef() = 5 ;
    cout << "GetValueRef() = " << GetValueRef() << endl  ;

    string firstname = "Robotics" ; //temp
    string lastname ="Corner" ; //temp
    string fullname = firstname + lastname ;


    PrintName (fullname); //string& mName

    Print_Name(firstname + lastname) ; //string&& mName
    



    return 0;
}