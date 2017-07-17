#pragma once
#include "SFML\Audio.hpp"
#include "GameStatus.h"
class TetrisSoundPlayer
{
private:
  sf::Music backgroundMusic;
  const char * BACKGROUND_MUSIC_DIR = "./resources/sounds/background_music.ogg";
  const float MUSIC_VOLUME = 40.f;

public:
  TetrisSoundPlayer();
  ~TetrisSoundPlayer();

  //Starts playing if stopped, resumes if paused, pauses if playing
  void switchMusicStatus(GameStatus status);


};

