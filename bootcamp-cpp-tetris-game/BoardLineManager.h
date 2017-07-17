#pragma once
#include "Board.h"
#include "TetriminoPosition.h"
#include <vector>
//This class manages the status of each line of the board
class BoardLineManager
{
private:
  Board * board;
  std::vector<unsigned short> rows;

public:
  BoardLineManager() {};
  BoardLineManager(Board & board);
  ~BoardLineManager();

  //Returns the number of lines cleared after they are updated with the position of the tetrimino
  // that it's set in place
  unsigned short updateLines(TetriminoPosition pos);
  //Sets the given row as full. It means that the row is cleared, it's status is set to the
  //inmmediate upper row status, and so on...
  void clearRow(unsigned short row);
};

