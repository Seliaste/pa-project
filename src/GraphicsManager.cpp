#include "GraphicsManager.h"


GraphicsManager::GraphicsManager(SDL_Window* window){
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    background = load_image("../resources/road.bmp");
    truck = load_transparent_image("../resources/trashmaster.bmp",255,255,255);
    //tabBg = load_from_file("../resources/track1.txt");
}

void GraphicsManager::clean_graphics()
{
    SDL_DestroyTexture(this->background);
    SDL_DestroyTexture(this->truck);
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
void GraphicsManager::load_from_file(const char* namefile){
    FILE* file = fopen(namefile,"r");
    char str[100] = "";
    char track[100] = "";
    int lines = 0;
    int columns = 0;
    if(file != nullptr){
        while(fgets(str,100,file) != nullptr){
            for (int i=0; i < strlen(str); i++) {
                char c = fgetc(file);
                track[i] = c;       //placer textures dans tab à 2 dimensions (avec switch) puis les rendercopy dans display_images
                lines+=1;
            }
            columns = strlen(str);
        }
    }
    fclose(file);

}
void GraphicsManager::display_images(GameWorld* world){
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
    DestR.w = size.x;
    DestR.h = size.y;
    SDL_RenderCopy(renderer, background, nullptr, nullptr);
    SDL_RenderCopyEx(renderer, truck, &SrcR , &DestR,world->getPlayerCar()->get_rotation_degrees(), nullptr, SDL_FLIP_NONE);
    SDL_RenderPresent(renderer);
}