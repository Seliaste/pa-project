#ifndef MAIN_CPP
#define MAIN_CPP

#include <iostream>
#include <SDL2/SDL.h>

int main(int argc, char const *argv[])
{
    SDL_Window *fenetre;  // Déclaration de la fenêtre
    SDL_Event evenements; // Événements liés à la fenêtre
    bool terminer = false;
    if (SDL_Init(SDL_INIT_VIDEO) < 0) // Initialisation de la SDL
    {
        printf("Erreur d’initialisation de la SDL: %s", SDL_GetError());
        SDL_Quit();
        return EXIT_FAILURE;
    }
    // Créer la fenêtre
    fenetre = SDL_CreateWindow("Fenetre SDL", SDL_WINDOWPOS_CENTERED,
                               SDL_WINDOWPOS_CENTERED, 600, 600, SDL_WINDOW_RESIZABLE);
    if (fenetre == NULL) // En cas d’erreur
    {
        printf("Erreur de la creation d’une fenetre: %s", SDL_GetError());
        SDL_Quit();
        return EXIT_FAILURE;
    }
    SDL_Renderer* ecran = SDL_CreateRenderer(fenetre, -1, SDL_RENDERER_ACCELERATED);
    // Boucle principale
    while (!terminer)
    {
        SDL_PollEvent(&evenements);
        switch (evenements.type)
        {
        case SDL_QUIT:
            terminer = true;
            break;
        case SDL_KEYDOWN:
            switch (evenements.key.keysym.sym)
            {
            case SDLK_ESCAPE:
            case SDLK_q:
                terminer = true;
                break;
            }
        }
        SDL_RenderPresent(ecran);
    }
    // Quitter SDL
    SDL_DestroyWindow(fenetre);
    SDL_Quit();
    return 0;
}

#endif
