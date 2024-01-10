#pragma once

#include <ncurses.h>
#include <utility>
#include "symbol.hpp"


class Board
{
public:
    Board() = default;
    Board(const int height, const int width);
    
    void init();
    void addBorders();
    void clear();
    void refresh();
    void addSymbol(const int x, const int y, const char symbol);
    void addSymbol(const Symbol& symbol);
    void addSymbol(const Symbol* symbol);
    const int getInput();
    const std::pair<int, int> emptyCoordinates() const;
    bool isEmptyCoodrinate(const int x, const int y) const;

private:
    WINDOW* m_boardWindow = nullptr;
    int m_height;
    int m_width;
};