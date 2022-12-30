//
// Created by totomas on 30/12/22.
//

#ifndef PA_PROJECT_TRACKMENU_H
#define PA_PROJECT_TRACKMENU_H

#include <SDL2/SDL.h>
#include <SDL_ttf.h>
#include "../EventManager.h"
#include "Menu.h"
#include <string>
#include <list>
class TrackMenu{
private:
    Menu *menu;
    std::list<std::string> track_names;
    std::list<std::string> track_files;
    std::list<std::string> track_images;

public:
    TrackMenu(Menu* menu);
    void displayTrackSelection();
};
#endif //PA_PROJECT_TRACKMENU_H
