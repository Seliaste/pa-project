/**
 * @file main.cpp
 * @author Aéna Aria (aena.aria2@etu.univ-lorraine.fr)
 * @brief Fichier main exécutable
 * @date 2022-10-26
 */
#ifndef MAIN_CPP
#define MAIN_CPP

#include <iostream>
#include <SDL2/SDL.h>
#include "game_logic.h"
#include "graphics.h"

int main(int argc, char const *argv[])
{
    SDL_Window *window;  // Déclaration de la fenêtre
    SDL_Event events; // Événements liés à la fenêtre
    bool terminer = false;
    if (SDL_Init(SDL_INIT_VIDEO) < 0) // Initialisation de la SDL
    {
        printf("Erreur d’initialisation de la SDL: %s", SDL_GetError());
        SDL_Quit();
        return EXIT_FAILURE;
    }
    // Créer la fenêtre
    window = SDL_CreateWindow("Fenetre SDL", SDL_WINDOWPOS_CENTERED,
                               SDL_WINDOWPOS_CENTERED, 600, 600, SDL_WINDOW_RESIZABLE);
    if (window == nullptr) // En cas d’erreur
    {
        printf("Erreur de la creation d’une fenetre: %s", SDL_GetError());
        SDL_Quit();
        return EXIT_FAILURE;
    }
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

    data_struct* data = init_game_data();// initialisation des données
    Uint64 tmp;
    // Boucle principale
    while (!terminer)
    {
        tmp = SDL_GetTicks();
        SDL_PollEvent(&events);
        switch (events.type)
        {
        case SDL_QUIT:
            terminer = true;
            break;
        case SDL_KEYDOWN:
            switch (events.key.keysym.sym)
            {
            case SDLK_ESCAPE:
            case SDLK_q:
                terminer = true;
                break;
            }
        }
        compute_logic(data);
        display_images(renderer);
        SDL_RenderPresent(renderer);
        // SDL_Delay(0.17 - (SDL_GetTicks() - tmp) ); - not working yet
    }
    // clean des données
    clear_game_data(data);
    // Quitter SDL
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}

#endif
