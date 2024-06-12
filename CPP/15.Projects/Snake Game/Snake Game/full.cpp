#include <cstdlib>
#include <iostream>
#include <vector>
#include <memory>
#include <conio.h>
#include <windows.h> // For Sleep on Windows
#include <set>
#include <deque>
#include <utility>

// Forward declarations
class GameController;
class PlayingState;
class Fruit;
class Snake;
class GameBoard;

// GameState base class
class GameState {
public:
    virtual void handleInput() = 0;
    virtual void update() = 0;
    virtual void render() = 0;
    virtual ~GameState() = default;
};

// Fruit class
class Fruit {
public:
    Fruit(int width, int height) : width(width), height(height) {
        generateNewPosition();
    }

    std::pair<int, int> getPosition() const {
        return position;
    }

    void generateNewPosition() {
        position.first = rand() % width;
        position.second = rand() % height;
    }

private:
    int width, height;
    std::pair<int, int> position;
};

// Snake class
class Snake {
public:
    Snake(int startX, int startY) {
        body.push_back({startX, startY});
    }

    void move(int dx, int dy) {
        auto head = body.front();
        body.push_front({head.first + dx, head.second + dy});
        body.pop_back();
    }

    void grow() {
        body.push_back(body.back());
    }

    const std::deque<std::pair<int, int>>& getBody() const {
        return body;
    }

    std::pair<int, int> getHead() const {
        return body.front();
    }

private:
    std::deque<std::pair<int, int>> body;
};

// GameBoard class
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

    int getWidth() const {
        return width;
    }

    int getHeight() const {
        return height;
    }

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

// GameController singleton class
class GameController {
public:
    static GameController& getInstance() {
        static GameController instance;
        return instance;
    }

    void run() {
        setup();
        setState(new PlayingState(this, snake, board, fruit));
        while (isRunning) {
            state->handleInput();
            state->update();
            state->render();
            Sleep(sleepDuration);
        }
        endGame();
    }

    void stop() {
        isRunning = false;
    }

    void setState(GameState* newState) {
        delete state;
        state = newState;
    }

    void setup() {
        std::string playerName;
        int difficulty;
        std::cout << "Enter your name: ";
        std::cin >> playerName;
        std::cout << "Choose difficulty (1 - Easy, 2 - Medium, 3 - Hard): ";
        std::cin >> difficulty;
        switch (difficulty) {
            case 1: sleepDuration = 300; break;
            case 2: sleepDuration = 200; break;
            case 3: sleepDuration = 100; break;
            default: sleepDuration = 200; break;
        }
    }

    void GameController::endGame() {
        PlayingState* playingState = dynamic_cast<PlayingState*>(state);
        if (playingState) {
            std::cout << "Game Over\n";
            std::cout << "Score: " << playingState->getScore() << '\n';
        }
    }

private:
    GameController() : isRunning(true), state(nullptr), snake(10, 20), board(40, 20), fruit(40, 20), sleepDuration(200) {}

    GameController(const GameController&) = delete;
    GameController& operator=(const GameController&) = delete;

    bool isRunning;
    GameState* state;
    Snake snake;
    GameBoard board;
    Fruit fruit;
    int sleepDuration;

    friend class PlayingState;
};

// PlayingState class
class PlayingState : public GameState {
public:
    PlayingState(GameController* controller, Snake& snake, GameBoard& board, Fruit& fruit)
        : controller(controller), snake(snake), board(board), fruit(fruit), score(0), dx(0), dy(1) {}

    void handleInput() override {
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
        auto head = snake.getHead();
        snake.move(dx, dy);
        auto newHead = snake.getHead();

        if (newHead.first < 0 || newHead.first >= board.getWidth() || newHead.second < 0 || newHead.second >= board.getHeight()) {
            controller->stop();
        }

        const auto& body = snake.getBody();
        std::set<std::pair<int, int>> bodySet(body.begin(), body.end());
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

// Main function
int main() 
{
    GameController& controller = GameController::getInstance();
    controller.run();
    return 0;
}