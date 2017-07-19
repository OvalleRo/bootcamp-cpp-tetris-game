#include "TetrisGame.h"

TetrisGame::TetrisGame()
{
  mngr = TetriminoManager();
  
  board = new Board(20, 10, Tetrimino::MAP_LENGTH, Tetrimino::BLACK);
  mover.setBoard(*board);
  winHeight = (board->getUsableRows() + 1) * TetrisDrawer::TEXTURE_WIDTH;
  winWidth = winHeight * WINDOW_ASPECT_RATIO;
  window = new sf::RenderWindow(sf::VideoMode(winWidth, winHeight), "Tetris", sf::Style::Titlebar | sf::Style::Close);
  drawer = new TetrisDrawer(*window, *board);
  lineMngr = BoardLineManager(*board);

  waitTimeMilliseconds = 2000.0f;
  level = 1;
  score = 0;

  current = nullptr;
  next = nullptr;
}

TetrisGame::~TetrisGame()
{
}

void TetrisGame::startGame()
{
  GameStatus status = PLAYING;
  soundPlayer.switchBackgroundMusicStatus(status);
  gameClock.restart();

  nextTetriminos();

  mover.insertTetrimino(*current);
  
  float elapsedMilliseconds;
  bool tetriminoChangedPosition = false;

  short clearedLines = 0, totalLines = 0;

  while (window->isOpen())
  {

    if (status == PLAYING)
    {
      elapsedMilliseconds = gameClock.getElapsedTime().asMilliseconds();
      if ((elapsedMilliseconds >= waitTimeMilliseconds)) {

        tetriminoChangedPosition = mover.moveTetrimino(Direction::DOWN);
        if (!tetriminoChangedPosition) {
          nextTetriminos();

          clearedLines = lineMngr.updateLines(currentPosition);
          if (clearedLines > 0)
          {
            soundPlayer.lineCompleted();
            totalLines += clearedLines;
            updateScore(clearedLines);
          }
          else
          {
            soundPlayer.tetriminoCollision();
          }
          tetriminoChangedPosition = mover.insertTetrimino(*current);
          if (!tetriminoChangedPosition) {
            status = OVER;
            soundPlayer.switchBackgroundMusicStatus(status);
          }
          if (totalLines >= LINES_TO_NEXT_LEVEL) {
            totalLines = 0;
            nextLevel();
          }
        }
        
        gameClock.restart();

      }
    }
    

    sf::Event event;
    while (window->pollEvent(event)) {
      if (event.type == sf::Event::Closed || 
        sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
      {
        window->close();
      }

      if (sf::Keyboard::isKeyPressed(sf::Keyboard::RControl) || 
          sf::Keyboard::isKeyPressed(sf::Keyboard::LControl))
      {
        if (status == PLAYING)
        {
          status = PAUSED;
        }
        else if (status == PAUSED)
        {
          status = PLAYING;
        }
        soundPlayer.switchBackgroundMusicStatus(status);
      }

      if (status == PLAYING)
      {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
        {
          tetriminoChangedPosition = mover.moveTetrimino(Direction::DOWN);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        {
          tetriminoChangedPosition = mover.moveTetrimino(Direction::LEFT);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        {
          tetriminoChangedPosition = mover.moveTetrimino(Direction::RIGHT);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
        {
          tetriminoChangedPosition = mover.moveTetrimino(Direction::UP);
        }

      }

      
    }

    if (tetriminoChangedPosition) {
      tetriminoChangedPosition = false;
      currentPosition = mover.getCurrentPosition();
    }

    drawer->drawGameScreen(level, score, *next, status);
  }
}

void TetrisGame::nextLevel()
{
  ++level;
  waitTimeMilliseconds *= (1.f - TIME_DECREASE_PROPORTION);
}

void TetrisGame::updateScore(short lines)
{
  score += lines * SCORE_PER_LINE;
}


void TetrisGame::nextTetriminos()
{
  if (current == nullptr) {

    current = mngr.getRandom();

  }
  else
  {
    current = next;

  }
  do
  {
    //Note: In my experience testing the game and the time library,
    //while the seed is always the unix time (always different) since there are only
    //a limited number of tetriminos and the rand number returns a number between 0 and RAND_MAX,
    //rand() % tetriminos_count can return more than once the same value, hence the loop
    next = mngr.getRandom();

  } while (next == current);
 
}

bool TetrisGame::resourcesLoadedCorrectly()
{
  return drawer->artifactsLoadedCorrectly() && soundPlayer.soundsLoadedCorrectly();
}

