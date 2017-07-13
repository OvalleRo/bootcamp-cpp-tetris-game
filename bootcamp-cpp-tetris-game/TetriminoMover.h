#pragma once
#include "Board.h"
#include "TetriminoPosition.h"
#include "Tetrimino.h"

class TetriminoMover
{

private:
  Board * board;
  TetriminoPosition currentTetriminoPosition;
  BoardCoordinates pivot; //For the rotation
  Tetrimino * currentTetrimino;

public:
  TetriminoMover();
  TetriminoMover(Board &board);
  ~TetriminoMover();

  bool moveTetrimino(Direction dir);

  bool insertTetrimino(Tetrimino &t);

  const TetriminoPosition getCurrentPosition();

  void setBoard(Board & board);

private:

  bool checkCollisionOnCoordinate(BoardCoordinates coord);
  bool changePosition(Direction dir);
  bool rotate();
  //Sets the position to the default
  // and the currentTetrimino pointer to nothing
  void resetMover();
  bool insertTetrimino(unsigned short initialRow, unsigned short initialCol, unsigned short * tetriminoMap);
  void changeRotationPivot();

};

