//
// Created by seliaste on 11/16/22.
//

#include "EventManager.h"

EventManager::EventManager() {
    is_pressed = false;
    is_accelerating = false;
    is_quitting = false;
    is_braking = false;
    wants_to_restart = false;
    steeraxis = 0;
}

void EventManager::poll_events() {
    while (SDL_PollEvent(&events)) {
        if (events.key.repeat == 0) {
            switch (events.type) {
                case SDL_QUIT:
                    is_quitting = true;
                    break;
                case SDL_KEYDOWN:
                    switch (events.key.keysym.sym) {
                        case SDLK_ESCAPE:
                            is_quitting = true;
                            break;
                        case SDLK_q:
                            steeraxis += -1;
                            break;
                        case SDLK_d:
                            steeraxis += 1;
                            break;
                        case SDLK_z:
                            is_accelerating = true;
                            break;
                        case SDLK_s:
                            is_braking = true;
                            break;
                        case SDLK_r:
                            wants_to_restart = true;
                            break;
                    }
                    break;
                case SDL_KEYUP:
                    switch (events.key.keysym.sym) {
                        case SDLK_q:
                            steeraxis += 1;
                            break;
                        case SDLK_d:
                            steeraxis -= 1;
                            break;
                        case SDLK_z:
                            is_accelerating = false;
                            break;
                        case SDLK_s:
                            is_braking = false;
                            break;
                        case SDLK_r:
                            wants_to_restart = false;
                            break;
                    }
                case SDL_MOUSEBUTTONDOWN:
                    is_pressed = true;
                    break;
                case SDL_MOUSEBUTTONUP:
                    is_pressed = false;
                    break;
            }
        }
    }
}

bool EventManager::get_is_pressed() const {
    return this->is_pressed;
}

bool EventManager::get_is_accelerating() const {
    return this->is_accelerating;
}

bool EventManager::get_is_quitting() const {
    return this->is_quitting;
}

int EventManager::get_steering_axis() const {
    return this->steeraxis;
}

bool EventManager::get_is_braking() const {
    return this->is_braking;
}

bool EventManager::get_wants_to_restart() const {
    return wants_to_restart;
}
