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
    SDL_Renderer *renderer;
    TTF_Font *menu_font;
    EventManager *eventManager;
    SDL_Rect button{};
    SDL_Texture *tex_bg;
    int window_size_x{};
    int window_size_y{};

    // macro to display the background
    void display_menu_bg(SDL_Texture *texture_bg);

    // macro to display a menu text
    void display_menu_text(const char *text, int x, int y);

    // macro to display a menu button
    void display_button(const char *, int x, int y, TTF_Font *font);

    // checks if the start button has been pressed
    void start_game_button_check();

public:
    Menu(EventManager *events, SDL_Window *window);

    /**
     * @brief starts the main menu displaying loop. Doesnt stop until user has finished interacting
     */
    void display_main_menu();
};


#endif //PA_PROJECT_MENU_H
