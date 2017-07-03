#include "TetrisBoard.h"

using namespace std;
TetrisBoard::TetrisBoard(const unsigned short rows, const unsigned short columns, 
  const unsigned short mapLength, const short backgroundValue)
{
  //For random positions at insertion time
  srand(time(NULL));


  this->safetyPadding = mapLength - 1;
  this->paddingValue = -1;
  this->rows = rows + safetyPadding;
  this->columns = columns + (safetyPadding * 2);
  this->backgroundValue = backgroundValue;

  this->size = this->rows * this->columns;
  //row and column of the tetromino
  this->currentTetrominoPos = std::tuple<short, short>(-1, -1);

  boardMapVector = vector<short>(size);
  rowsStatii = new short[rows];


  for (short i = 0; i < this->rows; i++)
  {
    if (i < this->rows - safetyPadding - 1) {
      rowsStatii[i] = 0;
    }
    for (short j = 0; j < this->columns; j++)
    {
      short position = (this->columns * i) + j;
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

TetrisBoard::~TetrisBoard()
{
}

unsigned short TetrisBoard::getRows()
{
  return rows;
}

unsigned short TetrisBoard::getColumns()
{
  return columns;
}

short TetrisBoard::getPaddingValue()
{
  return paddingValue;
}

short TetrisBoard::getSize()
{
  return size;
}

const vector<short> TetrisBoard::getBoardMap() const
{
  return boardMapVector;
}

std::tuple<short, short> TetrisBoard::get2DPosition(short pos)
{
  short currentColumn = pos % columns,
    currentRow = pos / rows;
  return std::tuple<short, short>(currentRow, currentColumn);
}

bool TetrisBoard::insertTetrimino(Tetrimino & t)
{
  unsigned short * tetriminoMap = t.getMap();
  unsigned short color = t.getColor();
  vector<short>  newBoardMapVector = boardMapVector;

  //  Set the position of the tetromino in any VALID place of the
  //  0th row
  get<0>(currentTetrominoPos) = 0;
  get<1>(currentTetrominoPos) = columns / 2 - ((safetyPadding + 1) / 2);
  for (short i = 0; i < safetyPadding + 1; i++)
  {
    
    for (short j = 0; j < safetyPadding + 1; j++)
    {
      short tetriminoMapPosition, boardMapPosition;

      tetriminoMapPosition = ((safetyPadding + 1) *i) + j;
      boardMapPosition = (columns * i) + get<1>(currentTetrominoPos) + j;
      newBoardMapVector[boardMapPosition] += (tetriminoMap[tetriminoMapPosition] * color);
    }
  }
  if (!checkCollision()) {
    boardMapVector = newBoardMapVector;
    return true;
  }
  return false;
}

void TetrisBoard::print()
{
  for (int i = 0; i < rows; i++)
  {
    for (int j = 0; j < columns; j++)
    {
      short position = (this->columns * i) + j;
      std::cout << boardMapVector[position] << " ";
    }
    std::cout << std::endl;
  }
}

bool TetrisBoard::checkCollision()
{
  return false;
}
