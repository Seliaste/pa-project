/**
 * @file graphics.h
 * @author WIECZOREK Thomas
 * @brief 
 * @version 0.1
 * @date 2022-10-26
 */
#ifndef GRAPHICS_H
#define GRAPHICS_H

#include "../logic/GameWorld.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

class GraphicsManager{
private:
    SDL_Renderer* renderer;
    SDL_Texture* background; /*!< Texture liée à l'image du fond de l'écran. */
    SDL_Texture* truck;
    TTF_Font* timefont;


public:
    explicit GraphicsManager(SDL_Window* window);

    /**
    * @brief charge une image à partir d'un fichier
    *
    * @param nomfichier
    * @return SDL_Texture*
    */
    SDL_Texture* load_image (const char* nomfichier);

    /**
     * @brief charge une image et rend le fond transparent à partir d'un fichier
     *
     * @param nomfichier
     * @param r
     * @param g
     * @param b
     * @return SDL_Texture*
     */
    SDL_Texture* load_transparent_image(const char* nomfichier,Uint8 r,Uint8 g,Uint8 b);


    /**
 * @brief efface les données graphiques
 *
 * @param resources
 */
    void clean_graphics();


/**
 *
 * @param namefile
 * @param image1
 * @param image2
 * @param image3
 */
    static void load_from_file(const char* namefile,const char* image1, const char* image2, const char* image3);

/**
 *@brief charge les images et les affiche
 * @return void
 */
    void display_images(GameWorld* world);

    void display_timer_text(GameWorld *world);

    void update_display(GameWorld *world);
};


#endif