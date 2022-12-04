#include "GraphicsManager.h"
#include <vector>
#include <iostream>
#include <SDL_image.h>
GraphicsManager::GraphicsManager(SDL_Window* window){
    IMG_Init(IMG_INIT_PNG);
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    bgtextroad = load_image("../resources/road.bmp");
    bgtextgrass = load_image("../resources/grass.bmp");
    car = load_png("../resources/pitstop_car_10.png");
    timefont = TTF_OpenFont("../resources/fonts/ShareTechMono-Regular.ttf", 64);

}

void GraphicsManager::clean_graphics()
{
    SDL_DestroyTexture(this->bgtextroad);
    SDL_DestroyTexture(this->bgtextgrass);
    SDL_DestroyTexture(this->car);
    TTF_CloseFont(timefont);
    SDL_DestroyRenderer(this->renderer);
}

SDL_Texture* GraphicsManager::load_image (const char* nomfichier){
    SDL_Surface* surface = SDL_LoadBMP(nomfichier);
    SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer,surface);
    SDL_FreeSurface(surface);
    return texture;
}
SDL_Texture* GraphicsManager::load_transparent_image(const char* nomfichier,Uint8 r,Uint8 g,Uint8 b){
        SDL_Surface* surface = SDL_LoadBMP(nomfichier);
        Uint32 code = SDL_MapRGB(surface->format,r,g,b);
        SDL_SetColorKey(surface,SDL_TRUE,code);
        SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer,surface);
        SDL_FreeSurface(surface);
        return texture;
}

SDL_Texture* GraphicsManager::load_png (const char* nomfichier){
    SDL_Surface* surface = IMG_Load(nomfichier);
    if(surface == NULL)
    {
        printf( "Unable to load image %s! SDL_image Error: %s\n", nomfichier, IMG_GetError() );
    }
    SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer,surface);
    SDL_FreeSurface(surface);
    return texture;
}

void GraphicsManager::update_display(GameWorld* world){
    SDL_RenderClear(renderer);
    render_track(world);
    add_images_to_renderer(world);
    add_timer_text_to_renderer(world);
    SDL_RenderPresent(renderer);
}

void GraphicsManager::add_timer_text_to_renderer(GameWorld* world){
    SDL_Color color = { 255, 255, 255 };
    char timer_string[20];
    world->get_lap_timer()->get_timer_string(timer_string);
    SDL_Surface * surface = TTF_RenderText_Solid(timefont, timer_string, color);
    SDL_Texture * texture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_Rect dstrect = { 0, 0, surface->w, surface->h };
    SDL_RenderCopy(renderer, texture, nullptr, &dstrect);
    SDL_DestroyTexture(texture);
    SDL_FreeSurface(surface);

}

void GraphicsManager::add_images_to_renderer(GameWorld* world){
    SDL_Point size;
    SDL_Rect SrcR;
    SrcR.x = 0;
    SrcR.y = 0;
    SDL_QueryTexture(car, nullptr, nullptr, &size.x, &size.y);
    SrcR.w = size.x;
    SrcR.h = size.y;
    SDL_Rect DestR;
    DestR.x = ceil(world->getPlayerCar()->get_pos_x()-floor(size.x/2));
    DestR.y = ceil(world->getPlayerCar()->get_pos_y()-floor(size.y/2));
    DestR.w = ceil(size.x);
    DestR.h = ceil(size.y);
    //SDL_RenderCopy(renderer, background, nullptr, nullptr);
    SDL_RenderCopyEx(renderer, car, &SrcR , &DestR, world->getPlayerCar()->get_rotation_degrees(), nullptr, SDL_FLIP_NONE);
}
void GraphicsManager::render_track(GameWorld* world) {
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
    Track* track = world->get_track();
    SDL_Texture* texture;
    glm::ivec2 size = track->get_size();
    int tile_size = track->get_tile_size();
    for (int row = 0; row < size.y; row++) {
        for (int col = 0; col<size.x; col++) {
            if (track->get_tile_type(col,row) == 'o') {
                texture = bgtextgrass;
            }
            else {
                texture = bgtextroad;
            }
                DestR.x = col * tile_size;
                DestR.y = row * tile_size;
                DestR.w = tile_size;
                DestR.h = tile_size;
                SDL_RenderCopy(renderer, texture, &SrcR, &DestR);

        }
    }
}