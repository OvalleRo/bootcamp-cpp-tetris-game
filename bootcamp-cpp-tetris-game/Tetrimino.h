#include <iostream>
#pragma once

class Tetrimino {
public:
   enum Shapes {
    SQUARE,
    T,
    S,
    INVERSE_S,
    L,
    INVERSE_L,
    LINE
  };
  /*
  The map is intended to act as a 2D representation of the Tetromino.
  MAP_LENGTH defines the width/height of the square.
  */
  static const int MAP_LENGTH = 4;

protected:

  Shapes name;
  unsigned char map[MAP_LENGTH*MAP_LENGTH];

public:

  Tetrimino();
  ~Tetrimino();

  Shapes getShape();
  unsigned char* getMap();
  virtual unsigned char* rotate() =0;
  
  //For debuging purposes only
  void print();


};