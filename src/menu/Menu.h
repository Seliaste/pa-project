//
// Created by seliaste on 11/30/22.
//

#ifndef PA_PROJECT_MENU_H
#define PA_PROJECT_MENU_H

#include <SDL2/SDL.h>
#include <SDL_ttf.h>

class Menu {
private:
    bool keep_displaying;
    SDL_Renderer * renderer;
    TTF_Font* menu_font;
public:
    Menu();
    void display_main_menu(SDL_Window* window);

    void display_menu_item(const char *text, int x, int y);
};


#endif //PA_PROJECT_MENU_H
