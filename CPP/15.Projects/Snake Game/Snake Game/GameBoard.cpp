#include <vector>
#include <iostream>
#include "Snake.cpp"

class GameBoard 
{
public:
    GameBoard(int width, int height) : width(width), height(height) {
        // Initialize the game board with empty spaces
        board.resize(height, std::vector<char>(width, ' '));
    }

    void update(const Snake& snake, const std::pair<int, int>& fruit) {
        clearBoard(); // Clear the board before updating
        // Place the snake segments on the board
        for (const auto& segment : snake.getBody()) {
            board[segment.second][segment.first] = 'O';
        }
        // Place the fruit on the board
        board[fruit.second][fruit.first] = 'F';
    }

    void print() const {
        // Print the game board to the console
        printTopBottomBorder();
        for (const auto& row : board) 
        {
            std::cout << '|';
            for (const auto& cell : row) {
                std::cout << cell;
            }
            std::cout << '|' << '\n';
        }
        printTopBottomBorder();
    }

    int getWidth() const {
        return width;
    }

    int getHeight() const {
        return height;
    }




private:
    void clearBoard() {
        // Fill the board with empty spaces
        for (auto& row : board) {
            std::fill(row.begin(), row.end(), ' ');
        }
    }

    void printTopBottomBorder() const {
        // Print the top and bottom border
        std::cout << '+';
        for (int i = 0; i < width; ++i) {
            std::cout << '-';
        }
        std::cout << '+' << '\n';
    }

    int width, height;
    std::vector<std::vector<char>> board; // 2D vector to represent the game board
};
