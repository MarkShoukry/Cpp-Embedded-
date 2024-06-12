#include <iostream>

class Shape 
{
public :
    Shape ()
    {

    }
    virtual void draw () 
    {
        std::cout << "Draw Shape" << std::endl; 
    }

private:
};

class Circle : public Shape
{
public:
    Circle ()
    {

    }
    void draw ()
    {
        std::cout << "Draw Circle" << std::endl ;
    }
    double Area (float reduis)
    {
        constexpr double PI = 3.14 ;
        return 2*PI*reduis*reduis;
    }
private:
};

class Elipse : public Circle  
{
public:
    Elipse ()
    {

    }
    void draw ()
    {
        std::cout << "Draw Elipse" << std::endl; 
    }
private:
};




int main ()
{
    Shape *shape ;
    Shape  concrete_shape ;
    Circle circle ;

    Elipse elipse ;
    shape = &circle ; 
    shape->draw();

    elipse.draw() ;
    concrete_shape.draw();



    return  0;
}