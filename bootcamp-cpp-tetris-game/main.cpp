#include <SFML/Graphics.hpp>
#include "StaticTetrimino.h"
#include "RotableTetrimino.h"

int main()
{
  Tetrimino *t;
  t = new RotableTetrimino(Tetrimino::T);
  t->print();

  t->rotate();
  t->print();

  delete t;

  return 0;
}