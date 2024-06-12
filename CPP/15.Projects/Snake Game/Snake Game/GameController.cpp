#include <memory>
#include "PlayingState.cpp"


class GameController {
public:
    static GameController& getInstance() 
    {
        static GameController instance;
        return instance;
    }

    void run() 
    {
        setup();
        setState(new PlayingState(this, snake, board, fruit));
        while (isRunning) {
            state->handleInput();
            state->update();
            state->render();
            Sleep(sleepDuration);
        }
        endGame(); // Display the end game message
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

    void endGame() {
        // Display the final score and game over message
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
};
