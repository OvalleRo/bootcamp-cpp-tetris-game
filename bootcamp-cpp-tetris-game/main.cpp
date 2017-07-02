#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "TetriminoDrawer.h"
#include "TetriminoManager.h"
#include "TetrisBoard.h"

void draw() {

  TetriminoManager mngr{};
  Tetrimino * t;
  t = mngr.getRandom();

  sf::RenderWindow window(sf::VideoMode(700, 700), "Ventana", sf::Style::Titlebar | sf::Style::Close);
  TetriminoDrawer drawer(window);
  while (window.isOpen()) {
    sf::Event event;
    while (window.pollEvent(event))
    {
      if (event.type == sf::Event::Closed) {
        window.close();
      }
      if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
        t->rotate();
      }
      if (sf::Keyboard::isKeyPressed(sf::Keyboard::R)) {
        t = mngr.getRandom();
      }

    }
    window.clear();
    drawer.draw(*t);
    window.display();


  }
}

int main()
{
  TetrisBoard * b = new TetrisBoard(20, 10, Tetrimino::MAP_LENGTH, Tetrimino::BLACK);
  //b->print();

  TetriminoManager mngr{};
  Tetrimino * t;
  t = mngr.getByName(TetriminoShape::SQUARE);

  if (!b->insertTetrimino(*t)) {
    std::cout << "Can't insert the tetrimino";
  }
  else
  {
    b->print();
  }


  return 0;
}