// A stringstream associates a string object with a stream 
// allowing you to read from the string as if it were a stream (like cin). 
// To use stringstream, we need to include <sstream> header file. 
// The stringstream class is extremely useful in parsing input.


#include <sstream>
#include <iostream>
#include <vector>
using namespace std;


    vector<int> parseInts(string str)
    {
        stringstream s(str);
        vector<int> a;
        char ch ;
        int t ;
        while (s >> t )
        {
            a.push_back(t);
            s >> ch ;
        }
        return a ;

    }



int main ()
{
    string str;
    cin >> str;
    vector<int>integers = parseInts(str);

    for (int i= 0 ; i< integers.size() ; i++ )
    {
        cout << integers[i] << endl;
    }
    


    return 0 ;
}
