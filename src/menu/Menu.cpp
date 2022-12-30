//
// Created by seliaste on 11/30/22.
//

#include "Menu.h"
#include <iostream>
#include <SDL_image.h>

Menu::Menu(EventManager *events, SDL_Window *window) {
    keep_displaying = true;
    menu_font = TTF_OpenFont("../resources/fonts/Xenogears.ttf", 64);
    eventManager = events;
    SDL_Surface *surface = IMG_Load("../resources/pitstop_car_10.png");
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if (surface == nullptr) {
        std::cout << "Unable to load image" << IMG_GetError() << std::endl;
    }
    tex_bg = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_FreeSurface(surface);
    SDL_GetWindowSize(window, &window_size_x, &window_size_y);
}

void Menu::displayMainMenu() {
    while (keep_displaying) {
        eventManager->poll_events();
        displayMenuBg(tex_bg);
        displayMenuText("Initial C", window_size_x / 2, 64);
        displayButton("START", window_size_x / 2, 256, TTF_OpenFont("../resources/fonts/Facon.ttf", 64));
        SDL_RenderPresent(renderer);
        keep_displaying = !eventManager->get_is_quitting();
        startGameButtonCheck();
    }
    SDL_DestroyTexture(tex_bg);
}

void Menu::displayMenuBg(SDL_Texture *texture_bg) {
    SDL_RenderCopy(renderer, texture_bg, nullptr, nullptr);
}

void Menu::displayMenuText(const char *text, int x, int y) {
    SDL_Color color = {255, 255, 255};
    SDL_Surface *surface = TTF_RenderText_Solid(menu_font, text, color);
    SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_Rect dstrect = {x - (surface->w / 2), y, surface->w, surface->h};
    SDL_RenderCopy(renderer, texture, nullptr, &dstrect);
    SDL_DestroyTexture(texture);
    SDL_FreeSurface(surface);

}

void Menu::displayButton(const char *text, int x, int y, TTF_Font *font) {
    SDL_Color color = {255, 255, 255};
    SDL_Surface *surface = TTF_RenderText_Solid(font, text, color);
    SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_Rect dstrect = {x - (surface->w / 2), y, surface->w, surface->h};
    this->button = dstrect;
    SDL_RenderCopy(renderer, texture, nullptr, &dstrect);
    SDL_DestroyTexture(texture);
    SDL_FreeSurface(surface);
}

void Menu::startGameButtonCheck() {
    int pos_x, pos_y;
    if (eventManager->get_is_pressed()) {
        SDL_GetMouseState(&pos_x, &pos_y);
        if ((button.x < pos_x && pos_x < button.x + button.w) && (button.y < pos_x && pos_y < button.y + button.h)) {
            keep_displaying = false;
            SDL_DestroyRenderer(renderer);
        }
    }
}

