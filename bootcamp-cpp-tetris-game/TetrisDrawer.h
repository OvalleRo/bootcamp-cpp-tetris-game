#pragma once
#include "Tetrimino.h"
#include "Board.h"
#include "SFML\Graphics.hpp"
#include <sstream>
#include <string>
#include "GameStatus.h"
class TetrisDrawer
{
private:
  sf::RenderWindow *window;
  const char * TEXTURE_DIR = "./resources/textures/allBlocks_40_40_8.png";
  const char * BACKGROUND_DIR = "./resources/backgrounds/background_blocks_pattern.png";
  const char * FONT_DIR = "./resources/fonts/ARCADE.TTF";
  const char * ICON_DIR = "./resources/icon.png";
  static const int BACKGROUND_WIDTH = 160;
  Board * board;
  float blockScaleFactor, backgroundScaleFactor;
  sf::Sprite tetrominoSprite;
  sf::RectangleShape background, gameInfoBox, nextTetriminoBox;
  sf::Texture tetrominoTexture, backgroundTexture;
  sf::Font gameFont;
  sf::Text gameInfoText, nextTetriminoText;
  //This flag indicates whether the resources (graphics, fonts, etc) were correctly loaded
  bool graphicsArtifactsLoaded;

  bool initTexture(sf::Texture & t, const char * dir);

  bool initFont(sf::Font & f, const char * dir);

  void drawStatusSplash(GameStatus status);

  void drawBackground();

  void drawBoard();

  void drawGameInfo(short level, int score);

  void drawNextTetrimino(Tetrimino & next);

public:
  static const int TEXTURE_WIDTH = 40;

  TetrisDrawer(sf::RenderWindow & window, Board & board);
  ~TetrisDrawer();

  void drawGameScreen(short level, int score, Tetrimino & next, GameStatus status);
  bool artifactsLoadedCorrectly();
};

