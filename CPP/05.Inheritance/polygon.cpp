#include <iostream>
#include <vector>

using namespace std;

//base class
class polygon
{
public:
    polygon(){}
    virtual void Show()
    {
        cout << "Polygon show" << endl ; 
    }
};

class Triangle : public polygon
{
public:
    Triangle()
    {
    }

    void Show ()
    {
        cout << "Triangle is 3 sided polygon" << endl ;   
    }
};

class Rectangle : public polygon
{
public:
    Rectangle(){}
    void Show()
    {
        cout << "Rectangle is 4 sided polygon" << endl ;
    }
};


void ShowPolygon (vector<polygon*>polygons)
{
    for (auto polygon : polygons)
    {
        polygon->Show() ;
    }
}




int main()
{
    polygon *p ;
    Triangle t;
    Rectangle r;

    vector<polygon*>list;
    list.push_back(&t);
    list.push_back(&r);

    ShowPolygon(list);


    return 0 ;
}








/*
int main ()
{

    polygon *p ;  //pointer to he base class
    Triangle t; //vptr will be created vptr-> vtable-> vtable[0]
    p = &t; //points to triangle object [vptr is obtained]

    p->Show(); //vtable is accessed to obtain address of show in the triangle object

    Rectangle r;
    p =&r;
    p->Show();
    return 0;
}
*/