#include "GraphicsManager.h"


GraphicsManager::GraphicsManager(SDL_Window* window){
    TTF_Init();
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    background = load_image("../resources/road.bmp");
    truck = load_transparent_image("../resources/trashmaster.bmp",255,255,255);
    timefont = TTF_OpenFont("../resources/fonts/ShareTechMono-Regular.ttf", 64);
}

void GraphicsManager::clean_graphics()
{
    SDL_DestroyTexture(this->background);
    SDL_DestroyTexture(this->truck);
    TTF_CloseFont(timefont);
    TTF_Quit();
}

SDL_Texture* GraphicsManager::load_image (const char* nomfichier){
    SDL_Surface* surface = SDL_LoadBMP(nomfichier);
    SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer,surface);
    return texture;
}
SDL_Texture* GraphicsManager::load_transparent_image(const char* nomfichier,Uint8 r,Uint8 g,Uint8 b){
        SDL_Surface* surface = SDL_LoadBMP(nomfichier);
        Uint32 code = SDL_MapRGB(surface->format,r,g,b);
        SDL_SetColorKey(surface,SDL_TRUE,code);
        SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer,surface);
        return texture;
}

void GraphicsManager::update_display(GameWorld* world){
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
    SDL_Rect dstrect = { 0, 0, 200, 60 };
    SDL_RenderCopy(renderer, texture, nullptr, &dstrect);


}

void GraphicsManager::add_images_to_renderer(GameWorld* world){
    SDL_Point size;
    SDL_Rect SrcR;
    SrcR.x = 0;
    SrcR.y = 0;
    SDL_QueryTexture(truck,nullptr,nullptr,&size.x,&size.y);
    SrcR.w = size.x;
    SrcR.h = size.y;
    SDL_Rect DestR;
    DestR.x = ceil(-world->getPlayerCar()->get_pos_x());
    DestR.y = ceil(world->getPlayerCar()->get_pos_y());
    DestR.w = ceil(size.x/1.5);
    DestR.h = ceil(size.y/1.5);
    SDL_RenderCopy(renderer, background, nullptr, nullptr);
    SDL_RenderCopyEx(renderer, truck, &SrcR , &DestR,world->getPlayerCar()->get_rotation_degrees(), nullptr, SDL_FLIP_NONE);
}