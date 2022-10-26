#ifndef MAIN_CPP
#define MAIN_CPP

#include <iostream>
#include <SDL2/SDL.h>


int main(int argc, char const *argv[])
{
    std::cout << "Hello world!\n";
    SDL_Init(SDL_INIT_VIDEO);
    return 0;
}

#endif
