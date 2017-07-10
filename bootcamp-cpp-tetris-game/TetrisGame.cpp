#include "TetrisGame.h"
TetrisGame::TetrisGame()
{
  winHeight = 900;
  winWidth = 1200;
  window = new sf::RenderWindow(sf::VideoMode(winWidth, winHeight), "Tetris", sf::Style::Titlebar | sf::Style::Close);
  mngr = TetriminoManager();
  
  board = new Board(20, 10, Tetrimino::MAP_LENGTH, Tetrimino::BLACK);
  mover = TetriminoMover(*board);
  drawer = new TetrisDrawer(*window, *board);

  waitTimeMilliseconds = 2000;
  level = 1;
}

TetrisGame::~TetrisGame()
{
}

void TetrisGame::startGame()
{
  current = mngr.getRandom();
  next = mngr.getRandom();
  mover.insertTetrimino(*current);

  sf::Clock gameClock;
  
  float elapsedMilliseconds;
  bool tetriminoChangedPosition = false;
  bool paused = false;

  while (window->isOpen())
  {
    elapsedMilliseconds = gameClock.getElapsedTime().asMilliseconds();

    if (elapsedMilliseconds >= waitTimeMilliseconds &&
        !paused) {
      
      tetriminoChangedPosition = mover.moveTetrimino(TetriminoMover::DOWN);
      
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

    drawer->draw();
  }
}

