#include "scoreboard.hpp"


Scoreboard::Scoreboard()
    : m_scoreboardWindow(nullptr)
{}

Scoreboard::Scoreboard(const int width, const int height)
{
    int xMax = 0;
    int yMax = 0;
    getmaxyx(stdscr, yMax, xMax);
    
    m_scoreboardWindow = newwin(1, width, (yMax / 2) - (height / 2) - 1, (xMax / 2) - (width / 2));

    clear();
    mvwprintw(m_scoreboardWindow, 0, 0, "Score:");
    updateScore(0);
    refresh();
}

void Scoreboard::clear()
{
    wclear(m_scoreboardWindow);
}

void Scoreboard::refresh()
{
    wrefresh(m_scoreboardWindow);
}

void Scoreboard::updateScore(const int score)
{
    mvwprintw(m_scoreboardWindow, 0, m_scoreboardWindow->_maxx - 10, "%11lu", score);
}