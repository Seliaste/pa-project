//
// Created by seliaste on 12/14/22.
//

#ifndef PA_PROJECT_AUDIOMANAGER_H
#define PA_PROJECT_AUDIOMANAGER_H

#include <SDL2/SDL_mixer.h>

class AudioManager {
    Mix_Music *music;
    Mix_Chunk *buttonclick;
    AudioManager();
};


#endif //PA_PROJECT_AUDIOMANAGER_H
