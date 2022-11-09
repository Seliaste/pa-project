/**
 * @file game_logic.h
 * @author Aéna Aria (aena.aria2@etu.univ-lorraine.fr)
 * @brief Partie qui process les données de jeu
 * @date 2022-10-26
 */
#ifndef GAME_LOGIC_H
#define GAME_LOGIC_H

#include <SDL2/SDL.h>
#include "car.h"

typedef struct{
    car* player;
} data_struct;

data_struct* init_game_data();

int compute_logic(SDL_Renderer* renderer, data_struct* data);

void clear_game_data(data_struct* data);

#endif