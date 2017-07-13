#pragma once
#include "Board.h"
#include "Tetrimino.h"
#include <algorithm>
class TetriminoPosition {
private:
  std::vector<BoardCoordinates> blocksPositions;

public:
  TetriminoPosition();
  ~TetriminoPosition();
  void add(unsigned short order, BoardCoordinates coord);
  BoardCoordinates getCoordinateAt(unsigned short position);
  unsigned short getNoOfCoordinates();
  bool isTetriminoCoordinate(BoardCoordinates coord);
};