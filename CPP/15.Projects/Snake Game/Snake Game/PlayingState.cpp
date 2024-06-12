#include <conio.h>
#include <windows.h> // For Sleep on Windows
#include <set>
#include "GameState.cpp"
#include <iostream>
#include "GameBoard.cpp"
#include "Fruit.cpp"

class GameController; // Forward declaration

class PlayingState : public GameState {
public:
    PlayingState(GameController* controller, Snake& snake, GameBoard& board, Fruit& fruit)
        : controller(controller), snake(snake), board(board), fruit(fruit), score(0), dx(0), dy(1) 
        {}

    void handleInput() override {
        // Handle user input to control the snake
        if (_kbhit()) {
            char ch = _getch();
            switch (ch) {
                case 'w': dx = -1; dy = 0; break;
                case 's': dx = 1; dy = 0; break;
                case 'a': dx = 0; dy = -1; break;
                case 'd': dx = 0; dy = 1; break;
                case 27: controller->stop(); break; // ESC key to stop the game
            }
        }
    }

    void update() override {
        // Get the head position before moving
        auto head = snake.getHead();
        snake.move(dx, dy);
        auto newHead = snake.getHead();

        // Check for collision with the frame
        if (newHead.first < 0 || newHead.first >= board.getWidth() || newHead.second < 0 || newHead.second >= board.getHeight()) {
            controller->stop();
        }

        // Check for collision with the tail
        const auto& body = snake.getBody();
        std::set<std::pair<int, int>> bodySet(body.begin(), body.end());
        if (bodySet.size() < body.size()) {
            controller->stop();
        }

        // Check for collision with the fruit
        if (newHead == fruit.getPosition()) {
            snake.grow();
            fruit.generateNewPosition();
            score += 5;
        }
    }

    void render() override {
        // Render the game board and print the score
        board.update(snake, fruit.getPosition());
        board.print();
        std::cout << "Score: " << score << '\n';
    }

    int getScore() const {
        return score;
    }

private:
    GameController* controller;
    Snake& snake;
    GameBoard& board;
    Fruit& fruit;
    int score;
    int dx, dy;
};
