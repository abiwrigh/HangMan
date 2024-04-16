//
// Created by abiga on 2/23/2024.
//

#ifndef M10EP_AWRIGH30_DONT_BUILD_THE_MAN_H
#define M10EP_AWRIGH30_DONT_BUILD_THE_MAN_H

#include "PlayGame.h"
#include "Level.h"
class Dont_Build_The_Man : public PlayGame{

private:
    double fTime;
    Level level;

public:
    // constructor
    Dont_Build_The_Man();

    //destructor
    ~Dont_Build_The_Man() = default;

    /*
     * set time
     * Requires: double time
     * Modifies: fTime
     * Effects: sets private field time to be recorded for scoreboard
     */
    void set_Time(double pTime);

    /*
     * get time
     * Requires: nothing
     * Modifies: nothing
     * Effects: returns private field time
     */
    double get_Time();

    /*
     * get level
     * Requires: nothing
     * Modifies: nothing
     * Effects: returns private field level
     */
    static string get_Level(int pLevel);

    /*
     * Build Man
     * Requires: integer of numbers guessed wrong
     * Modifies: nothing
     * Effects: Based off of the numbers guessed wrong a body part character prints to the screen
     * resembling a man
     */
    static void build_Man(int pNumberGuessesWrong);

    /*
     * Character Validator
     * Requires: vector of chars of guesses wrong, vector of chars of guesses right, and string from user input
     * Modifies: Nothing
     * Effects: validates user input. If string is more than length of 1 returns false.
     * if char is already guessed either in guesses wrong vector of guesses right, return false.
     * else string is a valid character
     */
    static bool character_Validator(vector<char> pGuesses, vector<char> pGuessedRight, string pValidateInput);

    /*
    * Print Leaderboard
    * Requires: string pUser
    * Modifies: Nothing
    * Effects: Prints leader board of who guessed it right, or personal stats with username
    */
    static void print_Leaderboard(string pUser);

    /*
     * Play Game
     * Requires: ostream cout and string of a word to be guessed for game
     * Modifies: nothing
     * Effects: Creates vectors of char of guesses right and wrong. Creates vector of char buildWord
     * that starts as a placeholder for the characters to be guessed. Keeps track of guesses wrong.
     * If Guesses wrong=6 then returns false. If buildWord matches parameter word, returns true.
     */
    static bool play_Game(std::ostream &outs,string pWord);

    /*
     * Print Rules
     * Requires: ostream Outs
     * Modifies: nothing
     * Effects: Prints rules of the game.
     */
    static void print_rules(std::ostream &outs);

    /*
     * Get Level
     * Requires: ostream outs, istream ins
     * Modifies: integer of level
     * Effects: validates user input returns number that correlates with level selection
     */
    static int get_Level_Choice(std::ostream &outs,std::istream &ins);



    /*
     * Play Again
     * Requires: ostream outs and istream ins
     * Modifies: boolean option of playing again
     * Effects: validates user input to play again. If yes, return true. If no, return false.
     */
    static bool play_Again(std::ostream &outs,std::istream &ins);

    /*
     * Shuffle Words
     * Requires: vector of strings, words
     * Modifies: Vector of Ints, random integers
     * Effects: Takes the vector of strings length to create a vector of shuffled integers
     * of that size vector. Returns vector of integers that are randomized.
     */
    vector<int> shuffle_words(vector<string> &pWords);


};


#endif //M10EP_AWRIGH30_DONT_BUILD_THE_MAN_H
