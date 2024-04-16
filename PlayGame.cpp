//
// Created by abiga on 2/18/2024.
//

#include "PlayGame.h"

PlayGame::PlayGame(){
    fGame="example";
}

void PlayGame::set_Game(std::string pGame) {
    fGame=pGame;
}
string PlayGame::get_Game(){
    return fGame;
}

bool PlayGame::game_User_Options() {
    cout<<"Welcome to the Game Center!"<<endl;
    cout<<"Do you have an account with us?"<<endl;
    int accountOption;
    cout<<"Enter (1) to Enter Username (2) to Create Username"<<endl;
    while (!(cin >> accountOption)||(!(accountOption == 1 || accountOption == 2))){
        cout << "Invalid Input! Please Enter Integer (1) or (2)"<<endl;
        cin.clear();
        string junk;
        getline(cin, junk);
    }
    if(accountOption==1){
        return true;
    }
    else{
        cout << "Let's Get You Started!" << endl;
        return false;
    }
}
bool PlayGame::check_Username(std::string pUsername) {
    read_Username_File();
    for (int i=0;i<players.size();i++) {
        if (players[i].get_User_Name() == pUsername) {
            return true;
        }
    }
    return false;
}
void PlayGame::read_Username_File() {
    players.clear();
    // Open the file
    ifstream inFile("../users.txt");
    ifstream inFile2("../passwords.txt");
    // Read in the users and passwords
    Player p;
    string user;
    string password;

    while (inFile) {

        inFile >> user;
        p.set_User_Name(user);

        inFile2>>password;
        p.set_Password(password);

        players.push_back(p);

    }

    inFile.close();
    inFile2.close();
}

void PlayGame::add_Username(std::string pUser, std::string pPassword) {
    Player p;
    p.set_User_Name(pUser);
    p.set_Password(pPassword);
    ofstream outFile,outFile2;
    outFile.open("../users.txt", std::ios::app);
    outFile << pUser<<endl;
    outFile2.open("../passwords.txt", std::ios::app);
    outFile2<<pPassword<<endl;
    outFile.close();
    outFile2.close();
}
string PlayGame::game_Choice(){
    cout<<"What game would you like to play?"<<endl;
    int gameOption;
    cout<<"Enter (1) to Play Don't Build The Man (2) to play other game"<<endl;
    while (!(cin >> gameOption)||(!(gameOption == 1 || gameOption == 2))){
        cout << "Invalid Input! Please Enter Integer (1) or (2)"<<endl;
        cin.clear();
        string junk;
        getline(cin, junk);
    }
    if(gameOption==1){
        set_Game("Dont_Build_The_Man");
        return "Dont_Build_The_Man";
    }
    else{
        set_Game("Other_Game");
        return "Other_Game";
    }
}
int PlayGame::get_User_Index(std::string pUsername) {
    for (int i=0;i<players.size();i++) {
        if (players[i].get_User_Name() == pUsername) {
            return i;
        }
    }
    return -1;
}
bool PlayGame::check_Password(int pIndex, std::string pPassword) {
    if (players[pIndex].get_Password() == pPassword) {
            return true;
    }
    return false;
}