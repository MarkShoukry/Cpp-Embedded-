/*
Composite Design Pattern :-

    Composite is a structural design pattern that 
allows composing objects into a tree-like structure 
and work with the it as if it was a singular object. 

*/

#include <iostream>
#include <vector>

class Component
{
public:
    virtual std::string Operation()
    {
        return "Apply operation ";
    }

    virtual void Add()
    {
        std::cout << "Add " << Operation() ; 
    }
    virtual void Remove()
    {
        std::cout << "Remove " << Operation()  ;
    }


};



class leaf : public Component
{
public:
    std::string Operation () override 
    {
        return "Apply Leaf operator \n" ;
    }

};


class Composite : public Component
{
public:
    Composite (std::vector<Component>components) :m_components(components)
    {

    }
    
    
    std::string Operation () override 
    {
        return "composite operator \n" ;
    } 

    void Add () override
    {
        for (auto Component : m_components)
        {
            Component.Add() ;
        }
    }  


    void Remove () override
    {
        for (auto Component : m_components)
        {
            Component.Remove(); 
        }
    }

private:
    std::vector<Component> m_components;
};




int main ()
{
    leaf leaf1 ;
    Composite composite1(std::vector<Component>com_list); 
    Component component1 ;

    

    return  0;
}