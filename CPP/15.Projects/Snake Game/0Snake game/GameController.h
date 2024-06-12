#ifndef GAMECONTROLLER_H
#define GAMECONTROLLER_H

#include "PlayingState.h"
#include <iostream>


class PlayingState;


class GameController
{
public:
        GameController() :isRunning(true), State(nullptr), snake(10,20), board(40,20), fruit(40,20), sleepDuration(200)
    {
    }

    static GameController& getInstance()
    {
        static GameController instance ;
        return instance;
    }

    void Stop()   {  isRunning = false ;  }

    void SetUp()
    {
        std::string PlayerName ;
        int Diffeculty;
        std::cout << "Please Eneter Your Name: \n" ;
        std::cin >> PlayerName ;
        std::cout << "Choose Difficulty:\n1- Easy\n2- Medium\n3- Hard\n" ;
        std::cin >> Diffeculty;

        switch (Diffeculty)
        {
            case '1':
                sleepDuration = 300;
                break;
            case '2':
                sleepDuration = 200;
                break;
            case '3':
                sleepDuration = 100;
                break;
            default:
                sleepDuration = 200;
                break;
        }
    }

    void SetState (std::unique_ptr<GameState> newState)
    {
        State = std::move(newState) ;
    }

    void Run()
    {
        SetUp();
        SetState(std::make_unique<PlayingState>(this, snake, board, fruit));
        while (isRunning)
        {
            State->HandleInput();
            State->Update();
            State->Render();
            Sleep(sleepDuration);
        }
        EndGame(); //Display the end game message
    }



    void EndGame()
    {
        PlayingState* m_PlayingState = dynamic_cast<PlayingState*>(State.get());
        if(m_PlayingState)
        {
            std::cout << "Game Over\n" ;
            std::cout <<"Score: " << m_PlayingState->getScore() << '\n' ;
        }
    }




private:
    // GameController() :isRunning(true), State(nullptr), snake(10,20), board(40,20), fruit(40,20), sleepDuration(200)
    // {
    // }

    // GameController(const GameController&) = delete;
    // GameController& operator=(const GameController&) = delete;

    bool isRunning;
    std::unique_ptr<GameState> State;
    Snake snake;
    GameBoard board;
    Fruit fruit;

    int sleepDuration;

};

#endif 