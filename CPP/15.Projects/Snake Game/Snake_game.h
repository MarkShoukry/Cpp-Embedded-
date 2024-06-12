#pragma once 
#include <iostream>
#include <vector>
#include <windows.h> 
#include <conio.h>
#include <cstdlib>  // for rand, srand
#include <ctime>    // for time    
#include <unistd.h>



class SnakeGame
{
private:
    bool isGameOver; // boolean variable for checking game is over or not 
    int width , height; // height and width of the boundary 
    
    // Snake head coordinates of snake (x-axis, y-axis) 
    int snakeHeadX, snakeHeadY;
    // Food coordinates 
    int fruitX, fruitY ;
    int score;

    std::vector<int> snakeTailX , snakeTailY ;
    int snakeTailLength;

    // for storing snake's moving snakesDirection 
    enum eDirection 
    {
        STOP = 0 ,
        LEFT,
        RIGHT,
        UP,
        DOWN
    };
    eDirection dir ;  // snakesDirection variable 

public:

    

    bool getIsGameOver () { return isGameOver ;}

    void GameInit();
    void GameRender(std::string PlayerName);
    void Input();
    void UpdateGame();

};