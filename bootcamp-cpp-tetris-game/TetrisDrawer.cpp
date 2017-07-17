#include "TetrisDrawer.h"
#include <vector>


TetrisDrawer::TetrisDrawer(sf::RenderWindow & window, Board & board)
{
  this->window = &window;
  this->board = &board;
  blockScaleFactor = 1.0f;
  sf::Image icon;
  icon.loadFromFile(ICON_DIR);
  this->window->setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());

  if (!initTexture(tetrominoTexture, TEXTURE_DIR)) {
    //error
    std::cout << "Error tetromino";
  }
  tetrominoTexture.setRepeated(true);
  tetrominoSprite.setTexture(tetrominoTexture);
  tetrominoSprite.setScale(sf::Vector2f(blockScaleFactor, blockScaleFactor));

  if (!initTexture(backgroundTexture, BACKGROUND_DIR)) {
    //error
    std::cout << "Error background";
  }
  backgroundTexture.setRepeated(true);
  backgroundTexture.setSmooth(true);
  background.setSize(sf::Vector2f(BACKGROUND_WIDTH, BACKGROUND_WIDTH));
  background.setTexture(&backgroundTexture);

  if (!initFont(gameFont, FONT_DIR))
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

void TetrisDrawer::drawGameScreen(short level, int score, Tetrimino & next, GameStatus status)
{
  window->clear(sf::Color::Black);
  
  drawBackground();

  drawBoard();

  drawGameInfo(level, score);

  drawNextTetrimino(next);

  if (status != PLAYING)
  {
    drawStatusSplash(status);
  }
   
  window->display();
}

void TetrisDrawer::drawStatusSplash(GameStatus status)
{
  sf::RectangleShape statusSplashBox;
  statusSplashBox.setFillColor(sf::Color(0, 0, 0, 192));
  statusSplashBox.setSize(sf::Vector2f(window->getSize()));
  window->draw(statusSplashBox);

  sf::Text statusText;
  if (status == OVER)
  {
    statusText.setString("Game over!");
    statusText.setCharacterSize(96);
  }
  else
  {
    statusText.setString("Paused, CTRL to continue.");
    statusText.setCharacterSize(48);
  }
  statusText.setFont(gameFont);
  statusText.setPosition(statusSplashBox.getSize().x / 4.f,
    statusSplashBox.getSize().y / 3.f);
  window->draw(statusText);
}

bool TetrisDrawer::initTexture(sf::Texture & t, const char * dir)
{
  // Tries three times to load the texture, if sfml misbehaves,
  // return false
  for (int i = 0; i < 3; i++)
  {
    if (t.loadFromFile(dir)) {
      return true;
    }
  }
  return false;
}

bool TetrisDrawer::initFont(sf::Font & f, const char * dir)
{
  // Tries three times to load the font, if sfml misbehaves,
    // return false
    for (int i = 0; i < 3; i++)
    {
      if (f.loadFromFile(dir)) {
        return true;
      }
    }
  return false;
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

  unsigned short * map = next.getMap();
  unsigned short color = next.getColor();

  sf::Vector2f startingPosition = nextTetriminoBox.getPosition() +
                                  sf::Vector2f(TEXTURE_WIDTH * 4, TEXTURE_WIDTH * 2);

  for (int row = 0; row < Tetrimino::MAP_LENGTH; row++)
  {
    for (int column = 0; column < Tetrimino::MAP_LENGTH; column++)
    {
      int position = (row * Tetrimino::MAP_LENGTH) + column;
      if (map[position] != 0)
      {
        tetrominoSprite.setTextureRect(sf::IntRect(map[position] * TEXTURE_WIDTH * color, 0, TEXTURE_WIDTH, TEXTURE_WIDTH));
        tetrominoSprite.setPosition(sf::Vector2f(TEXTURE_WIDTH*column + startingPosition.x, TEXTURE_WIDTH*row + startingPosition.y));
        window->draw(tetrominoSprite);
      }
    }
  }
}
