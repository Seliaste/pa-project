/**
 * @file GameWorld.h
 * @author Aéna Aria (aena.aria2@etu.univ-lorraine.fr)
 * @brief Partie qui process les données de jeu
 * @date 2022-10-26
 */
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

class GameWorld{
private:
    Car* player;
    Timer* lap_timer;
    Track* track;
    Trigger* startline;
    Trigger* checkpoints[3]{nullptr, nullptr, nullptr};
    bool validated[3]{false,false,false};

public:
    GameWorld();

    /**
     * @brief Updates the game world accordingly
     * @param events the EventManager to poll events from
     */
    void update_world(EventManager* events);

    /**
     * @brief Clears memory for dynamic objects
     */
    void clear_game_data();

    Timer* get_lap_timer();

    Car* getPlayerCar();

    Track* get_track();

    void init_checkpoints();

    void compute_checkpoint_updates();

    void try_validating_lap();
};

#endif