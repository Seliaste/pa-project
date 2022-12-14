//
// Created by seliaste on 11/30/22.
//

#include "Menu.h"
#include <string>
#include <iostream>

Menu::Menu(EventManager* events ) {
    keep_displaying = true;
    menu_font = TTF_OpenFont("../resources/fonts/ShareTechMono-Regular.ttf",64);
    eventManager = events;

}

void Menu::display_main_menu(SDL_Window *window) {
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    int x;
    int y;
    SDL_GetWindowSize(window,&x,&y);

    while (keep_displaying)
    {
        eventManager->poll_events();
        display_menu_item("Initial C",x/2, 64);
        display_button("START",x/2, 256);
        SDL_RenderPresent(renderer);
        keep_displaying = !eventManager->get_is_quitting();
        start_game();
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

void Menu::display_button(const char* text,int x,int y){
    SDL_Color color = { 255, 255, 255 };
    SDL_Surface * surface = TTF_RenderText_Solid(menu_font, text, color);
    SDL_Texture * texture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_Rect dstrect = { x - (surface->w /2), y , surface->w, surface->h };
    this -> button = dstrect;
    SDL_RenderCopy(renderer, texture, nullptr, &dstrect);
    SDL_DestroyTexture(texture);
    SDL_FreeSurface(surface);
}
void Menu::start_game(){
    int pos_x,pos_y;
    if(eventManager -> get_is_pressed()){
        SDL_GetMouseState(&pos_x,&pos_y);
        if((button.x < pos_x && pos_x < button.x + button.w) && (button.y < pos_x && pos_y < button.y + button.h)){
            keep_displaying = false;
            SDL_DestroyRenderer(renderer);
        }
    }
}

