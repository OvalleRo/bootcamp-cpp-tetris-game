#pragma once
#include <vector>
class Board
{
public:
  struct Coordinates
  {
    short x;
    short y;
  };

private:
  unsigned short rows, columns, safetyPadding, size;
  short backgroundValue, paddingValue;
  std::vector<short> boardMapVector;

public:
  Board(const unsigned short rows, const unsigned short columns,
    const unsigned short mapLength, const short backgroundValue);
  ~Board();

  Board::Coordinates getCoordinatesInBoard(short position);
  short getLinearPositionInBoardVector(Board::Coordinates c);
  void resetBoardVector();
};

