#include "snake.hpp"


Snake::Snake()
    : m_snakeDirection(SnakeDirection::Down)
    , m_segments()
{
    m_segments.emplace(1, 1);
}

void Snake::addSegment(const SnakeSegment segment)
{
    m_segments.push(segment);
}

void Snake::removeSegment()
{
    m_segments.pop();
}

SnakeSegment Snake::tail() const
{
    return m_segments.front();
}

SnakeSegment Snake::head() const
{
    return m_segments.back();
}

void Snake::setDirection(const SnakeDirection direction)
{
    if (direction + m_snakeDirection == 0)
        return;

    m_snakeDirection = direction;
}

SnakeSegment Snake::nextHead()
{
    SnakeSegment snakeHead = head();

    int x = snakeHead.x();
    int y = snakeHead.y();

    switch (m_snakeDirection)
    {
    case Up:
        y--;
        break;
    case Down:
        y++;
        break;
    case Left:
        x--;
        break;
    case Right:
        x++;
        break;
    default:
        break;
    }

    return SnakeSegment(x, y);
}