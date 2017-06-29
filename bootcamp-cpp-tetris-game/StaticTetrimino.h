#pragma once
#include "Tetrimino.h"
class StaticTetrimino :
  public Tetrimino
{
public:
  StaticTetrimino();
  ~StaticTetrimino();

  unsigned char* rotate() { return this->map; };
};

