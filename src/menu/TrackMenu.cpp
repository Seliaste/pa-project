//
// Created by totomas on 30/12/22.
//
#include "TrackMenu.h"
#include <iostream>
#include <SDL_image.h>
#include <queue>
TrackMenu::TrackMenu(Menu* track_menu){
    menu = track_menu;
    std::queue<Track*> track_queue;
    fillLists();
}

const std::queue<Track *> &TrackMenu::getTrackQueue() const {
    return track_queue;
}

void TrackMenu::fillLists() {
    Track* indianapolis = new Track("Indianapolis Superspeedway","../resources/track1.txt","../resources/indianapolis.png");
    track_queue.push(indianapolis);
    Track* monza = new Track("Autodromo Nazionale di Monza","../resources/track2.txt","../resources/monza.png");
    track_queue.push(monza);

}

void TrackMenu::displayArrowButton(int x,int y) {
    SDL_Surface *surface = IMG_Load("../resources/arrow.png");
    tex_arrow = SDL_CreateTextureFromSurface(menu->getRenderer(), surface);
    SDL_Rect dstrect = {x - (surface->w / 5), y, surface->w/5, surface->h/5};
    this->button_arrow = dstrect;
    SDL_RenderCopy(menu->getRenderer(), tex_arrow, nullptr, &dstrect);
    SDL_DestroyTexture(tex_arrow);
    SDL_FreeSurface(surface);
}
void TrackMenu::displayTrackSelection(){
    SDL_Color color = {0, 0, 0};
    SDL_Surface *surface = IMG_Load(track_queue.front()->getImage());
    menu->setTexBg(SDL_CreateTextureFromSurface(menu->getRenderer(), surface));
    SDL_FreeSurface(surface);
    while (menu->isKeepDisplaying()) {
        menu->getEventManager()->poll_events();
        menu->displayMenuBg(menu->getTexBg());
        menu->displayMenuText("CHOOSE YOUR TRACK", menu->getWindowSizeX() / 2, 64,color);
        menu->displayButton("START", menu->getWindowSizeX() / 2, menu->getWindowSizeY()*0.9, TTF_OpenFont("../resources/fonts/Facon.ttf", 64),color);
        displayArrowButton(menu->getWindowSizeX(), menu->getWindowSizeY()/2);
        SDL_RenderPresent(menu->getRenderer());
        menu->setKeepDisplaying(!menu->getEventManager()->get_is_quitting());
        menu->startGameButtonCheck();
        trackPickCheck();
    }
}
void TrackMenu::trackPickCheck() {
    int pos_x, pos_y;
    if (menu->getEventManager()->get_is_pressed()) {
        SDL_GetMouseState(&pos_x, &pos_y);
        if ((button_arrow.x < pos_x && pos_x < button_arrow.x + button_arrow.w) && (button_arrow.y < pos_y && pos_y < button_arrow.y + button_arrow.h)) {
            SDL_DestroyTexture(menu->getTexBg());
            track_queue.push(track_queue.front());
            track_queue.pop();
            SDL_Surface *surface = IMG_Load(track_queue.front()->getImage());
            menu->setTexBg(SDL_CreateTextureFromSurface(menu->getRenderer(), surface));
            SDL_FreeSurface(surface);

        }
    }
}