#ifndef GAMECONTROLLER_H
#define GAMECONTROLLER_H

#include <memory>
#include <iostream>
#include <windows.h>
#include "GameState.h"
#include "PlayingState.h"
#include "Snake.h"
#include "GameBoard.h"
#include "Fruit.h"

class GameController {
public:
    GameController()
        : isRunning(true), snake(10, 20), board(40, 20), fruit(40, 20), sleepDuration(200), state(nullptr) {}

    void stop() { isRunning = false; }

    void setUp() {
        std::string playerName;
        int difficulty;
        std::cout << "Please Enter Your Name: \n";
        std::cin >> playerName;
        std::cout << "Choose Difficulty:\n1- Easy\n2- Medium\n3- Hard\n";
        std::cin >> difficulty;

        switch (difficulty) {
            case 1:
                sleepDuration = 300;
                break;
            case 2:
                sleepDuration = 200;
                break;
            case 3:
                sleepDuration = 100;
                break;
            default:
                sleepDuration = 200;
                break;
        }
    }

    void setState(std::unique_ptr<GameState> newState) {
        state = std::move(newState);
    }

    void run() {
        setUp();
        setState(std::make_unique<PlayingState>(this, snake, board, fruit));
        while (isRunning) {
            state->handleInput();
            state->update();
            state->render();
            Sleep(sleepDuration);
        }
        endGame(); // Display the end game message
    }

    void endGame() {
        PlayingState* playingState = dynamic_cast<PlayingState*>(state.get());
        if (playingState) {
            std::cout << "Game Over\n";
            std::cout << "Score: " << playingState->getScore() << '\n';
        }
    }

private:
    bool isRunning;
    std::unique_ptr<GameState> state;
    Snake snake;
    GameBoard board;
    Fruit fruit;
    std::uint16_t sleepDuration;
};

#endif // GAMECONTROLLER_H
