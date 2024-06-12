#include <iostream>
#include <vector> 
#include <algorithm>
#include <functional>
using namespace std;

class Record 
{
    public :
    string Name ;
    uint16_t Id ;
};



template<class T>
void sort( typename T::iterator first , typename T::iterator last, 
        std::function <bool(typename T::value&, typename T::value&)> comp  ) 
{
    std::sort(first, last , comp);
}

int main ()
{
    vector<Record>record(4) ;

    cout <<"strategy pattern example\n";
    record[0].Name = "MArk" ;
    record[0].Id = 9 ;
    record[1].Name = "Omer_Mohamed" ;
    record[1].Id = 3 ;
    record[2].Name = "Ali" ;
    record[2].Id = 5 ;
    record[3].Name = "Abanoub" ;
    record[3].Id = 4 ;

    auto CmpareByName = [](Record& a, Record& b)->bool {return a.Name < b.Name ;};
    auto CmpareByID = [](Record& a, Record& b)->bool {return a.Id < b.Id ;};

    cout << "Sort by Name:" << endl ;
    sort(record.begin() , record.end() , CmpareByName );

    for (auto R : record)
    {
        cout << "Name: " << R.Name << " --- Id: " << R.Id << endl ;
    }
    cout << endl ;


    cout <<"Sort by Id:" << endl;
    sort(record.begin() , record.end() , CmpareByID );

    for (auto R : record)
    {
        cout << "Name: " << R.Name << " --- Id: " << R.Id << endl ;
    }
    
    return 0;
}