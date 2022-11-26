//
// Created by totomas on 26/11/22.
//

#ifndef PA_PROJECT_TRACK_H
#define PA_PROJECT_TRACK_H


class Track {
private:
    std::string name;
    std::string file_name;
public:
    /**
     * Constructor from a file
     * @param title name of the Track
     * @param file name of the file used to fill tab_track
     */
    Track(std::string title, std::string file);

    /**
     * Creates a 2d vector containing the characters from the file
     * @return vector of a char vector
     */
    std::vector<std::vector<char>> fill_tab() const;
};


#endif //PA_PROJECT_TRACK_H
