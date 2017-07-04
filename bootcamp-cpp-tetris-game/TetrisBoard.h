#pragma once
#include "Tetrimino.h"
#include <tuple>
#include <stdio.h>
#include <time.h>
#include <stdio.h>
#include <vector>


class TetrisBoard
{
public:
  enum MovementDirection {
    DOWN,
    LEFT,
    RIGHT
  };

private:

  unsigned short rows, columns, safetyPadding, size, coordinates;
  //The coordinates in the map of the falling tetromino - it's top-left corner, in terms of row/col
  std::tuple<short, short> currentTetrominoPos;
  short backgroundValue, paddingValue;
  short * rowsStatii;
  std::vector<short> boardMapVector, tetriminoCoordinatesVector;
  Tetrimino * currentTetrimino;

public:
  /*
    The tetris board is basically an array of rows*column values that represents
    the diffferents blocks of the game - blocks being the background, the individual
    pieces of the Tetromino.
    For safety and simplicty, I defined a "safetyPadding": additional rows at the bottom and
    columns at the sides that counts as "walls/floor", represented with an unique value
    The map length is the length of the "matrix" that represents the Tetromino.
    */
  TetrisBoard(unsigned short rows, unsigned short columns, 
              unsigned short mapLength, short backgroundValue);
  ~TetrisBoard();

  unsigned short getRows();
  unsigned short getColumns();
  short getPaddingValue();
  short getSize();

  const std::vector<short> getBoardMap() const;
  std::tuple<short, short> get2DPosition(short pos);
  
  bool moveTetrimino(TetrisBoard::MovementDirection dir);
  bool insertNewTetrimino(Tetrimino & t);
  bool fixCurrentTetrominoInPosition();

  bool clearRow(short rowToClear);
  bool isLastRowFull();
  

  void print();

private:
  bool checkCollision();
  bool moveTetrimino(short rowDelta, short colDelta);
  void resetTetrominoCoordinates();
};

