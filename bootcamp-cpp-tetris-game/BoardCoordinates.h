#pragma once
#include "Direction.h"
class BoardCoordinates
{
private:
  short x, y;
  static const short DIR_MOVEMENT_DELTA = 1;
  
public:
  BoardCoordinates();
  BoardCoordinates(short x, short y);
  ~BoardCoordinates();

  short getX();
  short getY();
  bool operator==(const BoardCoordinates& rhs);

  void setX(short x);
  void setY(short y);

  // Get the coordinate of the position in the given direction.
  BoardCoordinates getCordinateInDirection(Direction dir);
};

