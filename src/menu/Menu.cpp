//
// Created by seliaste on 11/30/22.
//

#include "Menu.h"
#include <string>

Menu::Menu() {
    keep_displaying = true;
    menu_font = TTF_OpenFont("../resources/fonts/ShareTechMono-Regular.ttf",64);
}

void Menu::display_main_menu(SDL_Window *window) {
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    int x;
    int y;
    SDL_GetWindowSize(window,&x,&y);

    while (keep_displaying)
    {
        display_menu_item("uwu",x/2, 64);
        SDL_RenderPresent(renderer);
    }
}

void Menu::display_menu_item(const char* text,int x,int y){
    SDL_Color color = { 255, 255, 255 };
    SDL_Surface * surface = TTF_RenderText_Solid(menu_font, text, color);
    SDL_Texture * texture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_Rect dstrect = { x - (surface->w /2), y , surface->w, surface->h };
    SDL_RenderCopy(renderer, texture, nullptr, &dstrect);
    SDL_DestroyTexture(texture);
    SDL_FreeSurface(surface);

}

