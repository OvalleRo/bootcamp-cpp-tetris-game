#pragma once
#include <vector>
class Board
{
public:
  struct Coordinates
  {
    short x;
    short y;

    inline bool operator==(const Board::Coordinates& rhs) {
      
        if (this->x == rhs.x && this->y == rhs.y) {
          return true;
        }
        return false;
      
    }
  };

private:
  unsigned short rows, columns, safetyPadding, size;
  short backgroundValue, paddingValue;
  std::vector<short> boardMapVector;

public:
  Board(const unsigned short rows, const unsigned short columns,
    const unsigned short mapLength, const short backgroundValue);
  ~Board();

  //Converts a position of the array into it's coordinates in the 2D space
  Board::Coordinates getCoordinatesInBoard(short position);
  //Converts a 2D coordinate into it's position in the linear vector
  short getLinearPositionInBoardVector(Board::Coordinates c);

  void resetBoardVector();

  const std::vector<short> * getBoard() const;
  void setBoard(std::vector<short> board);

  unsigned short getColumns();
  unsigned short getRows();

  short getBackgroundValue();
  short getPaddingValue();

  short getValue(Board::Coordinates c);
  short getValue(unsigned short position);

  void setValue(Board::Coordinates coord, short color);

};

