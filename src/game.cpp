#include <time.h>
#include <stdlib.h>

#include "game.hpp"


Game::Game(const int boardHeight, const int boardWidth)
    : m_board(new Board(boardHeight, boardWidth))
    , m_snake(new Snake())
    , m_scoreboard(new Scoreboard(boardWidth, boardHeight))
    , m_isGameOver(false)
    , m_score(0)
{
    m_board->init();
    srand(time(nullptr));
    m_board->addSymbol(m_snake->head());
    
    for (int iter = 0; iter != 3; iter++)
    {
        SnakeSegment segment = m_snake->nextHead();
        m_board->addSymbol(segment);
        m_snake->addSegment(segment);
    }

    m_snake->setDirection(SnakeDirection::Right);

    const std::pair<int, int> coordinates = m_board->emptyCoordinates();
    m_apple = new Apple(coordinates.first, coordinates.second);
    m_board->addSymbol(m_apple);
}

Game::~Game()
{
    delete m_apple;
    delete m_board;
    delete m_scoreboard;
    delete m_snake;
}

void Game::processInput()
{
    const int key = m_board->getInput();

    switch (key)
    {
    case 'w':
        m_snake->setDirection(SnakeDirection::Up);
        break;
    case 's':
        m_snake->setDirection(SnakeDirection::Down);
        break;
    case 'd':
        m_snake->setDirection(SnakeDirection::Right);
        break;
    case 'a':
        m_snake->setDirection(SnakeDirection::Left);
        break;
    case 'p':
        while (m_board->getInput() != 'p')
            ;
        break;
    default:
        break;
    }
}

void Game::updateState()
{
    if (m_apple == nullptr)
    {
        const std::pair<int, int> coordinates = m_board->emptyCoordinates();
        m_apple = new Apple(coordinates.first, coordinates.second);
        m_board->addSymbol(m_apple);
    }

    SnakeSegment nextSnakeHead = m_snake->nextHead();
    if (m_board->isEmptyCoodrinate(nextSnakeHead.x(), nextSnakeHead.y()))
    {
        SnakeSegment tail = m_snake->tail();
        m_board->addSymbol(Floor(tail.x(), tail.y()));
        m_snake->removeSegment();
        
        m_snake->addSegment(nextSnakeHead);
        m_board->addSymbol(nextSnakeHead);
        return;
    }

    if (m_apple->x() == nextSnakeHead.x() && m_apple->y() == nextSnakeHead.y())
    {
        m_snake->addSegment(nextSnakeHead);
        m_board->addSymbol(SnakeSegment(m_apple->x(), m_apple->y()));
        m_apple = nullptr;
        m_score++;
        m_scoreboard->updateScore(m_score);
        return;
    }

    m_isGameOver = true;
}

void Game::redraw()
{
    m_board->refresh();
    m_scoreboard->refresh();
}

const bool Game::isGameOver() const
{
    return m_isGameOver;
}

const int Game::score() const
{
    return m_score;
}