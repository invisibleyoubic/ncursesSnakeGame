#pragma once


class Symbol
{
public:
    Symbol(const int x, const int y, const char symbol);

    const int x() const;
    const int y() const;
    const char symbol() const;

protected:
    int m_x;
    int m_y;
    char m_symbol;
};

class Apple : public Symbol
{
public:
    Apple(const int x, const int y);
};

class Floor : public Symbol
{
public:
    Floor(const int x, const int y);
};

class SnakeSegment : public Symbol
{
public:
    SnakeSegment(const int x, const int y);
};