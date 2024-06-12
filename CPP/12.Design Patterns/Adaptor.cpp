#include <iostream>
#include "legacy.h"
using namespace std;

extern "C"
{
#include "legacy_functions.h"
}


// desired interface (Target)
class Rectangle 
{
public:
    virtual void Draw() = 0 ;
};

// Adapter Wrapper
class RectangleAdapter : public Rectangle , private LegacyRectangle
{
public:
    RectangleAdapter(int x, int y , int w, int h) :LegacyRectangle(x, y , x + w , y + h)
    {
        cout << "RetangleAdapter(x,y,x+w,y+h)\n" ;
    }
    void Draw() override
    {
        cout << "RectangleAdapter: draw().\n" ;
        OldDraw();
        veryOldDraw();  // legacy_functions.h
    }

};



int main ()
{
    int x =20 , y = 50 , w= 300, h = 200 ;
    Rectangle *r = new RectangleAdapter(x,y,w,h);
    r->Draw();
    //Can't be called because its privately inherited from LegacyRectangle
    //r->oldDraw();
    return 0;
}