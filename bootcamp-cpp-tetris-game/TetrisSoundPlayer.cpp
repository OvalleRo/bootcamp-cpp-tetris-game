#include "TetrisSoundPlayer.h"



TetrisSoundPlayer::TetrisSoundPlayer()
{
  backgroundMusic.openFromFile(BACKGROUND_MUSIC_DIR);
  if (!backgroundMusic.openFromFile(BACKGROUND_MUSIC_DIR)) {
    soundsLoaded = false;
    return;
  }
  backgroundMusic.setLoop(true);

  
  if (!lineCompletedSoundBuffer.loadFromFile(LINE_DIR)) {
    soundsLoaded = false;
    return;
  }
  lineCompletedSound.setBuffer(lineCompletedSoundBuffer);

  if (!tetriminoCollisionSoundBuffer.loadFromFile(COLLISION_DIR)) {
    soundsLoaded = false;
    return;
  }
  tetriminoCollisionSound.setBuffer(tetriminoCollisionSoundBuffer);
  tetriminoCollisionSound.setVolume(COLLISION_VOLUME);
  soundsLoaded = true;
}


TetrisSoundPlayer::~TetrisSoundPlayer()
{
}

void TetrisSoundPlayer::switchBackgroundMusicStatus(GameStatus status)
{
  switch (status)
  {
  case OVER:
  case PAUSED:
    backgroundMusic.setVolume(MUSIC_VOLUME / 2);
    break;
  case PLAYING:
    backgroundMusic.setVolume(MUSIC_VOLUME);
    if (backgroundMusic.getStatus() != sf::SoundSource::Status::Playing) {
      backgroundMusic.play();
    }
  default:
    break;
  }
}

void TetrisSoundPlayer::lineCompleted()
{
  lineCompletedSound.play();
}

void TetrisSoundPlayer::tetriminoCollision()
{
  tetriminoCollisionSound.play();
}

bool TetrisSoundPlayer::soundsLoadedCorrectly()
{
  return soundsLoaded;
}

