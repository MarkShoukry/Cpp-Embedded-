#include <iostream>
using namespace std;

class Entry
{
    public:
    int var ;
};


int main ()
{
    //allocate in heep
    Entry * heep_entry = new Entry ();


    //allocate in stack
    char buf[20];
    printf("address %x" , buf);
    Entry *entry = new (buf) Entry();


    entry->var = 10 ;

    return 0 ;
}