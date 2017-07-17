#include "TetrisSoundPlayer.h"



TetrisSoundPlayer::TetrisSoundPlayer()
{
  backgroundMusic.openFromFile(BACKGROUND_MUSIC_DIR);
  backgroundMusic.setLoop(true);
}


TetrisSoundPlayer::~TetrisSoundPlayer()
{
}

void TetrisSoundPlayer::switchMusicStatus(GameStatus status)
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

