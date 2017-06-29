#pragma once
#include "Tetrimino.h"
class RotableTetrimino :
  public Tetrimino
{
public:
  RotableTetrimino(Shapes shapeName);
  ~RotableTetrimino();

  unsigned char* rotate();

};

