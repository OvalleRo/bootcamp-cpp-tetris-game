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
  enum Color
  {
    BLACK = 0, //Intended as a background color

    BLUE ,
    GREEN,
    ORANGE,
    RED,
    YELLOW

  };

protected:

  TetriminoShape name;
  unsigned short map[MAP_LENGTH*MAP_LENGTH];
  Color c;

  const int colorCount = 5;

public:

  Tetrimino() {};
  //The shape is one of the posible defined in the corresponding enum
  //The map is an MAP_LENGTH**2 array that defines the Tetromino's shape
  Tetrimino(TetriminoShape s, unsigned short * map, Tetrimino::Color c);
  ~Tetrimino();

  TetriminoShape getShape();
  unsigned short* getMap();
  //Up to the children classes to define it...
  virtual unsigned short* rotate() =0;
  Color getColor();
  
  //For debuging purposes only
  void print();


};