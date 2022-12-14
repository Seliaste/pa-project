/**
 * @file main.cpp
 * @author Aéna Aria (aena.aria2@etu.univ-lorraine.fr)
 * @brief Main executable file
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
#include "menu/TrackMenu.h"
#include "audio/AudioManager.h"

int main() {

    // -- INITIALISATIONS --

    // SDL Initialization
    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) < 0)
    {
        std::cout << "SDL initialization error: " << SDL_GetError() << std::endl;
        SDL_Quit();
        return EXIT_FAILURE;
    }

    // Creating the window
    SDL_Window *window = SDL_CreateWindow("Initial C", SDL_WINDOWPOS_CENTERED,
                              SDL_WINDOWPOS_CENTERED, 1280, 720, SDL_WINDOW_FULLSCREEN_DESKTOP);
    if (window == nullptr)
    {
        std::cout << "Window creation error :" << SDL_GetError() << std::endl;
        SDL_Quit();
        return EXIT_FAILURE;
    }

    TTF_Init(); // for displaying text

    auto *events = new EventManager();  // will gather SDL inputs and events

    auto *audio = new AudioManager();
    audio->playMusic(); // Plays main game music

    auto *menu = new Menu(events, window);
    menu->displayMainMenu();
    // whats is written below won't run before the menu has finished displaying
    auto *track_selection_menu = new Menu(events,window);
    auto *track_selector = new TrackMenu(track_selection_menu);
    track_selector->displayTrackSelection();
    auto *graphics = new GraphicsManager(window);

    auto *world = new GameWorld(track_selector); // Initializes game data

    // Useful for frame limiter calculation
    Uint64 tmp;
    Uint64 toWait;


    // -- MAIN GAME LOOP --
    while (!events->get_is_quitting()) {
        tmp = SDL_GetTicks();

        // 3-steps game loop: events gathering, world data updating, and displaying.
        events->poll_events();
        world->updateWorld(events);
        graphics->updateDisplay(world);

        toWait = 17 - (SDL_GetTicks() - tmp);
        SDL_Delay(toWait <= 17 ? toWait : 0);   // delays to framelimit to ~60fps
    }


    // -- DATA CLEANUP --
    graphics->cleanGraphics();
    world->clearGameData();
    menu->cleanMenuResources();
    track_selection_menu->cleanMenuResources();
    track_selector->cleanResources();
    delete graphics;
    delete world;
    delete events;
    delete menu;
    delete track_selection_menu;
    delete track_selector;
    delete audio;
    // Quitter SDL
    TTF_Quit();
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}

#endif
