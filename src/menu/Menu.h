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
    char* bg_file;
public:
    Menu(EventManager* events);
    void display_main_menu(SDL_Window* window);

    void display_menu_bg(SDL_Texture* texture_bg);

    void display_menu_item(const char *text, int x, int y);

    void display_button(const char*,int x,int y,TTF_Font* font);

    void start_game();
};


#endif //PA_PROJECT_MENU_H
