#include "Circle.h"
#include "Triangle.h"
#include "Rectangle.h"
#include "Square.h"


typedef std::vector<std::shared_ptr<Shape>> &AllShapes ;

void PrintShape(const AllShapes &v) 
{
    for (const auto& element : v  )
    {
        std::cout << "Area is " << element->Area() << '\n';
        
    }
}



int main ()
{
    Circle c1(5);
    Triangle t1(4 ,3) ;
    Rectangle r1(2,4);

    std::vector<std::shared_ptr<Shape>> shapes ;
    shapes.push_back(std::make_shared<Circle>(c1));
    shapes.push_back(std::make_shared<Triangle>(t1));
    shapes.push_back(std::make_shared<Rectangle>(r1));

    PrintShape(shapes);

    Square s1(6);
    shapes.push_back(std::make_shared<Square>(s1));
    PrintShape(shapes) ;
    
    return 0 ;
}