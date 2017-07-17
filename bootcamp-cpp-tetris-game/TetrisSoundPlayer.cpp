#include "TetrisSoundPlayer.h"



TetrisSoundPlayer::TetrisSoundPlayer()
{
  backgroundMusic.openFromFile(BACKGROUND_MUSIC_DIR);
  backgroundMusic.setLoop(true);

  lineCompletedSoundBuffer.loadFromFile(LINE_DIR);
  lineCompletedSound.setBuffer(lineCompletedSoundBuffer);

  tetriminoCollisionSoundBuffer.loadFromFile(COLLISION_DIR);
  tetriminoCollisionSound.setBuffer(tetriminoCollisionSoundBuffer);
  tetriminoCollisionSound.setVolume(COLLISION_VOLUME);
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

