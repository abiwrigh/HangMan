//
// Created by abiga on 2/23/2024.
//

#ifndef M10EP_AWRIGH30_PLAYER_H
#define M10EP_AWRIGH30_PLAYER_H

#include <string>
#include <iostream>
#include <ostream>
#include <sstream>
#include <fstream>

using namespace std;

class Player{
private:
    string fPassword;
    string fUserName;


public:
    // constructor
    Player();

    // destructor
    ~Player()=default;
    /*
    * set username
    * Requires: string
    * Modifies: fUserName
    * Effects: sets private field username to be recorded for scoreboard
    */
    void set_User_Name(string pUserName);

    /*
    * get username
    * Requires: nothing
    * Modifies: nothing
    * Effects: returns private field username
    */
    string get_User_Name();
    /*
     * set password
     * Requires: string password
     * Modifies: fPassword
     * Effects: sets private field password to username
     */
    void set_Password(string pPassword);

    /*
     * get password
     * Requires: nothing
     * Modifies: nothing
     * Effects: returns private field time
     */
    string get_Password();

    /*
     * is Valid
     * Requires: string
     * Modifies: nothing
     * Effects: returns true if input is less than 20 characters and has no spaces
     */
    bool is_Valid(string pAny);

    /*
     * get player stats
     * Requires: nothing
     * Modifies: nothing
     * Effects: prints player stats
     */
    void player_Stats(string pUser);

    /*
     * write stats
     * Requires: string game, string level, double time
     * Modifies: adds new stats to txt file
     * Effects: takes the parameters and adds to users text file
     */
    void write_Stats(string pGame, string pLevel, double pTime, string pUser);



};


#endif //M10EP_AWRIGH30_PLAYER_H
