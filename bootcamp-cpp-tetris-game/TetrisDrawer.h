#pragma once
#include "Tetrimino.h"
#include "Board.h"
#include "SFML\Graphics.hpp"
#include <sstream>
#include <string>
class TetrisDrawer
{
public:
  static const int TEXTURE_WIDTH = 40;
private:
  sf::RenderWindow *window;
  const char * TEXTURE_DIR = "../resources/textures/allBlocks_40_40_8.png";
  const char * BACKGROUND_DIR = "../resources/backgrounds/background_blocks_pattern.png";
  const char * FONT_DIR = "../resources/fonts/ARCADE.TTF";
  static const int BACKGROUND_WIDTH = 160;
  Board * board;
  float blockScaleFactor, backgroundScaleFactor;
  sf::Sprite tetrominoSprite;
  sf::RectangleShape background, gameInfo, nextTetrimino;
  sf::Texture tetrominoTexture, backgroundTexture;
  sf::Font gameFont;
  sf::Text gameInfoText;

public:
  TetrisDrawer(sf::RenderWindow & window, Board & board);
  ~TetrisDrawer();

  void draw(short level, int score, Tetrimino & next);

private:
  void drawBackground();

  void drawBoard();

  void drawGameInfo(short level, int score);

  void drawNextTetrimino(Tetrimino & next);

};

