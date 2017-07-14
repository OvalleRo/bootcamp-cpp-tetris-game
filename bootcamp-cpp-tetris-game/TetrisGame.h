#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

#include "TetrisDrawer.h"
#include "TetriminoManager.h"
#include "TetriminoMover.h"
#include "Board.h"
#include "BoardLineManager.h"

class TetrisGame
{

private:
  Board * board;
  BoardLineManager lineMngr;
  TetriminoManager mngr;
  sf::RenderWindow * window;
  Tetrimino * current, * next;
  float waitTimeMilliseconds;
  TetriminoPosition currentPosition;
  TetriminoMover mover;
  short winHeight, winWidth, level;
  int score;
  TetrisDrawer * drawer;
  sf::Clock gameClock;

  const short LINES_TO_NEXT_LEVEL = 10,
              SCORE_PER_LINE = 10;
  const float NEXT_LEVEL_PROPORTION = 0.1f;

  //Increase level
  void nextLevel();
  //Update the score
  void updateScore(short lines);
  void nextTetriminos();

public:


  TetrisGame();
  ~TetrisGame();

  //Start a new game of tetris, principal method (controlling I/O)
  void startGame();
};

