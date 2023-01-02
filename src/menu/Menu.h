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
    TTF_Font *menu_font_2;
    TTF_Font *menu_font;
    EventManager *eventManager;
    SDL_Rect button{};
    SDL_Texture *tex_bg;
    int window_size_x{};
    int window_size_y{};


public:
    void setKeepDisplaying(bool keepDisplaying);

    bool isKeepDisplaying() const;

    SDL_Renderer *getRenderer() const;

    EventManager *getEventManager() const;

    SDL_Texture *getTexBg() const;

    int getWindowSizeX() const;

    int getWindowSizeY() const;
    // macro to display the background
    void displayMenuBg(SDL_Texture *texture_bg);

    // macro to display a menu text
    void displayMenuText(const char *text, int x, int y,SDL_Color color);

    // macro to display a menu button
    void displayButton(const char *text, int x, int y, TTF_Font *font,SDL_Color color);

    // checks if the start button has been pressed
    void startGameButtonCheck();

    Menu(EventManager *events, SDL_Window *window);

    /**
     * @brief starts the main menu displaying loop. Doesnt stop until user has finished interacting
     */
    void displayMainMenu();

    void setTexBg(SDL_Texture *texBg);

    [[nodiscard]] TTF_Font *getMenuFont() const;

    void cleanMenuResources();
};


#endif //PA_PROJECT_MENU_H
