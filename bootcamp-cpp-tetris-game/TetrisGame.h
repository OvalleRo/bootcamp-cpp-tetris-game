#pragma once
#include "Board.h"
#include "TetriminoManager.h"
#include "TetriminoPosition.h"

#include "SFML\Graphics.hpp"

class TetrisGame
{

private:
  Board * b;
  TetriminoManager manager;
  sf::RenderWindow * window;
  Tetrimino * current, * next;
  float waitTimeMiliseconds;
  TetriminoPosition currentPosition;

public:
  TetrisGame();
  ~TetrisGame();

  //Start a new game of tetris, principal method (controlling I/O)

  //Pause the game

  //Insert tetrimino as the current one, generate next

  //Increase level

  //Move tetrimino to the left, right, down

  //Rotate tetrimino

  //Check collision

  //Update line status

  //Check if a line if full

  //Empty the given line, rearrenge the board accordingly

  //Update the score

  //Get the score
};

