#include "symbol.hpp"


Symbol::Symbol(const int x, const int y, const char symbol)
    : m_x(x)
    , m_y(y)
    , m_symbol(symbol)
{}

const int Symbol::x() const
{
    return m_x;
}

const int Symbol::y() const
{
    return m_y;
}

const char Symbol::symbol() const
{
    return m_symbol;
}

Apple::Apple(const int x, const int y)
    : Symbol(x, y, '@')
{}

Floor::Floor(const int x, const int y)
    : Symbol(x, y, ' ')
{}

SnakeSegment::SnakeSegment(const int x, const int y)
    : Symbol(x, y, '#')
{}