#include "TetriminoManager.h"
#include <stdlib.h>
#include <stdio.h>
#include <time.h>


TetriminoManager::TetriminoManager()
{
  tetriminos.resize(TetriminoShape::COUNT);

  unsigned short square[] = { 
                             1,1,0,0,
                             1,1,0,0,
                             0,0,0,0,
                             0,0,0,0
  };
  tetriminos[TetriminoShape::SQUARE] = new StaticTetrimino(TetriminoShape::SQUARE, square, Tetrimino::BLUE);
  unsigned short t[] = { 
                        1, 1, 1, 0,
                        0, 1, 0, 0, 
                        0, 0, 0, 0,
                        0, 0, 0, 0
                        };
  tetriminos[TetriminoShape::T] = new RotableTetrimino(TetriminoShape::T, t, Tetrimino::YELLOW);
  unsigned short s[] = { 
                         0, 1, 1, 0,
                         1, 1, 0, 0,
                         0, 0, 0, 0,
                         0, 0, 0, 0
                        };
  tetriminos[TetriminoShape::S] = new RotableTetrimino(TetriminoShape::S, s, Tetrimino::GREEN);
  unsigned short is[] = { 
                          1, 1, 0, 0,
                          0, 1, 1, 0,
                          0, 0, 0, 0,
                          0, 0, 0, 0
                        };
  tetriminos[TetriminoShape::INVERSE_S] = new RotableTetrimino(TetriminoShape::INVERSE_S, is, Tetrimino::PURPLE);
  unsigned short l[] = {
                        1, 0, 0, 0,
                        1, 0, 0, 0,
                        1, 1, 0, 0,
                        0, 0, 0, 0
                        };
  tetriminos[TetriminoShape::L] = new RotableTetrimino(TetriminoShape::L, l, Tetrimino::RED);
  unsigned short il[] = { 
                          0, 1, 0, 0,
                          0, 1, 0, 0,
                          1, 1, 0, 0,
                          0, 0, 0, 0
                        };
  tetriminos[TetriminoShape::INVERSE_L] = new RotableTetrimino(TetriminoShape::INVERSE_L, il, Tetrimino::CYAN);
  unsigned short line[] = { 
                            1, 0, 0, 0,
                            1, 0, 0, 0,
                            1, 0, 0, 0,
                            1, 0, 0, 0 
                            };
  tetriminos[TetriminoShape::LINE] = new RotableTetrimino(TetriminoShape::LINE, line, Tetrimino::ORANGE);

  //Generate seed for the getRandom() method
  srand(time(NULL));
}


TetriminoManager::~TetriminoManager()
{
}

Tetrimino * TetriminoManager::getRandom()
{
  srand(time(NULL));
  int rnd = rand() % TetriminoShape::COUNT;
  return tetriminos[rnd];
}

Tetrimino * TetriminoManager::getByName(const TetriminoShape s)
{
  return tetriminos[s];
}
