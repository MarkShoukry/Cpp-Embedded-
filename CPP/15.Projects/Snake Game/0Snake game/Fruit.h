#pragma once
#include <iostream>


class Fruit
{

public:
    Fruit(int width , int height)
            : m_Width(width) , m_Height(height)
    {
        generatNewPosition();
    }

    std::pair<int , int> getPosition() const
    {   
        return Position;
    }

    void generatNewPosition()
    {
        //Generate a new random position for the fruit
        Position.first  = rand() % m_Width  ;
        Position.second = rand() % m_Height ;
    }


private:
    int m_Width ;
    int m_Height;

    //current position of the fruit
    std::pair<int, int> Position;

};