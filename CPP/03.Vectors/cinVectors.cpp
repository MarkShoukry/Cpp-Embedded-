#include <iostream>
#include <vector>
using namespace std;

void inputvector (vector<int>& nums)
{
    cout << "Please Enter elements of vector " << endl ;
    for (auto& element : nums)
        {
            cin >> element ; 
        } 
}


void outputvector (vector<int>& nums)
{
    cout << "ELements of vector is:" << endl; 
    for (auto element : nums)
        {
            cout << element << " " ;
        }
    cout << endl ;
}

int main ()
{
    vector<int>nums(4,0);
    inputvector(nums);
    outputvector(nums);

    cout <<"size of nums is " << nums.size() << " capacity of nums is " << nums.capacity() << endl ; 
    nums.push_back(7) ;
    nums.push_back(8);

    outputvector(nums);
    cout <<"size of nums is " << nums.size() << " capacity of nums is " << nums.capacity() << endl ; 


    return 0;
}