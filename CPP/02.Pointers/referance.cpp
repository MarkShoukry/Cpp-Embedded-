#include <iostream>
using namespace std;


int main ()
{
    //Alias
    int x = 8;
    int &r = x;

    cout << &x << " " << &r << endl;
    return 0;
}



/*
//this is better----->

int &r = x;
int &r2 = r;
int &r3 = r2;
int &r4 = r3;

//than this---------->

int *p = &y;
int **p2 = &p;
int ***p3 = &p2;
int ****p4 = &p3;


*/

