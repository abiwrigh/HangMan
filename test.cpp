//
// Created by abiga on 2/25/2024.
//
#include "Player.h"
#include "PlayGame.h"
#include "Level.h"
#include "Dont_Build_The_Man.h"
#include <ctime>
#include <iostream>

using namespace std;

bool test_Player();
bool test_PlayGame();
bool test_Level();
bool test_Dont_Build_The_Man();

int main(){
    srand(time(NULL));
    if(test_Player()){
        cout<<"Passed all Player test cases"<<endl;
    }
    if(test_PlayGame()){
        cout<<"Passed all PlayGame test cases"<<endl;
    }
    if(test_Level()){
        cout<<"Passed all Level test cases"<<endl;
    }
    if(test_Dont_Build_The_Man()){
        cout<<"Passes all Dont Build The Man test cases"<<endl;
    }
    return 0;
}

bool test_Player(){
    bool passed=true;
    Player p;
    string s="Abi is Testing";
    if(p.is_Valid(s)){
        cout<<"Test player is valid failed with spaces"<<endl;
        passed=false;
    }
    s="Abi";
    if(p.is_Valid(s)==false){
        cout<<"Test player is valid failed with no spaces"<<endl;
        passed=false;
    }
    s="";
    if(p.is_Valid(s)){
        cout<<"Test player is valid failed with empty string"<<endl;
        passed=false;
    }

    return passed;
}

bool test_PlayGame(){
    bool passed=true;
    Dont_Build_The_Man d;
    d.add_Username("TestUser","TestPass");
    d.read_Username_File();
    if(d.check_Username("TestUser")== false){
        cout<<"Test for username in players vector failed"<<endl;
        passed=false;
    }
    if(d.check_Username("TestFake")){
        cout<<"Test Playgame Username is valid fake username failed"<<endl;
        passed=false;
    }
    cout<< "Choose 1"<<endl;
    if(d.game_Choice()!=("Dont_Build_The_Man")){
        cout<<"Test PlayGame: game choice failed dbtm"<<endl;
        passed=false;
    }
    cout<<"Choose2"<<endl;
    if(d.game_Choice()!=("Other_Game")){
        cout<<"Test PlayGame: game choice failed Other Game"<<endl;
        passed=false;
    }
    if(!d.get_User_Index("TestUser")==3){
        cout<<"Failed PlayGame, get user index correct index"<<endl;
        passed=false;
    }
    if(d.get_User_Index("TestUser")==-1){
        cout<<"Failed PlayGame, get user index with false index"<<endl;
        passed=false;
    }
    if(d.check_Password(0,"TestPass")){
        cout<<"Failed Playgame check password with wrong index"<<endl;
        passed=false;
    }
    if(d.check_Password(3,"TestPass")==false){
        cout<<"Test Playgame check password with correct index and password failed"<<endl;
        passed=false;
    }



    return passed;
}

bool test_Level(){
    bool passed=true;
    Level l;
    l.level_to_string(1);
    if(!(l.get_Level()=="Easy")){
        cout<<"Test Level to string failed 1"<<endl;
        passed=false;
    }
    l.level_to_string(2);
    if(!(l.get_Level()=="Medium")){
        cout<<"Test Level to string failed 2"<<endl;
        passed=false;
    }
    l.level_to_string(3);
    if(!(l.get_Level()=="Hard")){
        cout<<"Test Level to string failed 3"<<endl;
        passed=false;
    }

    return passed;
}

bool test_Dont_Build_The_Man(){
    bool passed=true;
    Level l;
    l.level_to_string(1);
    Dont_Build_The_Man d;

    if(!(d.get_Level(1)=="Easy")){
        cout<<"Test Failed Dont Build Man get level"<<endl;
        passed=false;
    }
    vector<char> guesses;
    guesses.push_back('p');
    vector<char> guessR;
    guessR.push_back('x');
    if(d.character_Validator(guesses,guessR,"plus")){
        cout<<"Failed DBTM test with string"<<endl;
        passed= false;
    }
    if(d.character_Validator(guesses,guessR,"1")){
        cout<<"Failed DBTM test with non-letter"<<endl;
        passed= false;
    }
    if(d.character_Validator(guesses,guessR,"p")){
        cout<<"Failed DBTM test with char in guessed right"<<endl;
        passed= false;
    }
    if(d.character_Validator(guesses,guessR,"x")){
        cout<<"Failed DBTM test with char in guessed wrong"<<endl;
        passed= false;
    }
    if(d.character_Validator(guesses,guessR,"s")==false){
        cout<<"Failed DBTM test with vailid char"<<endl;
        passed= false;
    }
    cout<<"Enter 1 "<<endl;
    if(!(d.get_Level_Choice(std::cout,std::cin)==1 || d.get_Level_Choice(std::cout,std::cin)==2||d.get_Level_Choice(std::cout,std::cin)==3 )){
        cout<<"Test DBTM failed get level choice option 1,2,3"<<endl;
        passed=false;
    }
    vector<string> test;
    test.push_back("hi");
    test.push_back("this");
    test.push_back("is");
    test.push_back("a");
    test.push_back("test");
    test.push_back("okay");
    vector<int> testInt=d.shuffle_words(test);
    vector<int> testInt2;
    testInt2.push_back(1);
    testInt2.push_back(2);
    testInt2.push_back(3);
    testInt2.push_back(4);
    testInt2.push_back(5);
    testInt2.push_back(6);
    bool testing=false;
    int count=0;
    for(int i=0;i<testInt.size();i++){
        if(testInt[i]==testInt2[i]){
            testing=false;
        }
        if(!(testInt[i]==testInt2[i])){
            testing=true;
            count++;
        }
    }
    if(count==5){
        cout<<"Shuffle words Test for DBTM failed"<<endl;
        passed=false;
    }




    return passed;
}