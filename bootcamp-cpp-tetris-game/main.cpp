#include <SFML/Graphics.hpp>

#include "TetriminoManager.h"

int main()
{
  Tetrimino *t;
  TetriminoManager mngr{};

  t = mngr.getByName(TetriminoShape::T);

  t->print();

  t->rotate();
  t->print();


  delete t;

  t = mngr.getRandom();
  t->print();

  t->rotate();
  t->print();


  return 0;
}