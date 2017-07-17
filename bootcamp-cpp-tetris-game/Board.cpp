#include "Board.h"

Board::Board(const unsigned short rows, const unsigned short columns, const unsigned short mapLength, const short backgroundValue)
{
  //The board has a padding, symbolized in the vector with a given value, 
  //so the tetrimino won't collide if a blank position (background value) in it's map
  //moves outside the board
  this->safetyPadding = mapLength - 1;
  this->paddingValue = -1;
  //Padding at the bottom and the sides
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

//Given a position in the vector, returns it's coordinates in a 2D space
BoardCoordinates Board::getCoordinatesInBoard(short position)
{
  //x it's the row, y the column
  BoardCoordinates c(position / columns, position % columns);
  return c;
}

//Does the opposite of the Board::getCoordinatesInBoard() function
short Board::getLinearPositionInBoardVector(BoardCoordinates c)
{
  short position = (this->columns * c.getX()) + c.getY();
  return position;
}

void Board::resetBoardVector()
{
  //The linear vector symbolizes the 2d tetris board. It has n rows and 
  //each row has m columns
  BoardCoordinates c;
  for (short i = 0; i < this->rows; i++)
  {
    c.setX(i);
    for (short j = 0; j < this->columns; j++)
    {
      c.setY(j);
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

const std::vector<short> * Board::getBoard() const
{
  return &boardMapVector;
}

void Board::setBoard(std::vector<short> board)
{
  boardMapVector = board;
}

unsigned short Board::getColumns()
{
  return columns;
}

unsigned short Board::getRows()
{
  return rows;
}

//The usable rows are the number of rows that are not padding
unsigned short Board::getUsableRows()
{
  return rows - safetyPadding;
}

//The usable columns are the number of rows that are not padding
unsigned short Board::getUsableColumns()
{
  return columns - (safetyPadding * 2);
}

short Board::getBackgroundValue()
{
  return backgroundValue;
}

short Board::getPaddingValue()
{
  return paddingValue;
}

//Returns the value of the board in the given coordinate
short Board::getValue(BoardCoordinates c)
{
  return boardMapVector[getLinearPositionInBoardVector(c)];
}

//Returns the value of the board in the given linear position
short Board::getValue(unsigned short position)
{
  return boardMapVector[position];
}
//Sets the color of the board in the given coordinate
void Board::setValue(BoardCoordinates coord, short color)
{
  boardMapVector[getLinearPositionInBoardVector(coord)] = color;
}


