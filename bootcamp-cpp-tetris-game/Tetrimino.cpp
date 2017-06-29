#include <stdlib.h>
#include <array>
#include "Tetrimino.h"


Tetrimino::Tetrimino()
{
}

Tetrimino::~Tetrimino()
{
}

Tetrimino::Shapes Tetrimino::getShape()
{
  return name;
}

unsigned char * Tetrimino::getMap()
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
}

