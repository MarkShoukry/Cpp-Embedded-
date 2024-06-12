#ifndef FRUIT_H
#define FRUIT_H

#include <utility>
#include <cstdlib>

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

#endif // FRUIT_H
