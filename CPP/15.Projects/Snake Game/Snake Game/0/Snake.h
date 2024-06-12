#ifndef SNAKE_H
#define SNAKE_H

#include <deque>
#include <utility>

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

#endif // SNAKE_H
