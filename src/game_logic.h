/**
 * @file game_logic.h
 * @author Aéna Aria (aena.aria2@etu.univ-lorraine.fr)
 * @brief Partie qui process les données de jeu
 * @date 2022-10-26
 */
#ifndef GAME_LOGIC_H
#define GAME_LOGIC_H

#include <SDL2/SDL.h>

typedef struct {
    int pos_x;
    int pos_y;
    int rot;
} car;

typedef struct{
    car player;
} data_struct;

int compute_logic(SDL_Renderer* renderer);

#endif