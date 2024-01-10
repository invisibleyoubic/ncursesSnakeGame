#pragma once

#include "board.hpp"
#include "snake.hpp"
#include "scoreboard.hpp"


class Game
{
public:
    Game(const int boardHeight, const int boardWidth);
    ~Game();

    void processInput();
    void updateState();
    void redraw();
    const bool isGameOver() const;
    const int score() const;

private:
    Board* m_board;
    Snake* m_snake;
    Apple* m_apple;
    Scoreboard* m_scoreboard;
    bool m_isGameOver;
    int m_score;
};
