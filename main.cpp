#include <iostream>
#include <ncurses.h>
#include "game.hpp"


#define BOARD_UNIT 20
#define BOARD_HEIGHT BOARD_UNIT
#define BOARD_WIDTH BOARD_UNIT * 2.5


int main (int argc, char** argv)
{
    initscr();
    refresh();
    curs_set(0);
    noecho();

    Game game(BOARD_HEIGHT, BOARD_WIDTH);
    while(!game.isGameOver())
    {
        game.processInput();
        game.updateState();
        game.redraw();
    }

    endwin();

    std::cout << "Your score: " << game.score() << std::endl;

    return 0;
}