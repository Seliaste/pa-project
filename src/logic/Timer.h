//
// Created by seliaste on 24/11/22.
//

#ifndef PA_PROJECT_TIMER_H
#define PA_PROJECT_TIMER_H

#include <SDL2/SDL.h>

class Timer {
private:
    Uint64 lastResetTick = 0;
public:
    /**
     * @brief creates the timer and starts it
     */
    Timer();

    /**
     * @brief resets the timer to 0
     */
    void reset();

    /**
     * @return time since initialization/last reset
     */
    [[nodiscard]] Uint32 getCurrentTime() const;

    /**
     * @return a string in the format s:ms
     */
    void getTimerString(char *str) const;
};


#endif //PA_PROJECT_TIMER_H
