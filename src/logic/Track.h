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
    // vector for scalability
    std::vector<std::vector<char>> track_array;
    Uint32 current_best;
public:
    /**
     * Constructor from a file
     * @param title name of the Track
     * @param file name of the file used to fill tab_track
     */
    Track(std::string title, const std::string &file);

    /**
     * Creates a 2d vector containing the characters from the file
     * @return vector of a char vector
     */
    void fillTab(const std::string &file_name);

    /**
     * Gets the size of the map in 2d
     * @return 2d integer vector for size
     */
    glm::ivec2 getSize();

    /**
     * Returns the type of the tile on the specified coordinates
     * @param x horizontal position
     * @param y vertical position
     * @return character representing the tile type
     */
    char getTileType(int x, int y);

    /**
     * gets the size of a single tile
     * @return size of tile in pixels
     */
    [[nodiscard]] int getTileSize() const;

    /**
     * @return the start coordinates (adjusted with tile size)
     */
    glm::ivec2 getStartPosition();

    /**
     * writes the laptime in the corresponding file
     * @param time_ms time of the lap in ms
     */
    void writeLap(Uint32 time_ms);

    /**
     * returns the best laptime from the corresponding file
     * @return time of the lap in ms
     */
    [[nodiscard]] Uint32 readBestTime();

    /**
     * returns the best laptime without accessing the file
     * @return time of the lap in ms
     */
    [[nodiscard]] Uint32 getBestTime() const;
};


#endif //PA_PROJECT_TRACK_H
