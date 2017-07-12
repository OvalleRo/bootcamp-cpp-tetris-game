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
  //Fill color for the boxes
  sf::Color boxColor(0, 0, 0, 192);

  gameInfoBox.setSize(sf::Vector2f(this->window->getSize().x / 3.f, this->window->getSize().y / 6.f));
  gameInfoBox.setFillColor(boxColor);
  gameInfoBox.setPosition(this->window->getSize().x * (3.f/5.f), this->window->getSize().y / 10.f);

  float textSize = gameInfoBox.getSize().x / 10.f;
  gameInfoText.setFont(gameFont);
  gameInfoText.setCharacterSize(textSize);
  gameInfoText.setPosition(gameInfoBox.getPosition().x + gameInfoBox.getSize().x / 13.f,
                          gameInfoBox.getPosition().y + gameInfoBox.getSize().y / 3.f);

  nextTetriminoBox.setFillColor(boxColor);
  nextTetriminoBox.setSize(sf::Vector2f(gameInfoBox.getSize().x, TEXTURE_WIDTH * 7));
  nextTetriminoBox.setPosition(gameInfoBox.getPosition().x,
                            gameInfoBox.getPosition().y + (gameInfoBox.getSize().y * 1.5f));

  nextTetriminoText.setCharacterSize(textSize);
  nextTetriminoText.setFont(gameFont);
  nextTetriminoText.setString("Next Tetrimino");
  nextTetriminoText.setPosition(nextTetriminoBox.getPosition().x + nextTetriminoBox.getSize().x / 5.f,
                              nextTetriminoBox.getPosition().y + nextTetriminoBox.getSize().y / 15.f);
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
  
  window->draw(gameInfoBox);
  window->draw(gameInfoText);
}

void TetrisDrawer::drawNextTetrimino(Tetrimino & next)
{
  window->draw(nextTetriminoBox);
  window->draw(nextTetriminoText);
}
