#include <stdlib.h>
#include <array>
#include "Tetrimino.h"


Tetrimino::Tetrimino(TetriminoShape s, unsigned short * map)
{
  this->name = s;
  std::copy(map, map + (MAP_LENGTH*MAP_LENGTH), this->map);
}

Tetrimino::~Tetrimino()
{
}

TetriminoShape Tetrimino::getShape()
{
  return name;
}

unsigned short * Tetrimino::getMap()
{
  return map;
}

void Tetrimino::print()
{
  int pos;
  for (int i = 0; i < MAP_LENGTH; i++)
  {
    for (int j = 0; j < MAP_LENGTH; j++)
    {
      pos = (4 * i) + j;
      std::cout << " " << this->map[pos];
    }
    std::cout << std::endl;
  }
  std::cout << std::endl;
}

