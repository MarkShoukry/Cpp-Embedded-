//somtng wrong code in geeksforgeeks

#include <iostream>
using namespace std;

string Dec_To_Hex (int16_t num  );

int main ()
{   
    int16_t num ;
    cout << "Please enter a decimal number" << endl;
    cin >> num;
    cout << Dec_To_Hex (num);

    return 0;
}



string Dec_To_Hex (int16_t num  )
{
    int16_t rem = 0 ;
    string ans = "";
    char ch ;

    while (num != 0)
    {
        rem = num % 16 ;
        if (rem < 10)
           {
            ch = rem = 48 ;
           }
        else {
            ch = rem + 55 ;
        }     

        ans += ch ;
        num = num / 16 ;
    }
    int16_t i =0 , j = ans.size() -1 ;
    while ( i <= j)
    {
        swap(ans[i], ans[j]);
        i++;
        j--;
    }
    return ans;
    

}