#include <iostream>
#include <set>
#include <unordered_set>
using namespace std;


int main ()
{
    //initialize a set of int type, doesn't allow duplication
    set<int>num = {1, 100, 10, 70, 100};
    multiset<int> mul_num = {1, 100, 10, 70, 100};

    //print the set
    cout << "Set Numbers are :  " ;
    for (auto &num: num)
    {
        cout << num << ", ";
    } 
    
    //print Multi
    cout << "\nMulti Number are : " ;
    for (auto &num: mul_num)
    {
        cout << num << ", ";
    }

    //initialize an unordered set of int type
    multiset<int> num_allow_duplicate ;
    num_allow_duplicate.insert(70);
    num_allow_duplicate.insert(88);
    num_allow_duplicate.insert(50);
    num_allow_duplicate.insert(70);
    //print unordered set
    cout << "\nnumbers_allow_duplicate are : " ;
    for (auto &num : num_allow_duplicate)
    {
        cout << num << ", " ;
    }
    num_allow_duplicate = { 100,1, 10, 70, 100};
    cout << "\nnumbers_allow_duplicate are : " ;
    for (auto &num : num_allow_duplicate)
    {
        cout << num << ", " ;
    }



    return 0;
}