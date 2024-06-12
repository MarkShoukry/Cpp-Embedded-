#include <iostream>
#include <vector>
#include <algorithm>
#include <functional> 

class Graphic
{
public:
    virtual void draw() const = 0;  // pure virtual function
    virtual void Add(Graphic *g) {}
    virtual void Remove (Graphic *g) {}
    virtual void GetChild(int ) {}
    virtual ~Graphic () {} //virtual destructor
};



class Line : public Graphic
{
public:
    void draw() const override
    {   
        std::cout << "Line draw() \n" ;
    }
};

class Rectangle : public Graphic
{
public:
    void draw() const override
    {   
        std::cout << "Rectangle draw() \n" ;
    }
};

class Text : public Graphic
{
public:
    void draw() const override
    {   
        std::cout << "Text draw() \n" ;
    }
};


//composite
class Picture : public Graphic
{
public:
    void draw() const override
    {
       // for (const auto &graphic : graphic_list)     
                    // {   graphic->draw() ;     }
    // for_each(graphic_list.begin(), graphic_list.end() , [this]()   { draw();  } );

    for_each(graphic_list.begin() , graphic_list.end() , std::mem_fun(&Graphic::draw) ) ;
    
    }

    void Add(Graphic *graphic) override
    {
        graphic_list.push_back(graphic) ;
    }

private:
    std::vector<Graphic*>graphic_list ;
};


int main ()
{
    Rectangle rec1 , rec2;
    Line l1;
    Text t1;
    Picture pic;

    pic.Add(&rec1);   //Aggregation
    pic.Add(&l1);
    pic.Add(&t1);
    pic.Add(&rec2);

    pic.draw();

    

    return 0 ; 
}