#include <iostream>
#include "TetriminoShape.h"
#pragma once

class Tetrimino {
public:


  /*
  The map is intended to act as a 2D representation of the Tetromino.
  MAP_LENGTH defines the width/height of the square.
  */
  static const int MAP_LENGTH = 4;

protected:

  TetriminoShape name;
  unsigned short map[MAP_LENGTH*MAP_LENGTH];

public:

  Tetrimino() {};
  Tetrimino(TetriminoShape s, unsigned short * map);
  ~Tetrimino();

  TetriminoShape getShape();
  unsigned short* getMap();
  virtual unsigned short* rotate() =0;
  
  //For debuging purposes only
  void print();


};