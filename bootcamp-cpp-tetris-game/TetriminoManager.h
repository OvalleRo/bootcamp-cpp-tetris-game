#pragma once
#include <iostream>
#include <array>
#include <vector>
#include <tuple>
#include "RotableTetrimino.h"
#include "StaticTetrimino.h"

class TetriminoManager
{

private:
  std::vector<Tetrimino*> tetriminos;

public:

  TetriminoManager();
  ~TetriminoManager();

  Tetrimino * getRandom();
  Tetrimino * getByName(const TetriminoShape s);

};

