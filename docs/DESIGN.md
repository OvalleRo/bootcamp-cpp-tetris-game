# A simple TETRIS game implementation

### __*A design proposal*__

This proposal is subject of review and __not__ final.
The idea is to update this file as soon as I make changes in the implementation.

 For the sake of simplicity, this design is roughly explained here. For more information, refer to the source documentation and the code itself.

 The game consists of the following major components:

 1. An __application__ module, that provides an interface between the user and the game. The idea behind this is the abstraction of the game and the platform running the game (targeting initially Windows machines); this way the door for porting the game is left wide open, if desired.
 1. A __game__ module. This one establishes the rules of the TETRIS game, controlling the __pieces or tetriminos__ in a __game board__, setting the conditions of the game to the player and the eventual defeat (you can't win here), keeping the scores.
 1. A __board__, with it's own logic for the pieces to interact with each other, providing a discreet and limited enviroment for the player to try not to lose.
 1. The __Tetriminos__ or Tetris game pieces, consisting each one of them of four parts that are created as a whole, but can be destroyed individually. The Tetriminos can be moved and rotated as long as they are not set in the board.

 ### __Possible classes (of each module)__

 Again, all of this is subject of change.

 #### Application
 * Option Menu (point of entrance)
 * App settings
 * Input receiver
 * ...

 #### Game
 * Dificulty Controller
 * Score keeper
 * Game logic (The tetris game itself - maybe too big?)
 * Tetriminos' controller (generation, movement, status...)
 * Board controller (Status of each position)

 #### Board
 * Line status and management
 * Collision control
 * ...

 #### Tetriminos
 * Types
 * Rotation
 * ...




