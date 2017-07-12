#pragma once
#include "Tetrimino.h"
#include "Board.h"
#include "SFML\Graphics.hpp"
class TetrisDrawer
{
private:
  sf::RenderWindow *window;
  const char * TEXTURE_DIR = "../resources/textures/allBlocks_40_40_8.png";
  const char * BACKGROUND_DIR = "../resources/backgrounds/background_blocks_pattern.png";
  const int TEXTURE_WIDTH = 40;
  const int BACKGROUND_WIDTH = 160;
  Board * board;
  float blockScaleFactor, backgroundScaleFactor;
  sf::Sprite tetrominoSprite;
  sf::RectangleShape background;
  sf::Texture tetrominoTexture, backgroundTexture;


public:
  TetrisDrawer(sf::RenderWindow & window, Board & board);
  ~TetrisDrawer();

  void draw();

private:
  void drawBackground();

  void drawBoard();

};

