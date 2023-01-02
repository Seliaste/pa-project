//
// Created by seliaste on 11/16/22.
//

#ifndef PA_PROJECT_EVENTMANAGER_H
#define PA_PROJECT_EVENTMANAGER_H

#include <SDL2/SDL.h>

class EventManager {

private:
    SDL_Event events{};
    bool wants_to_restart;
    bool is_pressed;
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
     * has the mouse button been pressed
     * @return
     */
    [[nodiscard]] bool get_is_pressed() const;

    /**
     * @brief Is the acceleration key pressed
     *
     * @return true if the acceleration event is happening
     */
    [[nodiscard]] bool get_is_accelerating() const;

    /**
     * @brief Is the braking key pressed
     *
     * @return true if the braking event is happening
     */
    [[nodiscard]] bool get_is_braking() const;

    /**
     * @brief Has a quitting event been received
     *
     * @return true if the quitting should happen
     */
    [[nodiscard]] bool get_is_quitting() const;

    /**
     * @brief Has a restart event been triggered
     *
     * @return true if the user wants to restart (AkA reset the car)
     */
    [[nodiscard]] bool get_wants_to_restart() const;

    /**
     * @brief Returns the steering axis
     *
     * @return an int between -1 and 1.
     * NOTE: THIS COULD BE CHANGED TO A FLOAT TO ALLOW PARTIAL STEERING,
     * for example a gamepad. Will try to implement later
     */
    [[nodiscard]] int get_steering_axis() const;

    void declareMouseClickRegistered();
};


#endif //PA_PROJECT_EVENTMANAGER_H
