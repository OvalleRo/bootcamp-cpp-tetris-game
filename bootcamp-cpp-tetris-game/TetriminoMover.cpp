#include "TetriminoMover.h"

TetriminoMover::TetriminoMover(Board & board)
{
  this->board = &board;
  resetMover();
}

TetriminoMover::~TetriminoMover()
{

}

bool TetriminoMover::moveTetrimino(MovementDirection dir)
{
  if (currentTetrimino == nullptr) {
    //There is no tetrimino to move
    return false;
  }
  short rowDelta, colDelta;
  switch (dir)
  {
  case DOWN:
    rowDelta = 1;
    colDelta = 0;
    return changePositionByDeltas(rowDelta, colDelta);
    break;
  case LEFT:
    rowDelta = 0;
    colDelta = -1;
    return changePositionByDeltas(rowDelta, colDelta);
    break;
  case RIGHT:
    rowDelta = 0;
    colDelta = 1;
    return changePositionByDeltas(rowDelta, colDelta);
    break;
  case UP:
    return rotate();
  default:
    return false;
    break;
  }

}

bool TetriminoMover::insertTetrimino(Tetrimino & t)
{
  resetMover();

  unsigned short * tetriminoMap = t.getMap();

  currentTetrimino = &t;
  
  unsigned short initialCol = (board->getColumns() / 2) - (Tetrimino::MAP_LENGTH / 2);

  if (!insertTetrimino(0, initialCol, tetriminoMap)) {
    resetMover();
    return false;
  }

  for (int i = 0; i < Tetrimino::MAP_LENGTH; i++)
  {
    board->setValue(currentTetriminoPosition.getCoordinateAt(i), currentTetrimino->getColor());
  }
  changeRotationPivot();

  return true;
}

bool TetriminoMover::checkCollisionOnCurrentPosition()
{
  return false;
}

bool TetriminoMover::checkCollisionOnCoordinate(Board::Coordinates coord)
{
  if (board->getValue(coord) == board->getBackgroundValue()) {
    return false;
  }
  //It shouldn't collide if the next position is partially ocupied by the current one
  if (currentTetriminoPosition.isTetriminoCoordinate(coord))
  {
    return false;
  }
  return true;
}

bool TetriminoMover::changePositionByDeltas(short rowDelta, short colDelta)
{
  /*
  Given the row and col deltas, the tetromino is moved in the board
  as long as it moves to an empty space (background block or value).
  */

  Board::Coordinates current;
  TetriminoPosition next;
  for (int i = 0; i < Tetrimino::MAP_LENGTH; i++)
  {
    current = currentTetriminoPosition.getCoordinateAt(i);
    current.x += rowDelta;
    current.y += colDelta;
    if (!checkCollisionOnCoordinate(current))
    {
      next.add(i, current);
    }
    else {
      return false;
    }
  }
  for (int i = 0; i < Tetrimino::MAP_LENGTH; i++)
  {
    //Clears last position (as long as it's not part of the next), and sets the corresponding
    //values in the next coordinates
    if (!next.isTetriminoCoordinate(currentTetriminoPosition.getCoordinateAt(i)))
    {
      board->setValue(currentTetriminoPosition.getCoordinateAt(i), board->getBackgroundValue());
    }
    board->setValue(next.getCoordinateAt(i), currentTetrimino->getColor());
  }
  currentTetriminoPosition = next;
  changeRotationPivot();
  return true;
}

bool TetriminoMover::rotate()
{
  unsigned short * rotatedMap = currentTetrimino->rotate();
  unsigned short initialRow, initialCol;
  TetriminoPosition lastPosition = currentTetriminoPosition;
  initialRow = pivot.x;
  initialCol = pivot.y;
  if (insertTetrimino(initialRow,initialCol, rotatedMap))
  {
    currentTetrimino->setMap(rotatedMap);
    for (int i = 0; i < Tetrimino::MAP_LENGTH; i++)
    {
      //Clears last position (as long as it's not part of the next), and sets the corresponding
      //values in the next coordinates
      if (!currentTetriminoPosition.isTetriminoCoordinate(lastPosition.getCoordinateAt(i)))
      {
        board->setValue(lastPosition.getCoordinateAt(i), board->getBackgroundValue());
      }
      board->setValue(currentTetriminoPosition.getCoordinateAt(i), currentTetrimino->getColor());
    }
    return true;
  }
  else {
    currentTetriminoPosition = lastPosition;
    return false;
  }
}

void TetriminoMover::resetMover()
{
  currentTetrimino = nullptr;
  currentTetriminoPosition = TetriminoPosition();
  pivot.x = 0;
  pivot.y = 0;
  
}

bool TetriminoMover::insertTetrimino(unsigned short initialRow, unsigned short initialCol, unsigned short * tetriminoMap)
{
  unsigned short index = 0;

  Board::Coordinates coord;
  for (int row = 0; row < Tetrimino::MAP_LENGTH; row++)
  {
    for (int col = 0; col < Tetrimino::MAP_LENGTH; col++)
    {
      short tetriminoMapPosition, boardMapPosition;

      coord.x = row + initialRow;
      coord.y = col + initialCol;

      tetriminoMapPosition = (Tetrimino::MAP_LENGTH * row) + col;

      if (tetriminoMap[tetriminoMapPosition] != board->getBackgroundValue()) {
        if (!checkCollisionOnCoordinate(coord)) {
          currentTetriminoPosition.add(index, coord);
          ++index;
        }
        else {
          return false;
        }
      }

    }
  }
  return true;
}

void TetriminoMover::changeRotationPivot()
{
  int x = board->getRows(), y = board->getColumns();
  for (int i = 0; i < Tetrimino::MAP_LENGTH; i++)
  {
    Board::Coordinates coord = currentTetriminoPosition.getCoordinateAt(i);
    if (coord.x < x) {
      x = coord.x;
    }
    if (coord.y < y) {
      y = coord.y;
    }
  }
  pivot.x = x;
  pivot.y = y;
}
