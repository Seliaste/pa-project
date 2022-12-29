//
// Created by seliaste on 12/14/22.
//

#ifndef PA_PROJECT_AUDIOMANAGER_H
#define PA_PROJECT_AUDIOMANAGER_H

#include <SDL2/SDL_mixer.h>

class AudioManager {
private:
    Mix_Music *music;
public:
    AudioManager();
    void playMusic();
};


#endif //PA_PROJECT_AUDIOMANAGER_H
