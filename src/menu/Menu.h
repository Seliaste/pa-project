//
// Created by seliaste on 11/30/22.
//

#ifndef PA_PROJECT_MENU_H
#define PA_PROJECT_MENU_H

#include <SDL2/SDL.h>
#include <SDL_ttf.h>
#include "../EventManager.h"

class Menu {
private:
    bool keep_displaying;
    SDL_Renderer * renderer;
    TTF_Font* menu_font;
    EventManager* eventManager;
    SDL_Rect button;
    SDL_Texture* tex_bg;
    int window_size_x;
    int window_size_y;
public:
    Menu(EventManager* events, SDL_Window *window);
    void display_main_menu();

    void display_menu_bg(SDL_Texture* texture_bg);

    void display_menu_item(const char *text, int x, int y);

    void display_button(const char*,int x,int y,TTF_Font* font);

    void start_game();
};


#endif //PA_PROJECT_MENU_H
