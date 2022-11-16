/**
 * @file game_logic.h
 * @author Aéna Aria (aena.aria2@etu.univ-lorraine.fr)
 * @brief Partie qui process les données de jeu
 * @date 2022-10-26
 */
#ifndef GAME_LOGIC_H
#define GAME_LOGIC_H

#include <SDL2/SDL.h>
#include "Car.h"
#include "EventManager.h"

typedef struct{
    Car* player;
} data_struct;

data_struct* init_game_data();

void compute_logic(data_struct* data, EventManager* events);

void clear_game_data(data_struct* data);

#endif