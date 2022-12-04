//
// Created by seliaste on 24/11/22.
//

#include "Timer.h"

Timer::Timer() {
    reset();
}

void Timer::reset() {
    lastResetTick = SDL_GetTicks64();
}

Uint32 Timer::get_current_time() const {
    return SDL_GetTicks() - lastResetTick;
}

void Timer::get_timer_string(char* str) const {
    Uint32 time = get_current_time();
    sprintf(str, "%u:%02u", time/1000,time%1000/10);
}
