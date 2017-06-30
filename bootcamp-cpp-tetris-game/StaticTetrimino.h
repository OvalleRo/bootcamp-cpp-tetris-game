#pragma once
#include "Tetrimino.h"
class StaticTetrimino :
  public Tetrimino
{
public:
  StaticTetrimino(TetriminoShape s, unsigned short * map) : Tetrimino(s, map) {};
  ~StaticTetrimino();

  unsigned short* rotate() { return this->map; };
};

