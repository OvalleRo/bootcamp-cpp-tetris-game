#pragma once
#include <vector>
#include "BoardCoordinates.h"
class Board
{

private:
  unsigned short rows, columns, safetyPadding, size;
  short backgroundValue, paddingValue;
  std::vector<short> boardMapVector;

public:
  Board(const unsigned short rows, const unsigned short columns,
    const unsigned short mapLength, const short backgroundValue);
  ~Board();

  //Converts a position of the array into it's coordinates in the 2D space
  BoardCoordinates getCoordinatesInBoard(short position);
  //Converts a 2D coordinate into it's position in the linear vector
  short getLinearPositionInBoardVector(BoardCoordinates c);

  void resetBoardVector();

  const std::vector<short> * getBoard() const;
  void setBoard(std::vector<short> board);

  unsigned short getColumns();
  unsigned short getRows();
  unsigned short getUsableRows(); //The amount of rows where blocks can be put..
  unsigned short getUsableColumns(); //The amount of rows where blocks can be put..

  short getBackgroundValue();
  short getPaddingValue();

  short getValue(BoardCoordinates c);
  short getValue(unsigned short position);

  void setValue(BoardCoordinates coord, short color);

};

