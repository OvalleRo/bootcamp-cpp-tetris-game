#include "RotableTetrimino.h"
#include <array>

unsigned short * RotableTetrimino::rotate()
{
  unsigned short new_map[MAP_LENGTH*MAP_LENGTH];
  int x, y, pos, new_x, new_y;
  for (x = 0; x < MAP_LENGTH; x++)
  {
    for (y = 0; y < MAP_LENGTH; y++)
    {
      new_x = 4 * (3 - y);
      new_y = x;
      pos = (4 * x) + y;
      new_map[new_x + new_y] = map[pos];
    }
  }
  std::copy(new_map, new_map + (MAP_LENGTH*MAP_LENGTH), this->map);
  return this->map;
}
