#pragma once
#include "Tetrimino.h"
class RotableTetrimino :
  public Tetrimino
{
public:
  RotableTetrimino(TetriminoShape s, unsigned short * map) : Tetrimino(s, map) {};
  ~RotableTetrimino() {};

  unsigned short* rotate();

};

