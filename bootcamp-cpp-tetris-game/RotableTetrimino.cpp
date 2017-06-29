#include "RotableTetrimino.h"
#include <array>


RotableTetrimino::RotableTetrimino(Shapes shapeName)
{
  switch (shapeName)
  {
  case Tetrimino::SQUARE:
    //TODO: Throw exception
    break;
  case Tetrimino::T:
  {name = Shapes::T;
    unsigned char t[] = { 0, 0, 0, 0,
                              0, 0, 0, 0,
                              1, 1, 1, 0,
                              0, 1, 0, 0 };
    std::copy(t, t + (MAP_LENGTH*MAP_LENGTH), this->map);
    break;}
    
  case Tetrimino::S:
  {name = Shapes::S;
  unsigned char s[] = { 0, 0, 0, 0,
                            0, 0, 0, 0,
                            0, 1, 1, 0,
                            1, 1, 0, 0 };
  std::copy(s, s + (MAP_LENGTH*MAP_LENGTH), this->map);
  break; }
  case Tetrimino::INVERSE_S:
  {name = Shapes::INVERSE_S;
  unsigned char is[] = { 0, 0, 0, 0,
                              0, 0, 0, 0,
                              1, 1, 0, 0,
                              0, 1, 1, 0 };
  std::copy(is, is + (MAP_LENGTH*MAP_LENGTH), this->map);
  break; }
  case Tetrimino::L:
  {name = Shapes::L;
  unsigned char l[] = { 0, 0, 0, 0,
                              1, 0, 0, 0,
                              1, 0, 0, 0,
                              1, 1, 0, 0 };
  std::copy(l, l + (MAP_LENGTH*MAP_LENGTH), this->map);
  break; }
  case Tetrimino::INVERSE_L:
  { name = Shapes::INVERSE_L;
  unsigned char il[] = { 0, 0, 0, 0,
                              0, 0, 0, 1,
                              0, 0, 0, 1,
                              0, 0, 1, 1 };
  std::copy(il, il + (MAP_LENGTH*MAP_LENGTH), this->map);
  break; }
  case Tetrimino::LINE:
  { name = Shapes::LINE;
  unsigned char line[] = { 1, 0, 0, 0,
                              1, 0, 0, 0,
                              1, 0, 0, 0,
                              1, 0, 0, 0 };
  std::copy(line, line + (MAP_LENGTH*MAP_LENGTH), this->map);
  break; }
  default:
    //TODO: Throw exc
    break;
  }
}

RotableTetrimino::~RotableTetrimino()
{
}

unsigned char * RotableTetrimino::rotate()
{
  unsigned char new_map[MAP_LENGTH*MAP_LENGTH];
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
