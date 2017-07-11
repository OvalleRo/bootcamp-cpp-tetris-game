#pragma once
#include "Board.h"
#include "Tetrimino.h"
#include <algorithm>
class TetriminoPosition {
private:
  std::vector<Board::Coordinates> blocksPositions;

public:
  TetriminoPosition();
  ~TetriminoPosition();
  void add(unsigned short order, Board::Coordinates coord);
  Board::Coordinates getCoordinateAt(unsigned short position);
  unsigned short getNoOfCoordinates();
  bool isTetriminoCoordinate(Board::Coordinates coord);
};