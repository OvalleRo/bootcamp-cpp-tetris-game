#include "TetrisGame.h"
#include <windows.h>


int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPTSTR lpCmdLine, int nCmdShow)
{
  TetrisGame game;
  
  game.startGame();

  return 0;
}