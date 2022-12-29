//
// Created by seliaste on 12/14/22.
//

#include "AudioManager.h"

AudioManager::AudioManager() {
    Mix_OpenAudio( 44100, MIX_DEFAULT_FORMAT, 2, 2048 );
    music = Mix_LoadMUS("../resources/Seliaste - Monophonic.mp3");
}

void AudioManager::playMusic() {
    Mix_PlayMusic(music, -1);
}
