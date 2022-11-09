#include "graphics.h"

void clear_resources(resources_t *resources)
{
    SDL_free(resources -> background);
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
void display_images(SDL_Renderer* renderer){
    SDL_Texture* background = load_image("../resources/road.bmp", renderer);
    SDL_Texture* truck = load_transparent_image("../resources/trashmaster.bmp", renderer, 255, 255, 255);
    SDL_Point size;
    SDL_Rect SrcR;
    SrcR.x = 0;
    SrcR.y = 0;
    SDL_QueryTexture(truck,NULL,NULL,&size.x,&size.y);
    SrcR.w = size.x;
    SrcR.h = size.y;
    SDL_Rect DestR;
    DestR.x = 350;
    DestR.y = 350;
    DestR.w = size.x;
    DestR.h = size.y;
    SDL_RenderCopy(renderer, background, NULL, NULL);
    SDL_RenderCopy(renderer, truck, &SrcR , &DestR);
}