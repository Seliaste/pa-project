/**
 * @file GameWorld.h
 * @author Aéna Aria (aena.aria2@etu.univ-lorraine.fr)
 * @brief Partie qui process les données de jeu
 * @date 2022-10-26
 */
#ifndef PA_PROJECT_GAME_WORLD_H
#define PA_PROJECT_GAME_WORLD_H

#include <SDL2/SDL.h>
#include "Car.h"
#include "EventManager.h"

class GameWorld{
private:
    Car* player;
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

};

#endif