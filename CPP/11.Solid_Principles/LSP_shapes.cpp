/*
LSP:- Liskov Sbstitution Principle
objects of a superclass should be replaceable
with objects of its subclasses without affecting
the correctness of the program.
*/
#include <iostream>
#include <vector>

class Shape 
{
public:
    int height;
    int width ;
    virtual int get_width() const       = 0 ;
    virtual void set_width(int width)   = 0 ;
    virtual int get_height() const      = 0 ;
    virtual void set_height(int height) = 0 ;
    virtual int Area() const            = 0 ;
};

//not true
class Rectangle  //:public Shape
{
public:
    int mwidth;
    int mheight ;
    Rectangle(int w , int h) : mwidth(w) , mheight(h)
    {}
    int get_width() const //override
    {
        return mwidth;
    }
    virtual void set_width(int width)
    {
        this->mwidth = width ;
    }
    int get_height() const //override
    {
        return mheight;
    }
    virtual void set_height(int width)
    {
        this->mheight = mheight ;
    }
    int Area() const //override
    {
        return mwidth * mheight ;
    }
};


//Not True:
class Square : public Rectangle  //:public Shape
{
public:
    Square(int width , int height) 
            :Rectangle(width,height)
    {
    }

    int get_width() const //override
    {
        return mwidth;
    }
    void set_width(int mwidth) override
    {
        mheight =  mwidth = mwidth ;
    }
    int get_height() const //override
    {
        return mheight;
    }
    void set_height(int mheight) override
    {
        mheight = mwidth = mheight ;
    }
    int Area() const //override
    {
        return mwidth * mheight ;
    }
};


void Process (Rectangle& r)
{
    int W = r.get_width(); //5
    r.set_height(10) ; // height =10 , width =10
    std::cout << "expext area = " << (W * 10)
              << " , got " << r.Area()
              << std::endl ;
}

void process2 (Rectangle& r)
{
	int w = r.get_width(); //5
	r.set_height(10); //height =10 , width = 10
	std::cout << "expect area = " << (w * 10) << "  , got " << r.Area() << std::endl;
}

int main()
{
    Rectangle r{5,5};
    
    Process(r);
    

    Square s(5,5);
    
    Process(s) ;
   

    process2(r); 
    process2(s);
}
