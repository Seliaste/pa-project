//
// Created by seliaste on 11/30/22.
//
#ifndef PA_PROJECT_GAME_WORLD_H
#define PA_PROJECT_GAME_WORLD_H

#include <SDL2/SDL.h>
#include <vector>
#include <string>
#include "Car.h"
#include "../EventManager.h"
#include "Timer.h"
#include "Track.h"
#include "Trigger.h"
#include "../menu/TrackMenu.h"

class GameWorld {
private:
    glm::ivec2 start_pos{};
    Car *player;
    Timer *lap_timer;
    Track *track;
    Trigger *startline;
    Trigger *checkpoints[3]{nullptr, nullptr, nullptr};
    bool validated[3]{false, false, false};

public:
    explicit GameWorld(TrackMenu* track_menu );

    /**
     * @brief Updates the game world accordingly
     * @param events the EventManager to poll events from
     */
    void updateWorld(EventManager *events);

    /**
     * @brief Clears memory for dynamic objects
     */
    void clearGameData();

    /**
     * @brief Resets time, checkpoints and places the car back at the starting line
     */
    void resetGame();

    /**
     * @return the lap Timer object
     */
    Timer *getLapTimer();

    /**
     * @return the player car
     */
    Car *getPlayerCar();

    /**
     * @return the track of the gameworld
     */
    Track *getTrack();

    /**
     * @brief creates the checkpoint objects and stores them in the cp array
     */
    void initCheckpoints();

    /**
     * @brief checks for collision in the checkpoints
     */
    void computeCheckpointUpdates();

    /**
     * @brief checks for lap validation
     */
    void tryValidatingLap();
};

#endif