#include "GraphicsManager.h"
#include <SDL_image.h>
#include <random>

GraphicsManager::GraphicsManager(SDL_Window *window) {
    IMG_Init(IMG_INIT_PNG);
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    bgtextroad = loadBMPImage("../resources/road.bmp");
    bgtextstart = loadBMPImage("../resources/start.bmp");
    bgtextcheck = loadBMPImage("../resources/check.bmp");
    bgtextgrass = loadPNGImage("../resources/grass.png");
    bgtextsand = loadPNGImage("../resources/sand.png");
    bgtexttree = loadPNGImage("../resources/tree_bushes.png");
    car = loadPNGImage("../resources/pitstop_car_10.png");
    timefont = TTF_OpenFont("../resources/fonts/ShareTechMono-Regular.ttf", 32);

}

void GraphicsManager::cleanGraphics() {
    SDL_DestroyTexture(this->bgtextroad);
    SDL_DestroyTexture(this->bgtextgrass);
    SDL_DestroyTexture(this->car);
    TTF_CloseFont(timefont);
    SDL_DestroyRenderer(this->renderer);
}

SDL_Texture *GraphicsManager::loadBMPImage(const char *file_name) {
    SDL_Surface *surface = SDL_LoadBMP(file_name);
    SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_FreeSurface(surface);
    return texture;
}

SDL_Texture *GraphicsManager::loadPNGImage(const char *file_name) {
    SDL_Surface *surface = IMG_Load(file_name);
    if (surface == nullptr) {
        printf("Unable to load image %s! SDL_image Error: %s\n", file_name, IMG_GetError());
    }
    SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_FreeSurface(surface);
    return texture;
}

void GraphicsManager::updateDisplay(GameWorld *world) {
    SDL_RenderClear(renderer);
    SDL_GetRendererOutputSize(renderer, &win_size_x, &win_size_y);
    renderTrack(world);
    addImagesToRenderer(world);
    addTimerTextToRenderer(world);
    SDL_RenderPresent(renderer);
}

void GraphicsManager::addTimerTextToRenderer(GameWorld *world) {
    SDL_Color color = {255, 255, 255};
    char curr_time[20];
    world->getLapTimer()->getTimerString(curr_time);
    char timer_string[80];
    Uint32 best = world->getTrack()->getBestTime();
    std::sprintf(timer_string, "Time: %s\nBest: %u:%02u", curr_time, best / 1000, best % 1000 / 10);
    SDL_Surface *surface = TTF_RenderText_Blended_Wrapped(timefont, timer_string, color, 1000);
    SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_Rect dstrect = {0, 0, surface->w, surface->h};
    SDL_RenderCopy(renderer, texture, nullptr, &dstrect);
    SDL_DestroyTexture(texture);
    SDL_FreeSurface(surface);

}

void GraphicsManager::addImagesToRenderer(GameWorld *world) {
    SDL_Point size;
    SDL_Rect SrcR;
    SrcR.x = 0;
    SrcR.y = 0;
    SDL_QueryTexture(car, nullptr, nullptr, &size.x, &size.y);
    SrcR.w = size.x;
    SrcR.h = size.y;
    SDL_Rect DestR;
    DestR.x = ceil(win_size_x / 2 - size.x / 2);
    DestR.y = ceil(win_size_y / 2 - size.y / 2);
    DestR.w = ceil(size.x);
    DestR.h = ceil(size.y);
    //SDL_RenderCopy(renderer, background, nullptr, nullptr);
    SDL_RenderCopyEx(renderer, car, &SrcR, &DestR, world->getPlayerCar()->getRotationDegrees(), nullptr,
                     SDL_FLIP_NONE);
}

void GraphicsManager::renderTrack(GameWorld *world) {
    SDL_Point size1;
    SDL_Point size2;
    SDL_Rect SrcR;
    SrcR.x = 0;
    SrcR.y = 0;
    SDL_QueryTexture(bgtextroad, nullptr, nullptr, &size1.x, &size1.y);
    SDL_QueryTexture(bgtextgrass, nullptr, nullptr, &size2.x, &size2.y);
    SrcR.w = size1.x;
    SrcR.h = size1.y;
    SDL_Rect DestR;
    Track *track = world->getTrack();
    SDL_Texture *texture;
    glm::ivec2 size = track->getSize();
    int tile_size = track->getTileSize();
    for (int row = 0; row < size.y; row++) {
        for (int col = 0; col < size.x; col++) {
            SDL_Texture *overlay = nullptr; // pour les arbres et petites décos
            switch (track->getTileType(col, row)) {
                case 's':
                    texture = bgtextstart;
                    break;
                case 'c':
                    texture = bgtextcheck;
                    break;
                case 'r':
                    texture = bgtextroad;
                    break;
                case 't':
                    texture = bgtextgrass;
                    overlay = bgtexttree;
                    break;
                case 'g':
                    texture = bgtextsand;
                    break;
                case 'o':
                default:
                    texture = bgtextgrass;
                    break;
            }
            DestR.x = floor((col * tile_size) - world->getPlayerCar()->getPosX() + ceil(win_size_x / 2));
            DestR.y = floor((row * tile_size) - world->getPlayerCar()->getPosY() + ceil(win_size_y / 2));
            DestR.w = tile_size;
            DestR.h = tile_size;
            SDL_RenderCopy(renderer, texture, &SrcR, &DestR);
            if (overlay != nullptr) {
                SDL_RenderCopy(renderer, overlay, &SrcR, &DestR);
            }
        }
    }
}