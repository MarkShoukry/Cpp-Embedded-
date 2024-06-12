#ifndef PLAYINGSTATE_H
#define PLAYINGSTATE_H

#include <windows.h> // For Sleep on Windows
#include <conio.h> // for _kbhit and _getch
#include <set>
#include "GameState.h"
#include "GameController.h"
#include "Snake.h"
#include "GameBoard.h"
#include "Fruit.h"

class GameController;

class PlayingState : public GameState {
public:
    PlayingState(GameController* controller, Snake& snake, GameBoard& board, Fruit& fruit)
        : controller(controller), snake(snake), board(board), fruit(fruit), score(0), dx(0), dy(1) {}

    std::uint16_t getScore() const { return score; }

    void handleInput() override {
        if (_kbhit()) {
            char ch = _getch();
            switch (ch) {
                case 'w': dx = -1; dy = 0; break;
                case 's': dx = 1; dy = 0; break;
                case 'a': dx = 0; dy = -1; break;
                case 'd': dx = 0; dy = 1; break;
                case 27: controller->stop(); break; // ESC key to stop game
            }
        }
    }

    void update() override {
        auto head = snake.getHead();
        snake.move(dx, dy);
        auto newHead = snake.getHead();

        if (newHead.first < 0 || newHead.first >= board.getWidth() || newHead.second < 0 || newHead.second >= board.getHeight()) {
            controller->stop();
        }

        const auto& body = snake.getBody();
        std::set<std::pair<std::uint16_t, std::uint16_t>> bodySet(body.begin(), body.end());
        if (bodySet.size() < body.size()) {
           controller->stop();
        }

        if (newHead == fruit.getPosition()) {
            snake.grow();
            fruit.generateNewPosition();
            score += 5;
        }
    }

    void render() override {
        board.update(snake, fruit.getPosition());
        board.print();
        std::cout << "Score: " << score << '\n';
    }

private:
    GameController* controller;
    Snake& snake;
    GameBoard& board;
    Fruit& fruit;
    std::uint16_t score;
    int dx, dy;
};

#endif // PLAYINGSTATE_H
