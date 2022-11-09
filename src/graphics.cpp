#include "graphics.h"

void clear_resources(resources_t *resources)
{
    delete resources->background;
    delete resources;
}
SDL_Texture* load_image (const char* nomfichier, SDL_Renderer* renderer){
    SDL_Surface* surface = SDL_LoadBMP(nomfichier);
    SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer,surface);
    return texture;
}
SDL_Texture* load_transparent_image(const char* nomfichier,SDL_Renderer* renderer,Uint8 r,Uint8 g,Uint8 b){
        SDL_Surface* surface = SDL_LoadBMP(nomfichier);
        Uint32 code = SDL_MapRGB(surface->format,r,g,b);
        SDL_SetColorKey(surface,SDL_TRUE,code);
        SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer,surface);
        return texture;
}