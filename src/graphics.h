/**
 * @file graphics.h
 * @author WIECZOREK Thomas
 * @brief 
 * @version 0.1
 * @date 2022-10-26
 */
#ifndef GRAPHICS_H
#define GRAPHICS_H

#include "game_logic.h"
#include <SDL2/SDL.h>

typedef struct resources_s
{
    SDL_Texture *background; /*!< Texture liée à l'image du fond de l'écran. */
} resources_t;

void init_graphics(SDL_Renderer *renderer, resources_t *resources);
void clean_graphics(resources_t *resources);
void apply_background(SDL_Renderer *renderer, resources_t *resources);

#endif