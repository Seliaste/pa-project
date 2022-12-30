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

Uint32 Timer::getCurrentTime() const {
    return SDL_GetTicks() - lastResetTick;
}

void Timer::getTimerString(char *str) const {
    Uint32 time = getCurrentTime();
    sprintf(str, "%u:%02u", time / 1000, time % 1000 / 10);
}
