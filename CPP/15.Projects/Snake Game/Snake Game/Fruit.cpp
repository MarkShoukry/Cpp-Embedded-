#include <cstdlib>
#include <iostream>

class Fruit {
public:
    Fruit(int width, int height) : width(width), height(height) {
        generateNewPosition();
    }

    std::pair<int, int> getPosition() const {
        return position;
    }

    void generateNewPosition() {
        // Generate a new random position for the fruit
        position.first = rand() % width;
        position.second = rand() % height;
    }

private:
    int width, height;
    std::pair<int, int> position; // Current position of the fruit
};
