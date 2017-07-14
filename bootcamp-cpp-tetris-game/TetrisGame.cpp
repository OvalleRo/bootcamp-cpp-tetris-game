#include "TetrisGame.h"
TetrisGame::TetrisGame()
{
  mngr = TetriminoManager();
  
  board = new Board(20, 10, Tetrimino::MAP_LENGTH, Tetrimino::BLACK);
  mover.setBoard(*board);
  winHeight = (board->getUsableRows() + 1) * TetrisDrawer::TEXTURE_WIDTH;
  winWidth = winHeight * (4.f/3.f);
  window = new sf::RenderWindow(sf::VideoMode(winWidth, winHeight), "Tetris", sf::Style::Titlebar | sf::Style::Close);
  drawer = new TetrisDrawer(*window, *board);
  lineMngr = BoardLineManager(*board);

  waitTimeMilliseconds = 2000.0f;
  level = 1;
  score = 0;

  current = nullptr;
  next = nullptr;
}

TetrisGame::~TetrisGame()
{
}

void TetrisGame::startGame()
{
  gameClock.restart();

  updateTetriminos();

  mover.insertTetrimino(*current);
  
  float elapsedMilliseconds;
  bool tetriminoChangedPosition = false;
  bool paused = false;
  bool gameOver = false;

  short clearedLines = 0, totalLines = 0;

  while (window->isOpen())
  {
    elapsedMilliseconds = gameClock.getElapsedTime().asMilliseconds();
    if (!gameOver && !paused)
    {
      if ((elapsedMilliseconds >= waitTimeMilliseconds)) {

        tetriminoChangedPosition = mover.moveTetrimino(Direction::DOWN);
        if (!tetriminoChangedPosition) {
          updateTetriminos();

          clearedLines = lineMngr.updateLines(currentPosition);
          totalLines += clearedLines;
          updateScore(clearedLines);
          tetriminoChangedPosition = mover.insertTetrimino(*current);
          if (!tetriminoChangedPosition) {
            gameOver = true;
          }
          if (totalLines >= LINES_TO_NEXT_LEVEL) {

            totalLines = 0;
            nextLevel();

          }
        }
        
        gameClock.restart();

      }
    }
    

    sf::Event event;
    while (window->pollEvent(event)) {
      if (event.type == sf::Event::Closed || 
        sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
      {
        window->close();
      }
      if (!gameOver && !paused)
      {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
        {
          tetriminoChangedPosition = mover.moveTetrimino(Direction::DOWN);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        {
          tetriminoChangedPosition = mover.moveTetrimino(Direction::LEFT);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        {
          tetriminoChangedPosition = mover.moveTetrimino(Direction::RIGHT);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
        {
          tetriminoChangedPosition = mover.moveTetrimino(Direction::UP);
        }

      }
      if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
       {
       //Doesn't work quite well--
       paused = !paused;
       }
      
    }

    if (tetriminoChangedPosition) {
      tetriminoChangedPosition = false;
      currentPosition = mover.getCurrentPosition();
    }

    drawer->drawGameScreen(level, score, *next, gameOver);
  }
}

void TetrisGame::nextLevel()
{
  ++level;
  waitTimeMilliseconds *= (1.f - NEXT_LEVEL_PROPORTION);
}

void TetrisGame::updateScore(short lines)
{
  score += lines * SCORE_PER_LINE;
}


void TetrisGame::updateTetriminos()
{
  if (current == nullptr) {

    current = mngr.getRandom();
  }
  else
  {
    current = next;

  }
  do
  {
    next = mngr.getRandom();
  } while (current == next);
}

