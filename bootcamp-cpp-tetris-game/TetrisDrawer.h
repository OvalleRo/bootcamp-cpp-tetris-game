#pragma once
#include "Tetrimino.h"
#include "Board.h"
#include "SFML\Graphics.hpp"
class TetrisDrawer
{
private:
  sf::RenderWindow *window;
  const char * TEXTURE_DIR = "../resources/textures/allBlocks_40_40_6.png";

  const int TEXTURE_WIDTH = 40;
  Board * board;
  float scaleFactor;
  sf::Sprite tetrominoSprite;
  sf::Texture tetrominoTexture;


public:
  TetrisDrawer(sf::RenderWindow & window, Board & board);
  ~TetrisDrawer();

  void draw();

};

