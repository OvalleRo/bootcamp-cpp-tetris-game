#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

#include "TetrisDrawer.h"
#include "TetriminoManager.h"
#include "TetriminoMover.h"
#include "Board.h"


int main()
{
  short winHeight = 900, winWidth = 1200;

  sf::RenderWindow * window = new sf::RenderWindow(sf::VideoMode(winWidth, winHeight), "Ventana", sf::Style::Titlebar | sf::Style::Close);
  TetriminoManager mngr{};
  Tetrimino * t;
  Board * board = new Board(20, 10, Tetrimino::MAP_LENGTH, Tetrimino::BLACK);
  TetriminoMover mover(*board);
  TetrisDrawer drawer(*window, *board);

  t = mngr.getRandom();
  mover.insertTetrimino(*t);

  while (window->isOpen())
  {
    sf::Event event;
    while (window->pollEvent(event)) {
      if (event.type == sf::Event::Closed)
      {
        window->close();
      }
      if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
      {
        mover.moveTetrimino(TetriminoMover::DOWN);
      }
      if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
      {
        mover.moveTetrimino(TetriminoMover::LEFT);
      }
      if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
      {
        mover.moveTetrimino(TetriminoMover::RIGHT);
      }

    }
    window->clear(sf::Color::White);
    drawer.draw();
    window->display();
  }
  return 0;
}