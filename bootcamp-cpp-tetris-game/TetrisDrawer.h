#pragma once
#include "Tetrimino.h"
#include "Board.h"
#include "SFML\Graphics.hpp"
#include <sstream>
#include <string>
#include "GameStatus.h"
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
  sf::RectangleShape background, gameInfoBox, nextTetriminoBox;
  sf::Texture tetrominoTexture, backgroundTexture;
  sf::Font gameFont;
  sf::Text gameInfoText, nextTetriminoText;

public:
  TetrisDrawer(sf::RenderWindow & window, Board & board);
  ~TetrisDrawer();

  void drawGameScreen(short level, int score, Tetrimino & next, GameStatus status);

private:
  bool initTexture(sf::Texture & t, const char * dir);

  bool initFont(sf::Font & f, const char * dir);

  void drawStatusSplash(GameStatus status);
  
  void drawBackground();

  void drawBoard();

  void drawGameInfo(short level, int score);

  void drawNextTetrimino(Tetrimino & next);

};

