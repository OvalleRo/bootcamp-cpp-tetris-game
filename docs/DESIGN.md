# A simple TETRIS game implementation

### __*A design proposal*__

 For the sake of simplicity, this design is roughly explained here. For more information, refer to the source documentation and the code itself.

 The game consists of the following major components:

 1. An __application__ module, that provides an interface between the user and the game. The idea behind this is the abstraction of the game and the platform running the game (targeting initially Windows machines); this way the door for porting the game is left wide open, if desired.
 1. A __game__ module. This one establishes the rules of the TETRIS game, controlling the __pieces or tetriminos__ in a __game board__, setting the conditions of the game to the player and the eventual defeat (you can't win here), keeping the scores.
 1. A __board__, with it's own logic for the pieces to infteract with each other, providing a discreet and limited enviroment for the player to try not to lose.
 1. The __Tetriminos__ or Tetris game pieces, consisting each one of them of four parts that are created as a whole, but can be destroyed individually. The Tetriminos can be moved and rotated as long as they are not set in the board.

#### Aplication
  Consists of a simple WinMain(...) function on the *main.cpp* file. It serves as the point of entry
of the game, creating it and showing the screen if the graphics and sounds were correctly loaded.

#### Game
  The *game* class itself is TetrisGame. It manages the core logic of Tetris:
 
* The management of the *tetriminos* (getting both the *current* and *next* tetrimino), and keeping the *position* on the board of the falling (current) tetrimino;
* The creation of the *board*, and control of the *correct* movement of tetriminos;
* Keeping the score (checking if the lines are full and clearing them via the *BoardLineManager*);
* Leveling up the game and speeding it accordingly;
* Start *PLAYING* the game and changing the status of itself between that and *PAUSE* or *OVER*;

  The UI itself is drawn using the SFML library and the graphical resources (backgrounds, textures, fonts)
given in the ./resources/ folder. The *TetrisDrawer* is responsible for all of that. Sounds are also provided (collision and music),
and another entity is responsible for loading and playing them (also using the SFML library, but I found that sometimes the buffer destroys itself)

#### Board
  A barebones structure encapsulated in a class, with method for asigning a determinate *color* to a *coordinate*, or retrieving the 
color value of a given coordinate.

#### Tetrimino
  A simple entity that knows its name, *shape* (given by an array), and how to rotate itsef.

  In the game, there only exist one of each shape per session.




