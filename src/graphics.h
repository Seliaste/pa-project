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

/**
 * @brief efface les données graphiques
 * 
 * @param resources 
 */
void clean_graphics(resources_t *resources);

/**
 * @brief charge une image à partir d'un fichier
 * 
 * @param nomfichier 
 * @param renderer 
 * @return SDL_Texture* 
 */
SDL_Texture* load_image (const char* nomfichier, SDL_Renderer* renderer);
/**
 * @brief charge une image et rend le fond transparent à partir d'un fichier
 * 
 * @param nomfichier 
 * @param renderer 
 * @param r 
 * @param g 
 * @param b 
 * @return SDL_Texture* 
 */
SDL_Texture* load_transparent_image(const char* nomfichier,SDL_Renderer* renderer,Uint8 r,Uint8 g,Uint8 b);


#endif