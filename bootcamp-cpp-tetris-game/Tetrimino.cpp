#include <stdlib.h>
#include <array>
#include "Tetrimino.h"
#include <stdio.h>
#include <time.h>

//The map should have MAP_LENGTH > 0 values and (MAP_LENGTH)2 - MAP_LENGHT zeroes.
Tetrimino::Tetrimino(TetriminoShape s, unsigned short * map, Tetrimino::Color c)
{
  this->name = s;
  std::copy(map, map + (MAP_LENGTH*MAP_LENGTH), this->map);

  this->c = c;
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

void Tetrimino::setMap(unsigned short * newMap)
{
  std::copy(newMap, newMap + (MAP_LENGTH*MAP_LENGTH), this->map);
}

Tetrimino::Color Tetrimino::getColor()
{
  return c;
}

//For debbuging purposes
void Tetrimino::print()
{
  int pos;
  for (int i = 0; i < MAP_LENGTH; i++)
  {
    for (int j = 0; j < MAP_LENGTH; j++)
    {
      pos = (MAP_LENGTH * i) + j;
      std::cout << " " << this->map[pos];
    }
    std::cout << std::endl;
  }
  std::cout << std::endl;
}

