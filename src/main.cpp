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
#include "logic/GameWorld.h"
#include "graphics/GraphicsManager.h"
#include "EventManager.h"
#include "menu/Menu.h"

int main(int argc, char const *argv[])
{
    SDL_Window *window;  // Déclaration de la fenêtre
    if (SDL_Init(SDL_INIT_VIDEO) < 0) // Initialisation de la SDL
    {
        printf("Erreur d’initialisation de la SDL: %s", SDL_GetError());
        SDL_Quit();
        return EXIT_FAILURE;
    }
    // Créer la fenêtre
    window = SDL_CreateWindow("Fenetre SDL", SDL_WINDOWPOS_CENTERED,
                               SDL_WINDOWPOS_CENTERED, 1280, 720, 0);
    if (window == nullptr) // En cas d’erreur
    {
        printf("Erreur de la creation d’une fenetre: %s", SDL_GetError());
        SDL_Quit();
        return EXIT_FAILURE;
    }
    TTF_Init();
    auto* menu = new Menu();

    // menu->display_main_menu(window);

    auto* graphics = new GraphicsManager(window);

    auto* events = new EventManager();

    auto* world = new GameWorld();// initialisation des données
    Uint64 tmp;
    // Boucle principale
    while (!events->get_is_quitting())
    {
        tmp = SDL_GetTicks();
        events->poll_events();
        world->update_world(events);
        graphics->update_display(world);
        SDL_Delay( 17 - (SDL_GetTicks() - tmp) );
    }
    // clean des données
    graphics->clean_graphics();
    delete graphics;
    world->clear_game_data();
    delete world;
    delete events;
    delete menu;
    // Quitter SDL
    TTF_Quit();
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}

#endif
