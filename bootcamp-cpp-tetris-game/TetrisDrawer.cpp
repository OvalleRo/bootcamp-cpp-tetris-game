#include "TetrisDrawer.h"
#include <vector>


TetrisDrawer::TetrisDrawer(sf::RenderWindow & window, TetrisBoard & board)
{
  this->window = &window;
  this->board = &board;
  scaleFactor = 0.75f;

  if (!tetrominoTexture.loadFromFile(TEXTURE_DIR)) {
    //error
  }
  tetrominoTexture.setRepeated(true);
  tetrominoSprite.setTexture(tetrominoTexture);
  tetrominoSprite.setScale(sf::Vector2f(scaleFactor, scaleFactor));

}

TetrisDrawer::~TetrisDrawer()
{
}

void TetrisDrawer::draw()
{
  std::vector<short> map = board->getBoardMap();
  short rows = board->getRows();
  short columns = board->getColumns();
  int position, screenX, screenY;

  for (int i = 0; i < rows ; i++)
  {
    for (int j = 0; j < columns ; j++)
    {
      position = ((columns)*i) + j;
      if (map[position] != board->getPaddingValue()) {
        tetrominoSprite.setTextureRect(sf::IntRect(map[position]*TEXTURE_WIDTH, 0, TEXTURE_WIDTH, TEXTURE_WIDTH));
        tetrominoSprite.setPosition(sf::Vector2f(TEXTURE_WIDTH*j*scaleFactor, TEXTURE_WIDTH*i*scaleFactor));
        window->draw(tetrominoSprite);
      }
    }
  }
 
}
