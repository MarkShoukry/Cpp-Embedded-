/*
super_Class <----is_a-------  Sub_Class

vehicle <-------is_a--------- Bike

*/


#include <iostream>


class vehicle 
{
public:
    virtual void run  ()
    {
        std::cout <<"Vehicle" << std::endl ;
    }

};


class Bike : public vehicle 
{
public:
    void accelerate ()
    {
        std::cout <<"accelerate" << std::endl ;
    }
};



int main ()
{
    vehicle *v = new Bike();
    v->run();
    //v->accelerate(); //compile Error

    Bike *bi = dynamic_cast<Bike*>(v) ;
    bi->run();
    bi->accelerate();
    

    ((Bike *)v)->run();
    ((Bike *)v)->accelerate();

    


    return  0;
}
