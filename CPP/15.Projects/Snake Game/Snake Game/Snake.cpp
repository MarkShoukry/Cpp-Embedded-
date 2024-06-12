#include <deque>
#include <utility>

class Snake {
public:
    Snake(int startX, int startY) {
        // Initialize snake with one segment at the start position
        body.push_back({startX, startY});
    }

    void move(int dx, int dy) {
        // Move the snake by adding a new head and removing the tail
        auto head = body.front();
        body.push_front({head.first + dx, head.second + dy});
        body.pop_back();
    }

    void grow() {
        // Grow the snake by duplicating the last segment
        body.push_back(body.back());
    }

    const std::deque<std::pair<int, int>>& getBody() const {
        return body;
    }

    std::pair<int, int> getHead() const {
        return body.front();
    }

private:
    std::deque<std::pair<int, int>> body; // Deque to store the snake's body segments
};
