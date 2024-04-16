//
// Created by abiga on 2/23/2024.
//

#include "Level.h"

Level::Level() {
    fLevel="";
}

string Level::get_Level() {
    return fLevel;
}
void Level::set_Level(int pLevel) {
    if(pLevel==1){
        fLevel="Easy";
    }
    else if(pLevel==2){
        fLevel="Medium";
    }
    else{
        fLevel="Hard";
    }
}
vector<string> Level::level_to_string(int pLevel) {

    // Create Vector strings of words to be guessed, level choice has their own lists
    // Levels will call set_level() in PlayGame class to set level selection
    vector<string> wordsList;

    if (pLevel==EASY){
        set_Level(pLevel);
        std::string easyList="../easyList.txt";
        wordsList=get_WordList(easyList);
        return wordsList;
    }
    else if (pLevel==MEDIUM){
        set_Level(pLevel);
        string mediumList="../mediumList.txt";
        wordsList=get_WordList(mediumList);
        return wordsList;
    }
    else{
        set_Level(pLevel);
        string hardList="../hardList.txt";
        wordsList=get_WordList(hardList);
       return wordsList;
    }

}
vector<string> Level::get_WordList(string &wordListType){
    string word;
    std::vector<string> words;
    // Read from the text file
    ifstream inFile;
    inFile.open(wordListType);
    string header;
    if (inFile) {
        getline(inFile, header);
    }
    while (inFile && inFile.peek() != EOF) {
        inFile >> word;
        words.push_back(word);
    }
    inFile.close();
    return words;
}
