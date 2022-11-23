#include "GraphicsManager.h"


GraphicsManager(SDL_Window* window ){
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    SDL_Texture* background = load_image("../resources/road.bmp");
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
void GraphicsManager::load_from_file(const char* namefile, const char* image1, const char* image2, const char* image3){
    FILE* file = fopen(namefile,"r");
    char str[100] = "";
    if(file!= NULL){
        while(fgets(str,100,file)!= NULL){
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
void GraphicsManager::display_images(GameWorld* world){
    SDL_Point size;
    SDL_Rect SrcR;
    SrcR.x = 0;
    SrcR.y = 0;
    SDL_QueryTexture(truck,NULL,NULL,&size.x,&size.y);
    SrcR.w = size.x;
    SrcR.h = size.y;
    SDL_Rect DestR;
    DestR.x = ceil(-world->getPlayerCar()->get_pos_x());
    DestR.y = ceil(world->getPlayerCar()->get_pos_y());
    DestR.w = size.x;
    DestR.h = size.y;
    SDL_RenderCopy(renderer, background, NULL, NULL);
    SDL_RenderCopy(renderer, truck, &SrcR , &DestR);
}