#include "TetrisDrawer.h"
#include <vector>


TetrisDrawer::TetrisDrawer(sf::RenderWindow & window, Board & board)
{
  this->window = &window;
  this->board = &board;
  blockScaleFactor = 1.0f;
  //backgroundScaleFactor = blockScaleFactor / 2.0f;

  if (!tetrominoTexture.loadFromFile(TEXTURE_DIR)) {
    //error
    std::cout << "Error tetromino";
  }
  tetrominoTexture.setRepeated(true);
  tetrominoSprite.setTexture(tetrominoTexture);
  tetrominoSprite.setScale(sf::Vector2f(blockScaleFactor, blockScaleFactor));

  if (!backgroundTexture.loadFromFile(BACKGROUND_DIR)) {
    //error
    std::cout << "Error background";
  }
  backgroundTexture.setRepeated(true);
  backgroundSprite.setTexture(backgroundTexture);
  //backgroundSprite.setScale(sf::Vector2f(backgroundScaleFactor, backgroundScaleFactor));

}

TetrisDrawer::~TetrisDrawer()
{
}

void TetrisDrawer::draw()
{
  const std::vector<short> * map = board->getBoard();
  short rows = board->getRows();
  short columns = board->getColumns();
  int position;

  window->clear(sf::Color::White);

  for (int i = 0; i < rows ; i++)
  {
    for (int j = 0; j < columns ; j++)
    {
      position = ((columns)*i) + j;
      if ((*map)[position] != board->getPaddingValue()) {
        tetrominoSprite.setTextureRect(sf::IntRect((*map)[position]*TEXTURE_WIDTH, 0, TEXTURE_WIDTH, TEXTURE_WIDTH));
        tetrominoSprite.setPosition(sf::Vector2f(TEXTURE_WIDTH*j*blockScaleFactor, TEXTURE_WIDTH*i*blockScaleFactor));
        window->draw(tetrominoSprite);
      }
    }
  }
 
  window->display();
}
