#include "TetriminoPosition.h"

TetriminoPosition::TetriminoPosition()
{
  blocksPositions.resize(Tetrimino::MAP_LENGTH);
}

TetriminoPosition::~TetriminoPosition()
{
}

void TetriminoPosition::add(unsigned short order, Board::Coordinates coord)
{
  if (order < blocksPositions.size()) {
    blocksPositions[order] = coord;
  }
}

Board::Coordinates TetriminoPosition::getCoordinateAt(unsigned short position)
{
  if (position < blocksPositions.size()) {
    return blocksPositions[position];
  }
  return blocksPositions.front();
}

bool TetriminoPosition::isTetriminoCoordinate(Board::Coordinates coord)
{
  if (std::count(blocksPositions.begin(), blocksPositions.end(), coord) == 0) {
    return false;

  }
  return true;
  
}
