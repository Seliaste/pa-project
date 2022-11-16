//
// Created by seliaste on 11/16/22.
//

#include "EventManager.h"

EventManager::EventManager() {
    is_accelerating = false;
    is_quitting = false;
    turnvalue = 0;
}

void EventManager::poll_events() {
    SDL_PollEvent(&events);
    switch (events.type)
    {
        case SDL_QUIT:
            is_quitting = true;
            break;
        case SDL_KEYDOWN:
            switch (events.key.keysym.sym)
            {
                case SDLK_ESCAPE:
                case SDLK_q:
                    is_quitting = true;
                    break;
            }
    }
}

bool EventManager::get_is_accelerating() {
    return this->is_accelerating;
}

bool EventManager::get_is_quitting() {
    return this->is_quitting;
}
