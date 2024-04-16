//
// Created by abiga on 2/23/2024.
//

#include "Player.h"

Player::Player() {
    fUserName="Abi";
}
void Player::set_User_Name(string pUserName){
    fUserName=pUserName;
}

string Player::get_User_Name(){
    return fUserName;
}
void Player::set_Password(std::string pPassword) {
    fPassword=pPassword;
}

string Player::get_Password() {
    return fPassword;
}
bool Player::is_Valid(std::string pAny) {

    for (char c : pAny) {
        if (std::isblank(c)) {
            cout<<"Cannot Enter Spaces"<<endl;
            return false; // If any character is a space, return false
        }
        if(pAny.length()>20){
            cout<<"Input too, long please enter 20 characters max: ";
        }
    }
    if(pAny==""){
        return false;
    }
    return true; // If no spaces found, return true
}
void Player::player_Stats(string pUser) {
    string file="../"+pUser+".csv";
    ifstream inFile(file);
    string line;
    //stackoverflow.com/questions/11719538/how-to-use-stringstream-to-separate-comma-separated-strings to print in columns
    cout<<""<<endl;
    cout<<pUser+" Stats"<<endl;
    cout<<""<<endl;
    while (getline(inFile, line)) {
        // Use a stringstream to split the line into columns
        istringstream iss(line);
        string column;

        // Iterate over columns and print each one
        while (getline(iss, column, ',')) {
            cout << column << " ";
        }
        cout << endl;
    }
    inFile.close();
    cout<<""<<endl;
}
void Player::write_Stats(string pGame, string pLevel, double pTime, string pUser) {
    string file="../"+pUser+".csv";
    ofstream outFile;
    outFile.open(file, std::ios::app);
    outFile << pGame<< ',' << pLevel << ',' << pTime << endl;
    outFile.close();
}