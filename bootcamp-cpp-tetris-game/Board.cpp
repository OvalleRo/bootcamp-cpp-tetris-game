#include "Board.h"

Board::Board(const unsigned short rows, const unsigned short columns, const unsigned short mapLength, const short backgroundValue)
{

  this->safetyPadding = mapLength - 1;
  this->paddingValue = -1;
  this->rows = rows + safetyPadding;
  this->columns = columns + (safetyPadding * 2);
  this->backgroundValue = backgroundValue;

  this->size = this->rows * this->columns;
  boardMapVector = std::vector<short>(size);

  resetBoardVector();
}

Board::~Board()
{
}

Board::Coordinates Board::getCoordinatesInBoard(short position)
{
  Board::Coordinates c;
  c.x = position / columns;
  c.y = position % columns;
  return c;
}

short Board::getLinearPositionInBoardVector(Board::Coordinates c)
{
  short position = (this->columns * c.x) + c.y;
  return position;
}

void Board::resetBoardVector()
{
  Board::Coordinates c;
  for (short i = 0; i < this->rows; i++)
  {
    c.x = i;
    for (short j = 0; j < this->columns; j++)
    {
      c.y = j;
      short position = getLinearPositionInBoardVector(c);
      if (j < safetyPadding || j >(this->columns - safetyPadding) - 1 ||
        i > this->rows - safetyPadding - 1) {
        boardMapVector[position] = paddingValue;
      }
      else {
        boardMapVector[position] = this->backgroundValue;
      }
    }
  }
}
