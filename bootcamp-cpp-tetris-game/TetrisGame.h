#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

#include "TetrisDrawer.h"
#include "TetriminoManager.h"
#include "TetriminoMover.h"
#include "Board.h"

class TetrisGame
{

private:
  Board * board;
  TetriminoManager mngr;
  sf::RenderWindow * window;
  Tetrimino * current, * next;
  float waitTimeMilliseconds;
  TetriminoPosition currentPosition;
  TetriminoMover mover;
  short winHeight, winWidth, level;
  TetrisDrawer * drawer;

public:
  TetrisGame();
  ~TetrisGame();

  //Start a new game of tetris, principal method (controlling I/O)
  void startGame();

private:
  //Increase level
  void nextLevel();

  //Update line status
  void updateLine();

  //Check if a line if full

  //Empty the given line, rearrenge the board accordingly

  //Update the score

  //Get the score
};

