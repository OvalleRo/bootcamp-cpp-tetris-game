#include "TetriminoPosition.h"

TetriminoPosition::TetriminoPosition()
{
  blocksPositions.resize(Tetrimino::MAP_LENGTH);
}

TetriminoPosition::~TetriminoPosition()
{
}

void TetriminoPosition::add(unsigned short order, BoardCoordinates coord)
{
  if (order < blocksPositions.size()) {
    blocksPositions[order] = coord;
  }
}

BoardCoordinates TetriminoPosition::getCoordinateAt(unsigned short position)
{
  if (position < blocksPositions.size()) {
    return blocksPositions[position];
  }
  return blocksPositions.front();
}

unsigned short TetriminoPosition::getNoOfCoordinates()
{
  return blocksPositions.size();
}

bool TetriminoPosition::isTetriminoCoordinate(BoardCoordinates coord)
{
  if (std::count(blocksPositions.begin(), blocksPositions.end(), coord) == 0) {
    return false;

  }
  return true;
  
}
