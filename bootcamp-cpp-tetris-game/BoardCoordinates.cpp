#include "BoardCoordinates.h"



BoardCoordinates::BoardCoordinates()
{
}

BoardCoordinates::BoardCoordinates(short x, short y): x(x), y(y)
{
}


BoardCoordinates::~BoardCoordinates()
{
}

short BoardCoordinates::getX()
{
  return x;
}

short BoardCoordinates::getY()
{
  return y;
}

bool BoardCoordinates::operator==(const BoardCoordinates& rhs) {

  if (x == rhs.x && y == rhs.y) {
    return true;
  }
  return false;

}

void BoardCoordinates::setX(short x)
{
  this->x = x;
}

void BoardCoordinates::setY(short y)
{
  this->y = y;
}

//Returns the corresponding coordinate in the given direction
BoardCoordinates BoardCoordinates::getCordinateInDirection(Direction dir)
{
  BoardCoordinates c = *this;
  switch (dir)
  {
  case UP:
    c.x -= DIR_MOVEMENT_DELTA;
    break;
  case DOWN:
    c.x += DIR_MOVEMENT_DELTA;
    break;
  case LEFT:
    c.y -= DIR_MOVEMENT_DELTA;
    break;
  case RIGHT:
    c.y += DIR_MOVEMENT_DELTA;
    break;
  default:
    break;
  }
  return c;
}
