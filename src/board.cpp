#include <stdlib.h>

#include "board.hpp"


Board::Board(const int height, const int width)
    : m_height(height)
    , m_width(width)
{
    int xMax = 0;
    int yMax = 0;
    getmaxyx(stdscr, yMax, xMax);
    
    m_boardWindow = newwin(height, width, (yMax / 2) - (height / 2), (xMax / 2) - (width / 2));
}

void Board::init()
{
    clear();
    refresh();

    wtimeout(m_boardWindow, 300);
}

void Board::addBorders()
{
    box(m_boardWindow, 0, 0);
}

void Board::clear()
{
    wclear(m_boardWindow);
    addBorders();
}

void Board::refresh()
{
    wrefresh(m_boardWindow);
}

void Board::addSymbol(const int x, const int y, const char symbol)
{
    mvwaddch(m_boardWindow, y, x, symbol);
}

void Board::addSymbol(const Symbol& symbol)
{
    addSymbol(symbol.x(), symbol.y(), symbol.symbol());
}

void Board::addSymbol(const Symbol* symbol)
{
    addSymbol(symbol->x(), symbol->y(), symbol->symbol());
}

const int Board::getInput()
{
    return wgetch(m_boardWindow);
}

const std::pair<int, int> Board::emptyCoordinates() const
{
    int x = rand() % m_width;
    int y = rand() % m_height;
    while (mvwinch(m_boardWindow, y, x) != ' ')
    {
        x = rand() % m_width;
        y = rand() % m_height;
    }

    return {x, y};
}

bool Board::isEmptyCoodrinate(const int x, const int y) const
{
    return mvwinch(m_boardWindow, y, x) == ' ';
}