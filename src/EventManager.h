//
// Created by seliaste on 11/16/22.
//

#ifndef PA_PROJECT_EVENTMANAGER_H
#define PA_PROJECT_EVENTMANAGER_H

#include <SDL2/SDL.h>

class EventManager {

private:
    SDL_Event events{};
    bool is_accelerating{};
    bool is_quitting{};
    int turnvalue{};

public:
    EventManager();
    void poll_events();
    bool get_is_accelerating();
    bool get_is_quitting();
};


#endif //PA_PROJECT_EVENTMANAGER_H
