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
    SDL_Texture *bgtextroad;
    SDL_Texture *bgtextstart;
    SDL_Texture *bgtextcheck;
    SDL_Texture *bgtextgrass;
    SDL_Texture *bgtextsand;
    SDL_Texture *bgtexttree;
    SDL_Texture *car;
    TTF_Font *timefont;


public:
    explicit GraphicsManager(SDL_Window *window);

    /**
    * Loads a texture from a file
    *
    * @param file_name path to the file from the src folder
    * @return SDL_Texture* corresponding texture
    */
    SDL_Texture *loadBMPImage(const char *file_name);


    /**
     * @brief Cleans graphical data
     *
     */
    void cleanGraphics();

    /**
     * Adds images to screen
     * @param world
     */
    void addImagesToRenderer(GameWorld *world);

    /**
     * Adds the timer text to the screen
     * @param world
     */
    void addTimerTextToRenderer(GameWorld *world);

    /**
     * Refreshes the display
     * @param world
     */
    void updateDisplay(GameWorld *world);

    /**
     * Displays the track textures
     * @param world
     */
    void renderTrack(GameWorld *world);

    /**
     * Loads PNG files and creates a texture from it
     * @param file_name path to the file from the src folder
     * @return SDL_Texture* corresponding texture
     */
    SDL_Texture *loadPNGImage(const char *file_name);
};


#endif