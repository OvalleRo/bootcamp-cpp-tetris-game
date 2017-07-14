#pragma once
#include "Board.h"
#include "TetriminoPosition.h"
#include "Tetrimino.h"

class TetriminoMover
{

private:
  Board * board;
  // The position (colection of coordinates) of the blocks that make the Tetrimino
  // falling in the board
  TetriminoPosition currentTetriminoPosition;
  BoardCoordinates pivot; //For the rotation
  // The tetrimino falling in the board
  Tetrimino * currentTetrimino;

  bool checkCollisionOnCoordinate(BoardCoordinates coord);
  bool changeCurrentTetriminoPosition(Direction dir);
  bool rotateTetriminoInBoard();
  //Sets the position to the default
  // and the currentTetrimino pointer to nothing
  void resetMover();
  bool putMapInCoordinate(BoardCoordinates initialCoord, unsigned short * tetriminoMap);
  void changeRotationPivot();
  void changeBlocksToCurrentPosition(TetriminoPosition lastPosition);

public:
  TetriminoMover();
  TetriminoMover(Board &board);
  ~TetriminoMover();

  bool moveTetrimino(Direction dir);

  bool insertTetrimino(Tetrimino &t);

  const TetriminoPosition getCurrentPosition();

  void setBoard(Board & board);
};

