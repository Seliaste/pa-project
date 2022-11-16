/**
 * @file game_logic.h
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
    void compute_logic(EventManager* events);
    void clear_game_data();

};

#endif