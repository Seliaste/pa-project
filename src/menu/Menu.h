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
public:
    void setKeepDisplaying(bool keepDisplaying);

public:
    bool isKeepDisplaying() const;

    SDL_Renderer *getRenderer() const;

    TTF_Font *getMenuFont() const;

    EventManager *getEventManager() const;

    const SDL_Rect &getButton() const;

    SDL_Texture *getTexBg() const;

    int getWindowSizeX() const;

    int getWindowSizeY() const;

private:
    SDL_Renderer *renderer;
    TTF_Font *menu_font;
    EventManager *eventManager;
    SDL_Rect button{};
    SDL_Texture *tex_bg;
    int window_size_x{};
    int window_size_y{};
public:
    // macro to display the background
    void displayMenuBg(SDL_Texture *texture_bg);

    // macro to display a menu text
    void displayMenuText(const char *text, int x, int y);

    // macro to display a menu button
    void displayButton(const char *text, int x, int y, TTF_Font *font);

    // checks if the start button has been pressed
    void startGameButtonCheck();

    Menu(EventManager *events, SDL_Window *window);

    /**
     * @brief starts the main menu displaying loop. Doesnt stop until user has finished interacting
     */
    void displayMainMenu();

};


#endif //PA_PROJECT_MENU_H
