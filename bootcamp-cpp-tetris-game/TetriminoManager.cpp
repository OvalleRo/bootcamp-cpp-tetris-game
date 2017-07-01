#include "TetriminoManager.h"
#include <stdlib.h>
#include <stdio.h>
#include <time.h>


TetriminoManager::TetriminoManager()
{
  tetriminos.resize(TetriminoShape::COUNT);

  unsigned short square[] = { 0,0,0,0,
                                  0,0,0,0,
                                  1,1,0,0,
                                  1,1,0,0 };
  tetriminos[TetriminoShape::SQUARE] = new StaticTetrimino(TetriminoShape::SQUARE, square);
  unsigned short t[] = { 0, 0, 0, 0,
                        0, 0, 0, 0,
                        1, 1, 1, 0,
                        0, 1, 0, 0 };
  tetriminos[TetriminoShape::T] = new RotableTetrimino(TetriminoShape::T, t);
  unsigned short s[] = { 0, 0, 0, 0,
                         0, 0, 0, 0,
                         0, 1, 1, 0,
                         1, 1, 0, 0 };
  tetriminos[TetriminoShape::S] = new RotableTetrimino(TetriminoShape::S, s);
  unsigned short is[] = { 0, 0, 0, 0,
                          0, 0, 0, 0,
                          1, 1, 0, 0,
                          0, 1, 1, 0 };
  tetriminos[TetriminoShape::INVERSE_S] = new RotableTetrimino(TetriminoShape::INVERSE_S, is);
  unsigned short l[] = { 0, 0, 0, 0,
                      1, 0, 0, 0,
                      1, 0, 0, 0,
                      1, 1, 0, 0 };
  tetriminos[TetriminoShape::L] = new RotableTetrimino(TetriminoShape::L, l);
  unsigned short il[] = { 0, 0, 0, 0,
                          0, 0, 0, 1,
                          0, 0, 0, 1,
                          0, 0, 1, 1 };
  tetriminos[TetriminoShape::INVERSE_L] = new RotableTetrimino(TetriminoShape::INVERSE_L, il);
  unsigned short line[] = { 1, 0, 0, 0,
                            1, 0, 0, 0,
                            1, 0, 0, 0,
                            1, 0, 0, 0 };
  tetriminos[TetriminoShape::LINE] = new RotableTetrimino(TetriminoShape::LINE, line);

  //delete[] &square, &t, &s, &is, &l, &il, &line;


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
