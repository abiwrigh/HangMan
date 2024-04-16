//
// Created by abiga on 2/18/2024.
//
#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include <random>
#include <string>
#include <cctype>
#include <sstream>
using namespace std;

#ifndef M20EP_AWRIGH30_PLAYGAME_H
#define M20EP_AWRIGH30_PLAYGAME_H

#include "Player.h"

class PlayGame {

private:
    vector<Player> players;
    string fGame;

public:
    /*
    * Constructor to set PlayGame default variables are sent and
     * are intended to be overwritten
    */
    PlayGame();

    //destructor
    ~PlayGame() = default;

    /*
    * set game
    * Requires: string username, string password
    * Modifies: sets private field fGame
    * Effects: sets FGame
    */
    void set_Game(string pGame);

    /*
    * get game
    * Requires: nothing
    * Modifies: nothing
    * Effects: returns fGame;
    */
    string get_Game();


    /*
    * game Options
    * Requires: nothing
    * Modifies: nothing
    * Effects: returns bool true if user has a username with us false if they dont
    */
    bool game_User_Options();

    /*
    * check username
    * Requires: string username
    * Modifies: nothing
    * Effects: returns true if username is in vector false if not
    */
    bool check_Username(string pUsername);

    /*
    * read username file
    * Requires: nothing
    * Modifies: players vector
    * Effects: reads from a file and adds username and password to the Players vector
    */
    void read_Username_File();

    /*
    * add username
    * Requires: string username, string password
    * Modifies: adds player to Player vector
    * Effects: adds username and passport to file
    */
    void add_Username(string pUser,string pPassword);

    /*
    * game choice
    * Requires: nothing
    * Modifies: game choice title as string
    * Effects: prompts user for game selection then returns string of choice
    */
    string game_Choice();

    /*
    * get user  index
    * Requires: string username
    * Modifies: nothing
    * Effects: finds username and returns its index
    */
    int get_User_Index(string pUsername);

    /*
    * check password
    * Requires: integer index of username, and string password
    * Modifies: nothing
    * Effects: returns true if pPassword is at index of Username
    */
    bool check_Password(int pIndex, string pPassword);

};


#endif //M20EP_AWRIGH30_PLAYGAME_H
