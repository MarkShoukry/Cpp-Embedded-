#pragma once 
#include <vector>
#include <iostream>
#include "GameState.h"
#include "Snake.h"

class GameBoard
{
public:
    GameBoard(int width, int height) : m_Width(width) , m_Height(height)
    {
        // Initialize the game board with empty spaces
        m_Board.resize(m_Height, std::vector<char>(m_Width, ' ' ));
    }

    void Update (const Snake& snake, const std::pair<int, int>& fruit) 
    {
        clearBoard(); //clear the board before updating
        //place the snake segments on the board
        for (const auto& segment : snake.getBody())
        {
            m_Board[segment.second][segment.first] = '0';
        }
        //place the fruit on the board
        m_Board[fruit.second][fruit.first] = '*' ;
    }    


    void print() const 
    {
        //print the game board to the console
        printTopBottomBorder();
        for (const auto& row : m_Board)
        {
            std::cout << '|' ;

                for (const auto& cell : row)
                {
                    std::cout << cell ;
                }
            std::cout << '|' << '\n' ;
        }
        printTopBottomBorder() ;
    }


    int getWidth() const  {   return m_Width ;   }

    int getHeight() const {   return m_Height ;  }




private:
    void clearBoard()
    {
        //Fill the board with empty spaces
        for(auto& row : m_Board)
        {
            std::fill(row.begin(), row.end(), ' ');
        }
    }


    void printTopBottomBorder() const
    {
        //print the top and bottom boarder
        std::cout << "+" ;
        for (int i = 0 ; i < m_Width; i++)
        {
            std::cout << "-" ;
        }
        std::cout << '+' << std::endl ;
    }



    int m_Width ;
    int m_Height;
    // 2D vector to represent the game board
    std::vector<std::vector<char>> m_Board ;

};