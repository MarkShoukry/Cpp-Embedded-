//program: to get max of numbers 


#include <iostream>
#include <array>
using namespace std;

int Get_Max (int a, int b, int c, int d);

int main ()
{
    int16_t a = 0, b = 0, c = 0, d = 0;
    cout << "Please Enter four num to get max" << endl;
    cin >> a >> b >> c >> d ;
    int result = Get_Max(a,b,c,d);
    cout << "Max f num is " << result ;
    return 0;
}

int Get_Max (int a, int b, int c, int d)
{
    int16_t result =0;
    int arr[4] = {a  , b , c , d};
    for (int i=0 ; i <4 ; i++)
        {
         if (arr[i] > result)
            {result = arr[i];}  
        }
       return result ;
}