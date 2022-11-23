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
void GraphicsManager::load_from_file(const char* namefile, const char* image1, const char* image2, const char* image3){
    FILE* file = fopen(namefile,"r");
    char str[100] = "";
    if(file != nullptr){
        while(fgets(str,100,file) != nullptr){
            for (int i=0; i < strlen(str); i++) {
                if (strcmp(str, "X") == 0) {
                    printf("y a un X");
                    //load_image(image1,renderer);
                }
            }
        }
    }
    fclose(file);
}

void GraphicsManager::update_display(GameWorld* world){
    display_images(world);
    display_text(world);
    SDL_RenderPresent(renderer);
}

void GraphicsManager::display_text(GameWorld* world){
    SDL_Color color = { 255, 255, 255 };
    int ticks = SDL_GetTicks();
    char timing_string[20];
    sprintf(timing_string, "%d:%d", ticks/1000,SDL_GetTicks()%1000/10);
    SDL_Surface * surface = TTF_RenderText_Solid(timefont, timing_string, color);
    SDL_Texture * texture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_Rect dstrect = { 0, 0, 200, 60 };
    SDL_RenderCopy(renderer, texture, nullptr, &dstrect);


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
}