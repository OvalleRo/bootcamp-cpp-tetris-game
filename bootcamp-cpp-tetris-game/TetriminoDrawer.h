#pragma once
#include "SFML\Graphics.hpp"
#include "Tetrimino.h"


class TetriminoDrawer
{
private:
  sf::RenderWindow *window;
  char * textureDir = "../resources/textures/allBlocks_40_40_6.png";

  const int textureWidth = 40;


public:
  TetriminoDrawer(sf::RenderWindow & window);
  ~TetriminoDrawer();

  void draw(Tetrimino & t);
};

