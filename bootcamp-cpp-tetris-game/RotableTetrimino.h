#pragma once
#include "Tetrimino.h"
class RotableTetrimino :
  public Tetrimino
{
public:
  RotableTetrimino(TetriminoShape s, unsigned short * map, Tetrimino::Color c) : Tetrimino(s, map, c) {};
  ~RotableTetrimino() {};

  unsigned short* rotate();

};

