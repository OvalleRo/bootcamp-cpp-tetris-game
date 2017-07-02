#pragma once
#include "Tetrimino.h"
class StaticTetrimino :
  public Tetrimino
{
public:
  StaticTetrimino(TetriminoShape s, unsigned short * map, Tetrimino::Color c) : Tetrimino(s, map, c) {};
  ~StaticTetrimino();

  unsigned short* rotate() { return this->map; };
};

