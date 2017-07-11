#include "BoardLineManager.h"



BoardLineManager::BoardLineManager(Board & board)
{
  this->board = &board;
  this->rows = std::vector<unsigned short>(this->board->getRows());

}

BoardLineManager::~BoardLineManager()
{
}

unsigned short BoardLineManager::updateLines(TetriminoPosition pos)
{
  unsigned short cleared = 0;
  unsigned short noOfColumns = board->getUsableColumns();
  for (int i = 0; i < pos.getNoOfCoordinates(); i++)
  {
    Board::Coordinates coord = pos.getCoordinateAt(i);
    ++rows[coord.x];
    if (rows[coord.x] == noOfColumns)
    {
      clearRow(coord.x);
      ++cleared;
    }
   
  }

  return cleared;
}

void BoardLineManager::clearRow(unsigned short row)
{
  //rows[row] = 0;
  Board::Coordinates currentCoord, upCoord;
  bool empty = false;//when a whole row is empty
  for (int i = row; i >= 0; --i)
  {
    //Move the counter of occupied blocks along the blocks themselves.
    if (i > 0)
    {
      rows[i] = rows[i - 1];
    }
    else
    {
      rows[i] = 0;
    }
    currentCoord.x = i;
    upCoord.x = currentCoord.x - 1;
    for (int j = 0; j < board->getColumns(); j++)
    {
      currentCoord.y = j;
      short value = board->getValue(currentCoord);
      upCoord.y = currentCoord.y;

      if (value != board->getPaddingValue()) {
        //In the first (upper-most) row, there is not an upper value,
        // so we check if it is this row, and we set the value accordingly.
        if (i > 0) {
          short upValue = board->getValue(upCoord);
          board->setValue(currentCoord, upValue);
        }
        else {
          board->setValue(currentCoord, board->getBackgroundValue());
        }
      }
    }
  }
}
