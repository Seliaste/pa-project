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

class GraphicsManager {
private:
    int win_size_x{};
    int win_size_y{};
    SDL_Renderer *renderer;
    SDL_Texture *bgtextroad; /*!< Textures liées à l'image du fond de l'écran. */
    SDL_Texture *bgtextgrass;
    SDL_Texture *bgtextsand;
    SDL_Texture *bgtexttree;
    SDL_Texture *car;
    TTF_Font *timefont;


public:
    explicit GraphicsManager(SDL_Window *window);

    /**
    * @brief charge une image à partir d'un fichier
    *
    * @param nomfichier
    * @return SDL_Texture*
    */
    SDL_Texture *load_image(const char *nomfichier);


    /**
 * @brief efface les données graphiques
 *
 * @param resources
 */
    void clean_graphics();

/**
 *@brief charge les images et les affiche
 * @return void
 */
    void add_images_to_renderer(GameWorld *world);

    void add_timer_text_to_renderer(GameWorld *world);

    void update_display(GameWorld *world);

    /**
     * Affiche les textures selon le fichier track
     * @param world
     */
    void render_track(GameWorld *world);

    SDL_Texture *load_png(const char *nomfichier);
};


#endif