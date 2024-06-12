/*Vector:
size() : actual number of elements
capacity() : actual avaliable memory space

*/

#include <iostream>
#include <vector>
#include <utility>

using namespace std ;


int main ()
{
    //std::vector<std::pair<std::string, int>> myVector;
    vector <pair <string,int> > myvector ;
    myvector.push_back(std::make_pair<std::string, int>("Mark" , 3));
    myvector.push_back(std::make_pair<std::string,int>("Fouad",1)); 
    myvector.emplace_back("karim",2) ;


    for (auto element : myvector)
    {
        cout << element.first << " " ;
        cout << element.second << endl ;
    }

    cout <<"size: " << myvector.size() <<" capacity: " << myvector.capacity() << endl ; 

    return 0 ;
}