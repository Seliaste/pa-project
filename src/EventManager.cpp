//
// Created by seliaste on 11/16/22.
//

#include "EventManager.h"

EventManager::EventManager() {
    is_accelerating = false;
    is_quitting = false;
    is_braking = false;
    steeraxis = 0;
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
                    is_quitting = true;
                    break;
                case SDLK_q:
                    steeraxis = 1;
                    break;
                case SDLK_d:
                    steeraxis = -1;
                    break;
                case SDLK_z:
                    is_accelerating = true;
                    break;
                case SDLK_s:
                    is_braking = true;
                    break;
            }
            break;
        case SDL_KEYUP:
            switch (events.key.keysym.sym)
            {
                case SDLK_q:
                case SDLK_d:
                    steeraxis = 0;
                    break;
                case SDLK_z:
                    is_accelerating = false;
                    break;
                case SDLK_s:
                    is_braking = false;
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

int EventManager::get_steering_axis() {
    return this->steeraxis;
}

bool EventManager::get_is_braking() {
    return  this->is_braking;
}