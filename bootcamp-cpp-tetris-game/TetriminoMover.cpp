#include "TetriminoMover.h"

TetriminoMover::TetriminoMover()
{
  resetMover();
}

TetriminoMover::TetriminoMover(Board & board)
{
  this->board = &board;
  resetMover();
}

TetriminoMover::~TetriminoMover()
{

}

bool TetriminoMover::moveTetrimino(Direction dir)
{
  if (currentTetrimino == nullptr) {
    //There is no tetrimino to move
    return false;
  }

  switch (dir)
  {
  case DOWN:
  case LEFT:
  case RIGHT:
    return changeCurrentTetriminoPosition(dir);
    break;
  case UP:
    return rotateTetriminoInBoard();
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

  if (!putMapInCoordinate(BoardCoordinates(0, initialCol), tetriminoMap)) {
    resetMover();
    return false;
  }

  changeBlocksToCurrentPosition(currentTetriminoPosition);
  changeRotationPivot();

  return true;
}

const TetriminoPosition TetriminoMover::getCurrentPosition()
{
  return currentTetriminoPosition;
}

void TetriminoMover::setBoard(Board & board)
{
  this->board = &board;
}

bool TetriminoMover::checkCollisionOnCoordinate(BoardCoordinates coord)
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

bool TetriminoMover::changeCurrentTetriminoPosition(Direction dir)
{
  TetriminoPosition next, lastPosition(currentTetriminoPosition);
  for (int i = 0; i < Tetrimino::MAP_LENGTH; i++)
  {
    BoardCoordinates coord = currentTetriminoPosition.getCoordinateAt(i)
                                                        .getCordinateInDirection(dir);

    if (!checkCollisionOnCoordinate(coord))
    {
      next.add(i, coord);
    }
    else {
      return false;
    }
  }
  currentTetriminoPosition = next;
  changeBlocksToCurrentPosition(lastPosition);
  changeRotationPivot();
  return true;
}

bool TetriminoMover::rotateTetriminoInBoard()
{
  unsigned short * rotatedMap = currentTetrimino->rotate();
  TetriminoPosition lastPosition(currentTetriminoPosition);
  if (putMapInCoordinate(pivot, rotatedMap))
  {
    currentTetrimino->setMap(rotatedMap);
    changeBlocksToCurrentPosition(lastPosition);
    return true;
  }
  else {
    return false;
  }
}

void TetriminoMover::resetMover()
{
  currentTetrimino = nullptr;
  currentTetriminoPosition = TetriminoPosition();
  pivot.setX(0);
  pivot.setY(0);
  
}

// Changes the position of the tetromino in the map, if the change is allowed
// (does not collide)
bool TetriminoMover::putMapInCoordinate(BoardCoordinates initialCoord, unsigned short * tetriminoMap)
{
  unsigned short index = 0;
  TetriminoPosition nextPosition;

  BoardCoordinates coord;
  for (int row = 0; row < Tetrimino::MAP_LENGTH; row++)
  {
    for (int col = 0; col < Tetrimino::MAP_LENGTH; col++)
    {
      short tetriminoMapPosition, boardMapPosition;

      coord.setX(row + initialCoord.getX());
      coord.setY(col + initialCoord.getY());

      tetriminoMapPosition = (Tetrimino::MAP_LENGTH * row) + col;

      if (tetriminoMap[tetriminoMapPosition] != board->getBackgroundValue()) {
        if (!checkCollisionOnCoordinate(coord)) {
          nextPosition.add(index, coord);
          ++index;
        }
        else {
          return false;
        }
      }

    }
  }
  currentTetriminoPosition = nextPosition;
  return true;
}

// The rotation pivot is the coordinate arround which the rotated tetrimino is 
// drawn in the board.
void TetriminoMover::changeRotationPivot()
{
  int x = board->getRows(), y = board->getColumns();
  for (int i = 0; i < Tetrimino::MAP_LENGTH; i++)
  {
    BoardCoordinates coord = currentTetriminoPosition.getCoordinateAt(i);
    int coordX = coord.getX();
    int coordY = coord.getY();
    if (coordX < x) {
      x = coordX;
    }
    if (coordY < y) {
      y = coordY;
    }
  }
  pivot.setX(x);
  pivot.setY(y);
}

// 'Moves' the blocks of the falling tetrimino to the current position
void TetriminoMover::changeBlocksToCurrentPosition(TetriminoPosition lastPosition)
{
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
}
