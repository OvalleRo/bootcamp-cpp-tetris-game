#pragma once
#include <iostream>
#include <array>
#include <vector>
#include <tuple>
#include "RotableTetrimino.h"
#include "StaticTetrimino.h"

//For the storage of the Tetrominos
class TetriminoManager
{

private:
  std::vector<Tetrimino*> tetriminos;

public:

  TetriminoManager();
  ~TetriminoManager();

  //Get a random Tetromino's reference
  Tetrimino * getRandom();
  //Get the corresponding Tetromino ref., if exists
  Tetrimino * getByName(const TetriminoShape s);

};

