#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;

class Attribute
{
public:
    Attribute(string name , string value) :Name(name) , Value(value)
    {}
    string Name;
    string Value;
};


class Tag
{
public:
    string TagName;
    Tag *Parent;
    vector<Attribute*> attribute; // < name, value>

    Tag(string tagName, Tag *parent_ptr = nullptr)
    {
        TagName = tagName;
        Parent = parent_ptr;
    }


    string GenerateHashKay()
    {
        string key = "." + TagName;
        string ParentName;
        Tag* currentParent = Parent;
        while (currentParent != nullptr)
        {
            ParentName = "." + currentParent->TagName;
            key.insert(0, ParentName);
            currentParent = currentParent->Parent;
        }
        return key ;
    }
};

void ProcessQueries(int q, unordered_map<string, Tag*> &tag_map)
{
    string query;
    int tildaIndex;
    for (int i = 0 ; i <q ; i++)
        {
            cin >> query;
            tildaIndex = query.find('~');

                if(tildaIndex != string::npos)
                    {
                        string key = "." + query.substr(0, tildaIndex);
                        if(tag_map[key] == nullptr)
                            {
                                cout << "Not Found!" << endl ;
                                continue;
                            }

                        
                    }
            
        }      
}



int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    return 0;
}


