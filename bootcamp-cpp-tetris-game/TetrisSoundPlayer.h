#pragma once
#include "SFML\Audio.hpp"
#include "GameStatus.h"
class TetrisSoundPlayer
{
private:
  sf::Music backgroundMusic;
  sf::SoundBuffer lineCompletedSoundBuffer, tetriminoCollisionSoundBuffer;
  sf::Sound lineCompletedSound, tetriminoCollisionSound;
  const char * BACKGROUND_MUSIC_DIR = "./resources/sounds/background_music.ogg";
  const char * LINE_DIR = "./resources/sounds/line.wav";
  const char * COLLISION_DIR = "./resources/sounds/collision_thud.wav";
  const float MUSIC_VOLUME = 40.f;
  const float COLLISION_VOLUME = 50.f;
  bool soundsLoaded;

public:
  TetrisSoundPlayer();
  ~TetrisSoundPlayer();

  //Starts playing if stopped, resumes if paused, pauses if playing
  void switchBackgroundMusicStatus(GameStatus status);
  void lineCompleted();
  void tetriminoCollision();

  bool soundsLoadedCorrectly();

};

