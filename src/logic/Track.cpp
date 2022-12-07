//
// Created by totomas on 26/11/22.
//
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <fstream>
#include "Track.h"

Track::Track(std::string title, const std::string& file){
    name = title;
    tile_size = 128;
    fill_tab(file);
}

void Track::fill_tab(const std::string& file_name){
    std::string line;
    char word;

    std::ifstream inFile(file_name);

    std::vector<std::vector<char>> tab_track;

    if(inFile)
    {
        while(getline(inFile, line, '\n'))
        {
            //create a temporary vector that will contain all the columns
            std::vector<char> tempVec;

            std::istringstream ss(line);

            //read char by char
            while(ss >> word)
            {
                //add the word to the temporary vector
                tempVec.push_back(word);
            }
            //now all the words from the current line has been added to the temporary vector
            tab_track.emplace_back(tempVec);
        }
    }
    else
    {
        throw std::invalid_argument("Track file name does not correspond to an actual file");
    }
    inFile.close();
    this->track_array = tab_track;
}

glm::ivec2 Track::get_size() {
    return {track_array[0].size(),track_array.size()};
}

int Track::get_tile_size() const{
    return tile_size;
}

char Track::get_tile_type(int x, int y) {
    if(y >= 0 && y<track_array.size() && x >= 0 && x < track_array[y].size()){
        return track_array[y][x];
    }
    return 'o';
}

glm::ivec2 Track::get_start_position() {
    for(int y = 0; y < track_array.size(); y++){
        for(int x = 0; x < track_array[y].size(); x++){
            if(track_array[y][x] == 's'){
                return {x*tile_size,y*tile_size};
            }
        }
    }
    return {0,0};
}

void Track::write_lap(Uint32 time_ms){
    std::ofstream outfile;
    char filename[32];
    std::sprintf(filename,"../data/%s.txt",name.c_str());
    outfile.open(filename, std::ios_base::app);
    outfile << time_ms << std::endl;
}