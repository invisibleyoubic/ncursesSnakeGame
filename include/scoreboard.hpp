#pragma once 

#include <ncurses.h>


class Scoreboard
{
public:
    Scoreboard();
    Scoreboard(const int width, const int height);
    void clear();
    void refresh();
    void updateScore(const int score);

private:
    WINDOW* m_scoreboardWindow;
};