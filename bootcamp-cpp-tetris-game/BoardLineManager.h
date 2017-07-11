#pragma once
#include "Board.h"
#include "TetriminoPosition.h"
#include <vector>
class BoardLineManager
{
private:
  Board * board;
  std::vector<unsigned short> rows;

public:
  BoardLineManager() {};
  BoardLineManager(Board & board);
  ~BoardLineManager();

  //Returns the number of lines cleared
  unsigned short updateLines(TetriminoPosition pos);
  void clearRow(unsigned short row);
};

