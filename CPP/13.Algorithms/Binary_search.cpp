#include <iostream>
#include <vector>
using namespace std;


// time_complexity = O(Log(n))
int BinarySearch(vector<int> v, int To_Find)
{
    //first = 0 , last = size - 1
    int first = 0 , last = v.size() - 1 ;
    int mid ;
    // This below check covers all cases , so need to check
    // for mid=lo-(hi-lo)/2
    while(last - first > 1)
    {
        mid = (last + first ) / 2 ;

        if(v[mid] < To_Find)
        {
            first = mid +1 ;
        }
        else 
        {
            last = mid ;
        }
    }    
    if(v[first] == To_Find)
    {
        cout << "Found" << " At Index " << first << endl ;
    }
    else if (v[last] == To_Find)
    {
        cout << "Found" << " At Index " << last << endl ;
    }
    else 
    {
        cout << "Not Found" << endl ;
    }
}


int main ()
{
    vector<int> v = {1,3,5,7,9, 12, 13};
    int ToFind = 0 ;
    cout << "Please Enter Key to search:\n" ;
    cin >> ToFind ;
    BinarySearch(v, ToFind);

    return 0;
}