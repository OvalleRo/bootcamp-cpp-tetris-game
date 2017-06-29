#include <array>
#include "StaticTetrimino.h"



StaticTetrimino::StaticTetrimino()
{
      //Because the square is the only one that won't rotate...
  name = Shapes::SQUARE;
      unsigned char new_map[] = {0,0,0,0,
                        0,0,0,0,
                        1,1,0,0,
                        1,1,0,0};
      std::copy(new_map, new_map + (MAP_LENGTH*MAP_LENGTH), this->map);
}


StaticTetrimino::~StaticTetrimino()
{
}

