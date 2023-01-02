//
// Created by totomas on 26/11/22.
//
#include <iostream>
#include <utility>
#include <vector>
#include <string>
#include <sstream>
#include <fstream>
#include "Track.h"

Track::Track(std::string title, const std::string &file,std::string img) {
    name = std::move(title);
    image = std::move(img);
    tile_size = 128;
    fillTab(file);
    current_best = readBestTime();
}

std::string Track::getName() const {
    return name;
}

std::string Track::getImage() const {
    return image;
}

void Track::fillTab(const std::string &file_name) {
    std::string line;
    char word;

    std::ifstream inFile(file_name);

    if (inFile) {
        while (getline(inFile, line, '\n')) {
            //create a temporary vector that will contain all the columns
            std::vector<char> tempVec;

            std::istringstream ss(line);

            //read char by char
            while (ss >> word) {
                //add the word to the temporary vector
                tempVec.push_back(word);
            }
            //now all the words from the current line has been added to the temporary vector
            this->track_array.emplace_back(tempVec);
        }
    } else {
        throw std::invalid_argument("Track file name does not correspond to an actual file");
    }
    inFile.close();
}

glm::ivec2 Track::getSize() {
    return {track_array[0].size(), track_array.size()};
}

int Track::getTileSize() const {
    return tile_size;
}

char Track::getTileType(int x, int y) {
    if (y >= 0 && y < track_array.size() && x >= 0 && x < track_array[y].size()) {
        return track_array[y][x];
    }
    return 'o';
}

glm::ivec2 Track::getStartPosition() {
    for (int y = 0; y < track_array.size(); y++) {
        for (int x = 0; x < track_array[y].size(); x++) {
            if (track_array[y][x] == 's') {
                return {x * tile_size, y * tile_size};
            }
        }
    }
    return {0, 0};
}

void Track::writeLap(Uint32 time_ms) {
    std::ofstream outfile;
    char filename[32];
    std::sprintf(filename, "../data/%s.txt", name.c_str());
    outfile.open(filename, std::ios_base::app);
    outfile << time_ms << std::endl;
    outfile.close();
    if (time_ms < current_best) {
        current_best = time_ms;
    }
}

Uint32 Track::readBestTime() {
    std::ifstream infile;
    char filename[32];
    std::sprintf(filename, "../data/%s.txt", name.c_str());
    infile.open(filename);
    std::string line;
    Uint32 bestTime = 100000;
    Uint32 time;
    // if file is empty will keep default value,
    // high enough to make the player understand that there is no valid lap yet
    while (getline(infile, line)) {
        time = std::stoi(line);
        if (time < bestTime) {
            bestTime = time;
        }
    }
    return bestTime;
}

Uint32 Track::getBestTime() const {
    return current_best;
}
