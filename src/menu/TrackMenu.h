//
// Created by totomas on 30/12/22.
//

#ifndef PA_PROJECT_TRACKMENU_H
#define PA_PROJECT_TRACKMENU_H

#include <SDL2/SDL.h>
#include <SDL_ttf.h>
#include "../EventManager.h"
#include "Menu.h"
#include "../logic/Track.h"
#include <string>
#include <queue>

class TrackMenu {
private:
    Menu *menu;
    SDL_Rect right_arrow{};
    std::queue<Track *> track_queue;
    SDL_Texture *tex_arrow{};
    SDL_Rect button_arrow{};

    void fillLists();

public:
    explicit TrackMenu(Menu *menu);

    void displayTrackSelection();

    void displayArrowButton(int x, int y);

    void trackPickCheck();

    [[nodiscard]] std::queue<Track *> getTrackQueue() const;

    void cleanResources();
};

#endif //PA_PROJECT_TRACKMENU_H
