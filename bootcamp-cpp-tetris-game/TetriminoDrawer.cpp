#include "TetriminoDrawer.h"
#include <stdlib.h>
#include <stdio.h>


TetriminoDrawer::TetriminoDrawer(sf::RenderWindow & window)
{
  this->window = &window;
}

TetriminoDrawer::~TetriminoDrawer()
{
}

void TetriminoDrawer::draw(Tetrimino & t)
{

  sf::Sprite tetrominoSprite;
  sf::Texture tetrominoTexture;

  unsigned short * map = t.getMap();

  int position;


  if (!tetrominoTexture.loadFromFile("../resources/textures/allBlocks_40_40_6.png")) {
    //error
  }
  tetrominoTexture.setRepeated(true);
  tetrominoSprite.setTexture(tetrominoTexture);
  tetrominoSprite.setTextureRect(sf::IntRect(t.getColor()*textureWidth, 0, 40, 40));

  for (int x = 0; x < Tetrimino::MAP_LENGTH; x++)
  {
    for (int y = 0; y < Tetrimino::MAP_LENGTH; y++) {
      position = (Tetrimino::MAP_LENGTH * x) + y;
      if (map[position] != 0) {
        tetrominoSprite.setPosition(sf::Vector2f(textureWidth*y, textureWidth*x));
        window->draw(tetrominoSprite);
      }
    }
  }

}
