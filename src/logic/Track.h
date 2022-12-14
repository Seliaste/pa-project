//
// Created by totomas on 26/11/22.
//

#ifndef PA_PROJECT_TRACK_H
#define PA_PROJECT_TRACK_H

#include "glm/vec2.hpp"
#include <string>
#include <vector>
#include <SDL2/SDL.h>

class Track {
private:
    std::string name;
    int tile_size;
    std::vector<std::vector<char>> track_array;
    Uint32 current_best;
public:
    /**
     * Constructor from a file
     * @param title name of the Track
     * @param file name of the file used to fill tab_track
     */
    Track(std::string title, const std::string& file);

    /**
     * Creates a 2d vector containing the characters from the file
     * @return vector of a char vector
     */
     void fill_tab(const std::string& file_name);

     glm::ivec2 get_size();

     char get_tile_type(int x, int y);

     int get_tile_size() const;

     glm::ivec2 get_start_position();

    void write_lap(Uint32 time_ms);

    Uint32 read_best_time();

    Uint32 get_best_time();
};


#endif //PA_PROJECT_TRACK_H
