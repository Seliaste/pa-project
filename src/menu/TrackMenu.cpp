//
// Created by totomas on 30/12/22.
//
#include "TrackMenu.h"
#include <iostream>
#include <SDL_image.h>

TrackMenu::TrackMenu(Menu* track_menu){
    menu = track_menu;
    std::list<std::string> track_names;
    std::list<std::string> track_files;
    std::list<std::string> track_images;

}
void TrackMenu::displayTrackSelection(){
    //créer liste de noms une d'images et une autre de fichier de circuits et incrementer de 1 à chaque clic de flèche modulo nb circuits
    while (menu->isKeepDisplaying()) {
        menu->getEventManager()->poll_events();
        menu->displayMenuBg(menu->getTexBg());
        menu->displayMenuText("CHOOSE YOUR TRACK", menu->getWindowSizeX() / 2, 64);
        menu->displayButton("START", menu->getWindowSizeX() / 2, 256, TTF_OpenFont("../resources/fonts/Facon.ttf", 64));
        SDL_RenderPresent(menu->getRenderer());
        menu->setKeepDisplaying(!menu->getEventManager()->get_is_quitting());
        menu->startGameButtonCheck();
    }
    SDL_DestroyTexture(menu->getTexBg());
}