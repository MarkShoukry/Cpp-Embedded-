#ifndef GAMEBOARD_H
#define GAMEBOARD_H

#include <vector>
#include <iostream>
#include "Snake.h"

class GameBoard {
public:
    GameBoard(int width, int height) : width(width), height(height) {
        board.resize(height, std::vector<char>(width, ' '));
    }

    void update(const Snake& snake, const std::pair<int, int>& fruit) {
        clearBoard();
        for (const auto& segment : snake.getBody()) {
            board[segment.second][segment.first] = 'O';
        }
        board[fruit.second][fruit.first] = 'F';
    }

    void print() const {
        printTopBottomBorder();
        for (const auto& row : board) {
            std::cout << '|';
            for (const auto& cell : row) {
                std::cout << cell;
            }
            std::cout << '|' << '\n';
        }
        printTopBottomBorder();
    }

    int getWidth() const { return width; }
    int getHeight() const { return height; }

private:
    void clearBoard() {
        for (auto& row : board) {
            std::fill(row.begin(), row.end(), ' ');
        }
    }

    void printTopBottomBorder() const {
        std::cout << '+';
        for (int i = 0; i < width; ++i) {
            std::cout << '-';
        }
        std::cout << '+' << '\n';
    }

    int width, height;
    std::vector<std::vector<char>> board;
};

#endif // GAMEBOARD_H
