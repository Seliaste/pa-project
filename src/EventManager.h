//
// Created by seliaste on 11/16/22.
//

#ifndef PA_PROJECT_EVENTMANAGER_H
#define PA_PROJECT_EVENTMANAGER_H

#include <SDL2/SDL.h>

class EventManager {

private:
    SDL_Event events{};
    bool is_accelerating;
    bool is_quitting;
    bool is_braking;
    int steeraxis;

public:
    EventManager();

    /**
     * @brief Polls SDL events and changes the object fields accordingly
     */
    void poll_events();

    /**
     * @brief Is the acceleration key pressed
     *
     * @return true if the acceleration event is happening
     */
    bool get_is_accelerating() const;

    bool get_is_braking() const;

    /**
     * @brief Has a quitting event been received
     *
     * @return true if the quitting should happen
     */
    bool get_is_quitting() const;

    int get_steering_axis();
};


#endif //PA_PROJECT_EVENTMANAGER_H
