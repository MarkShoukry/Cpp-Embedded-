/*
* Abstract class Shape:
    getDimension
    calculateArea
    displayArea

* derived:
* Circle
* Square

*pointer from shape to point to each object and use the functions by turn (Optional)

*/


#include <iostream>
#include <vector>


//abstract class
class Shape 
{
public :
    Shape (){}
    virtual float calculateArea () =  0;
    virtual void displayArea () = 0 ; 
    virtual ~Shape() = default ; // virtual extract 

   
private:
};


class Circle : public Shape 
{
public:
    Circle (float radius) : m_radius(radius)
    {

    }
    float calculateArea () override
    {
        constexpr double PI = 3.14 ;
        m_Area = 2 *PI *m_radius *m_radius;
        return m_Area ;
    }
    void displayArea () override
    {
        std::cout << "Circle area is " << calculateArea() << std::endl ; 
    }

private :
    float m_radius;
    float m_Area ;

};

class Rectangle : public Shape
{
public:
    Rectangle (float height , float width) :m_Height(height) , m_Width(width)
    {
    }


    float calculateArea () override
    {
        return m_Height * m_Width ;
    }
    void displayArea () override
    {
        std::cout << "Rectangle area is " << calculateArea() << std::endl ; 
    }

private:
    float m_Height ;
    float m_Width ;

};


class Square : public Shape
{
public:
    Square(float height): m_height(height)  
    {
    }


    float calculateArea () override
    {
        return m_height*m_height;
    }

    void displayArea () override
    {
        std::cout << "Squara area is " << calculateArea() << std::endl ; 
    }


private:
    float m_height ;
};




void drawShape (std::vector<Shape*> shapes)
{
    for (auto shape : shapes)
    {
            shape->calculateArea();
            shape->displayArea();
    }

}



typedef std::vector<Shape*> ShapeListType;

int main()
{
    // Shape     *shape ;
    Circle    circle(10.0);
    Rectangle rect(2,4);
    Square    squ(5) ;
    
    ShapeListType shapes;
    shapes.push_back(&circle);
    shapes.push_back(&rect);
    shapes.push_back(&squ) ;

    drawShape(shapes);
    
    
    


    return 0 ;
}