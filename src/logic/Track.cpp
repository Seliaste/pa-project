//
// Created by totomas on 26/11/22.
//
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <fstream>
#include "Track.h"

Track::Track(std::string title, std::string file){
    name = title;
    file_name = file;
}

std::vector<std::vector<char>> Track::fill_tab() const{
    std::string line;
    char word;

    std::ifstream inFile(this->file_name);

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
        std::cout<<"file cannot be opened"<<std::endl;
    }
    inFile.close();
    return tab_track;
}
