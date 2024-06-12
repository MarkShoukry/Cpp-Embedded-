#ifndef PLAYINGSTATE_H
#define PLAYINGSTATE_H


#include <windows.h> // For Sleep on Windows
#include <conio.h> // for _kbhit and _getch
#include <set>
#include <memory>
#include <iostream>

#include "GameState.h"
#include "GameController.h"
#include "Snake.h"
#include "GameBoard.h"
#include "Fruit.h"


//class GameController;


class PlayingState : public GameState  
{
public:
    PlayingState(GameController*controller, Snake& snake, GameBoard& board, Fruit& fruit)
                 : m_controller(controller), m_snake(snake) , board(board)
                               ,fruit(fruit), Score(0), SnakeHeadX(0) , SnakeHeadY(1)
        {
        }

    int getScore() const { return Score ; }

    void HandleInput() override
    {
        // Handle user input to control the snake
        if (_kbhit())
        {
            char ch = _getch();
            switch (ch)
            {
            case 'w':
                SnakeHeadX = -1;
                SnakeHeadY = 0 ;
                break;
            case 's':
                SnakeHeadX = 1;
                SnakeHeadY = 0;
                break;
            case 'a':
                SnakeHeadX = 0;
                SnakeHeadY = -1;
                break;
            case 'd':
                SnakeHeadX = 0;
                SnakeHeadY = 1;
                break;
            case 27:
               m_controller->Stop(); // ESC key to stop game
                break;
            }
        }
    }



    void Update() override
    {
        // Get the head position befor moving
        auto head = m_snake.getHead();
        m_snake.Move(SnakeHeadX, SnakeHeadY);
        auto newHead = m_snake.getHead();

        // check for collision with the frame
        if (newHead.first < 0 || newHead.first >= board.getWidth() || newHead.second < 0 || newHead.second >= board.getHeight())
        {    m_controller->Stop() ;  }

        //check for collision with the tail
        const auto& body = m_snake.getBody();
        std::set<std::pair<int , int>> bodyset(body.begin() , body.end());
        if (bodyset.size() < body.size())
        {   m_controller->Stop();    }

        //check for collision with the fruit
        if (newHead == fruit.getPosition())
        {
            m_snake.Grow();
            fruit.generatNewPosition();
            Score += 5 ;
        }
    }




    void Render() override 
    {
        // Render the game board and  print the score
        board.Update(m_snake, fruit.getPosition());
        board.print();
        std::cout << "Score: " << Score << '\n';
    }





private:
    
    GameController* m_controller ;
    Snake& m_snake;
    GameBoard& board;
    Fruit& fruit;

    int Score ;
    int SnakeHeadX;
    int SnakeHeadY;



};



#endif 