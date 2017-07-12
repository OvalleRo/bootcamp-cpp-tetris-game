#include "TetrisGame.h"
TetrisGame::TetrisGame()
{
  mngr = TetriminoManager();
  
  board = new Board(20, 10, Tetrimino::MAP_LENGTH, Tetrimino::BLACK);
  mover = TetriminoMover(*board);
  winHeight = (board->getUsableRows() + 1) * TetrisDrawer::TEXTURE_WIDTH;
  winWidth = winHeight * (4.f/3.f);
  window = new sf::RenderWindow(sf::VideoMode(winWidth, winHeight), "Tetris", sf::Style::Titlebar | sf::Style::Close);
  drawer = new TetrisDrawer(*window, *board);
  lineMngr = BoardLineManager(*board);

  waitTimeMilliseconds = 2000;
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
  updateTetriminos();

  mover.insertTetrimino(*current);

  sf::Clock gameClock;
  
  float elapsedMilliseconds;
  bool tetriminoChangedPosition = false;
  bool paused = false;

  short clearedLines = 0, totalLines = 0;

  while (window->isOpen())
  {
    elapsedMilliseconds = gameClock.getElapsedTime().asMilliseconds();

    if (elapsedMilliseconds >= waitTimeMilliseconds &&
        !paused) {
      
      tetriminoChangedPosition = mover.moveTetrimino(TetriminoMover::DOWN);
      if (!tetriminoChangedPosition) {
        updateTetriminos();

        clearedLines = lineMngr.updateLines(currentPosition);
        totalLines += clearedLines;
        updateScore(clearedLines);
        tetriminoChangedPosition = mover.insertTetrimino(*current);
        if (!tetriminoChangedPosition) {
          gameOver();
        }
        if (totalLines >= LINES_TO_NEXT_LEVEL) {

          totalLines = 0;
          nextLevel();

        }
      }

      gameClock.restart();

    }

    sf::Event event;
    while (window->pollEvent(event)) {
      if (event.type == sf::Event::Closed || 
        sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
      {
        window->close();
      }
      if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
      {
        tetriminoChangedPosition = mover.moveTetrimino(TetriminoMover::DOWN);
      }
      if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
      {
        tetriminoChangedPosition = mover.moveTetrimino(TetriminoMover::LEFT);
      }
      if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
      {
        tetriminoChangedPosition = mover.moveTetrimino(TetriminoMover::RIGHT);
      }
      if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
      {
        tetriminoChangedPosition = mover.moveTetrimino(TetriminoMover::UP);
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

    drawer->draw(level, score, *next);
  }
}

void TetrisGame::nextLevel()
{
  ++level;
  waitTimeMilliseconds *= 0.85f;
}

void TetrisGame::updateScore(short lines)
{
  score += lines * SCORE_PER_LINE;
}

void TetrisGame::gameOver() {
  //Freeze screen, show score
  std::cout << "Game over" << std::endl;
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

