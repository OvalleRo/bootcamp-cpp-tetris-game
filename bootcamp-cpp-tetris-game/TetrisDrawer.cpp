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
  backgroundTexture.setSmooth(true);
  background.setSize(sf::Vector2f(BACKGROUND_WIDTH, BACKGROUND_WIDTH));
  background.setTexture(&backgroundTexture);

  if (!gameFont.loadFromFile(FONT_DIR))
  {
    //Font error
    std::cout << "Font error";
  }
  gameInfo.setSize(sf::Vector2f(this->window->getSize().x / 3.f, this->window->getSize().y / 6.f));
  gameInfo.setFillColor(sf::Color(0, 0, 0, 192));
  gameInfo.setPosition(this->window->getSize().x * (3.f/5.f), this->window->getSize().y / 10.f);
  gameInfoText.setFont(gameFont);
  gameInfoText.setCharacterSize(gameInfo.getSize().x/10.f);
  gameInfoText.setPosition(gameInfo.getPosition().x + gameInfo.getSize().x / 13.f,
                          gameInfo.getPosition().y + gameInfo.getSize().y / 3.f);

}

TetrisDrawer::~TetrisDrawer()
{
}

void TetrisDrawer::draw(short level, int score, Tetrimino & next)
{
  window->clear(sf::Color::Black);
  
  drawBackground();

  drawBoard();

  drawGameInfo(level, score);

  drawNextTetrimino(next);
   
  window->display();
}

void TetrisDrawer::drawBackground()
{
  for (float i = 0.f; i < window->getSize().x; i+=BACKGROUND_WIDTH)
  {
    for (float j = 0.f; j < window->getSize().y; j+=BACKGROUND_WIDTH)
    {
      background.setPosition(sf::Vector2f(i, j));
      window->draw(background);
    }
  }
}

void TetrisDrawer::drawBoard()
{
  const std::vector<short> * map = board->getBoard();
  short rows = board->getRows();
  short columns = board->getColumns();
  int position;


  for (int i = 0; i < rows; i++)
  {
    for (int j = 0; j < columns; j++)
    {
      position = ((columns)*i) + j;
      if ((*map)[position] != board->getPaddingValue()) {
        tetrominoSprite.setTextureRect(sf::IntRect((*map)[position] * TEXTURE_WIDTH, 0, TEXTURE_WIDTH, TEXTURE_WIDTH));
        tetrominoSprite.setPosition(sf::Vector2f(TEXTURE_WIDTH*j*blockScaleFactor, TEXTURE_WIDTH*i*blockScaleFactor));
        window->draw(tetrominoSprite);
      }
    }
  }

}

void TetrisDrawer::drawGameInfo(short level, int score)
{
  std::stringstream ss;
  ss << "Level " << level << " - Score " << score;
  gameInfoText.setString(ss.str());
  
  window->draw(gameInfo);
  window->draw(gameInfoText);
}

void TetrisDrawer::drawNextTetrimino(Tetrimino & next)
{
}
