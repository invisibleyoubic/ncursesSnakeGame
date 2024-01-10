#pragma once

#include <queue>
#include "symbol.hpp"


enum SnakeDirection
{
    Up = -1,
    Down = 1,
    Right = -2,
    Left = 2,
};

class Snake
{
public:
    Snake();
    void addSegment(const SnakeSegment segment);
    void removeSegment();
    SnakeSegment tail() const;
    SnakeSegment head() const;
    void setDirection(const SnakeDirection direction);
    SnakeSegment nextHead();

private:
    std::queue<SnakeSegment> m_segments;
    SnakeDirection m_snakeDirection;
};