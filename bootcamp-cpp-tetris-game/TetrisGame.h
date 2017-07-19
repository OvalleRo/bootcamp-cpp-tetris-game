#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

#include "TetrisDrawer.h"
#include "TetriminoManager.h"
#include "TetriminoMover.h"
#include "Board.h"
#include "BoardLineManager.h"
#include "TetrisSoundPlayer.h"

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
  TetrisSoundPlayer soundPlayer;
  bool gameResourcesLoadedCorrectly; //Both graphics and sounds..

  const short LINES_TO_NEXT_LEVEL = 10,
              SCORE_PER_LINE = 10;
  const float TIME_DECREASE_PROPORTION = 0.1f,
              WINDOW_ASPECT_RATIO = 4.f/3.f;

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
  bool resourcesLoadedCorrectly();
};

