#pragma once
#include "Board.h"
#include "TetriminoPosition.h"
#include "Tetrimino.h"

class TetriminoMover
{
public:
  enum MovementDirection {
    DOWN,
    LEFT,
    RIGHT,
    UP
  };

private:
  Board * board;
  TetriminoPosition currentTetriminoPosition;
  Board::Coordinates pivot; //For the rotation
  Tetrimino * currentTetrimino;

public:
  TetriminoMover() {};
  TetriminoMover(Board &board);
  ~TetriminoMover();

  bool moveTetrimino(MovementDirection dir);

  bool insertTetrimino(Tetrimino &t);

  const TetriminoPosition getCurrentPosition();

private:
  //Check collision on current position
  bool checkCollisionOnCurrentPosition();
  bool checkCollisionOnCoordinate(Board::Coordinates coord);
  bool changePositionByDeltas(short x, short y);
  bool rotate();
  //Sets the position to the default
  // and the currentTetrimino pointer to nothing
  void resetMover();
  bool insertTetrimino(unsigned short initialRow, unsigned short initialCol, unsigned short * tetriminoMap);
  void changeRotationPivot();

};

