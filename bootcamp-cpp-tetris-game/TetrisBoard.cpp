#include "TetrisBoard.h"
#include <algorithm>

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

  this->coordinates = mapLength;

  this->size = this->rows * this->columns;
  //row and column of the tetromino
  this->currentTetrominoPos = std::tuple<short, short>(-1, -1);
  
  resetTetrominoCoordinates(); //Initializes the coordinates to an array of in valid positions
                                // as there is not a tetromino in the board.

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

bool TetrisBoard::moveTetrimino(TetrisBoard::MovementDirection dir)
{
  if (tetriminoCoordinatesVector[0] == -1) {
    //There is no tetrimino to move
    return false;
  }
  short rowDelta, colDelta;
  switch (dir)
  {
  case TetrisBoard::DOWN:
    rowDelta = 1;
    colDelta = 0;
    
    break;
  case TetrisBoard::LEFT:
    rowDelta = 0;
    colDelta = -1;

    break;
  case TetrisBoard::RIGHT:
    rowDelta = 0;
    colDelta = 1;

    break;
  default:
    return false;
    break;
  }

  return moveTetrimino(rowDelta, colDelta);
}

void TetrisBoard::resetTetrominoCoordinates() {
  this->tetriminoCoordinatesVector = vector<short>(coordinates, -1);

}

bool TetrisBoard::insertNewTetrimino(Tetrimino & t)
{
  // Inserts the tetrimino in the board, giving it new coordinates for each of the blocks
  unsigned short * tetriminoMap = t.getMap();
  unsigned short color = t.getColor();
  unsigned short initialCol = columns / 2 - ((safetyPadding + 1) / 2), index = 0;
  vector<short>  newBoardMapVector = boardMapVector;

  for (int row = 0; row < safetyPadding + 1; row++)
  {
    for (int col = 0; col < safetyPadding + 1; col++)
    {
      short tetriminoMapPosition, boardMapPosition;

      tetriminoMapPosition = ((safetyPadding + 1) *row) + col;
      if (tetriminoMap[tetriminoMapPosition] != backgroundValue) {
        boardMapPosition = (columns * row) + initialCol + col;
        
        //The tetrimino tries to move to an occupied position
        if (boardMapVector[boardMapPosition] != backgroundValue) {
          resetTetrominoCoordinates();
          return false;
        }
        newBoardMapVector[boardMapPosition] = color;
        tetriminoCoordinatesVector[index] = boardMapPosition;
        ++index;
      }
    }
  }
  boardMapVector = newBoardMapVector;
  return true;
}

bool TetrisBoard::fixCurrentTetrominoInPosition()
{
  resetTetrominoCoordinates();
  return true;
}

void TetrisBoard::print()
{
  for (int r = 0; r < rows; r++)
  {
    for (int c = 0; c < columns; c++)
    {
      short position = (this->columns * r) + c;
      std::cout << boardMapVector[position] << " ";
    }
    std::cout << std::endl;
  }
}

bool TetrisBoard::checkCollision()
{
  return false;
}


bool TetrisBoard::moveTetrimino(short rowDelta, short colDelta)
{
  /*
    Given the row and col deltas, the tetromino is moved in the board
    as long as it moves to an empty space (background block or value).
  */

  short nextCoordinate, currentValue, currentCoordinate;
  vector<short> newTetriminoCoordinatesVector = tetriminoCoordinatesVector,
                  newBoardMapVector = boardMapVector;
  for (int i = 0; i < coordinates; i++)
  {
    currentCoordinate = tetriminoCoordinatesVector[i];
    nextCoordinate = (rowDelta * columns) + colDelta + currentCoordinate;
    if (boardMapVector[nextCoordinate] != backgroundValue &&
        count(tetriminoCoordinatesVector.begin(), tetriminoCoordinatesVector.end(), nextCoordinate) == 0) {
      return false;
    }

    newTetriminoCoordinatesVector[i] = nextCoordinate;
    
    newBoardMapVector[currentCoordinate] = backgroundValue;
  }
  for (int i = 0; i < coordinates; i++)
  {
    currentCoordinate = tetriminoCoordinatesVector[i];
    nextCoordinate = (rowDelta * columns) + colDelta + currentCoordinate;
    newBoardMapVector[nextCoordinate] = boardMapVector[currentCoordinate];
  }

  boardMapVector = newBoardMapVector;

  tetriminoCoordinatesVector = newTetriminoCoordinatesVector;
  return true;
}
