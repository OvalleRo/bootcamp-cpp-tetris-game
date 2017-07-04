#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

#include "TetrisDrawer.h"
#include "TetriminoManager.h"
#include "TetrisBoard.h"

int main()
{
  TetrisBoard * b = new TetrisBoard(20, 10, Tetrimino::MAP_LENGTH, Tetrimino::BLACK);
  //b->print();

  TetriminoManager mngr{};
  Tetrimino * t;

  t = mngr.getRandom();

  if (!b->insertNewTetrimino(*t)) {
    std::cout << "Can't insert the tetrimino";
  }
  else
  {

    sf::RenderWindow window(sf::VideoMode(700, 700), "Ventana", sf::Style::Titlebar | sf::Style::Close);
    TetrisDrawer drawer(window, *b);
    while (window.isOpen()) {
      sf::Event event;
      while (window.pollEvent(event))
      {
        if (event.type == sf::Event::Closed) {
          window.close();
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
          b->moveTetrimino(TetrisBoard::DOWN);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
          b->moveTetrimino(TetrisBoard::LEFT);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
          b->moveTetrimino(TetrisBoard::RIGHT);
        }
      }
      window.clear(sf::Color::White);
      
      drawer.draw();
      window.display();


    }
  }

  


  return 0;
}