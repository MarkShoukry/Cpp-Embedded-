#pragma once

#include <iostream>
#include <deque>
#include <utility>

class Snake
{
public:
    Snake(int startX, int startY)
    {
       // Initialize snake with one segment at the start position
       m_Body.push_back({startX, startY});
    }

    void Move(int snakeHeadX, int snakeHeadY)
    {
        // Move the snake by adding a new head and removing the tail
        auto head = m_Body.front();
        m_Body.push_front({head.first + snakeHeadX, head.second + snakeHeadY});
        m_Body.pop_back();
    }

    void Grow()
    {
        //Grow the snake by duplicating the last segment
        m_Body.push_back(m_Body.back());
    }

    const std::deque<std::pair<int, int>>& getBody() const
    {
        return m_Body ;
    }

    std::pair<int, int> getHead() const 
    {
        return m_Body.front() ;
    }


private:

    // Deque to store the snake's body segments
    std::deque<std::pair<int, int>> m_Body;


};