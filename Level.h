//
// Created by abiga on 2/23/2024.
//

#ifndef M10EP_AWRIGH30_LEVEL_H
#define M10EP_AWRIGH30_LEVEL_H
#include <string>
#include <vector>
#include <fstream>
 using namespace std;
class Level {
private:

    // Player Choice of easy, medium, or hard word, call function for input
    enum LEVEL{EASY=1, MEDIUM=2, HARD=3};
    string fLevel;

public:
    // constructor
    Level();

    // destructor
    ~Level()=default;

    /*
     * get level
     * Requires: nothing
     * Modifies: nothing
     * Effects: returns level
     */
    string get_Level();

    /*
     * set level
     * Requires: int level
     * Modifies: takes level number
     * Effects: returns corresponding text from level number, 1=easy, 2=medium, 3=hard
     */
    void set_Level(int pLevel);

    /*
     * level to string
     * Requires: int level
     * Modifies: takes a level int
     * Effects: takes level, finds corresponding txt file, calls get_wordlist, sets level, and returns wordlist
     */
    vector<string> level_to_string(int pLevel);

    /*
     * Get Word List
     * Requires: string file name
     * Modifies: vector of strings to be outputted
     * Effects: Reads file line by line and adds string to vector. Returns vector once file is done.
     */
    vector<string> get_WordList(string &wordListType);

};


#endif //M10EP_AWRIGH30_LEVEL_H
