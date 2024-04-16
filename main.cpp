//
// Created by abiga on 2/18/2024.
//
#include <iostream>
#include <time.h>
#include "Dont_Build_The_Man.h"
#include "Player.h"

using namespace std;

int main(){
    // resets for random to be used!
    srand(time(NULL));

    // Creating game object of don't build the man
    Dont_Build_The_Man game;

    // initialise game choice
    string game_Choice="";

    // initialise game to start by calling this function to load player vector
    game.read_Username_File();

    // initialise username if user is in system return true
    string userName;
    userName.clear();
    if(game.game_User_Options()==true){
        // prompt user for username until found, 5 attempts until program exits
        cout<<""<<endl;
        cout<<"Enter a Username:";
        getline(cin, userName);
        int count=0;
        while(game.check_Username(userName)==false || count>5){
            if(count==4){
                cout<<"This is your last try, Try making another account"<<endl;
            }
            else{
                if(count>0){
                    cout<<"We couldn't find you, please try again"<<endl;
                }
                userName.clear();
                getline(cin, userName);
            }
            count++;
        }
        if(count==5){
            exit(0);
        }

        // once username found, find password for username 5 attempts until program exits
        int userIndex=game.get_User_Index(userName);
        string password;
        cout<<""<<endl;
        cout<<"Enter Password:";
        getline(cin, password);
        int count2=0;
        while(game.check_Password(userIndex,password)==false || count2>5){
            if(count2==4){
                cout<<"This is your last try, contact us to reset password"<<endl;
            }
            else{
                cout<<"Wrong password, please try again"<<endl;
                password.clear();
                cout<<""<<endl;
                cout<<"Enter Password:";
                getline(cin, password);
            }
            count2++;
        }
        if(count2==5){
            cout<<"Contact us to reset password"<<endl;
            exit(0);
        }

        // welcome back statement
        cout<<""<<endl;
        cout<<"Welcome Back "+userName+"!"<<endl;

        cout<<""<<endl;

        // option to choose a game, only one game loaded right now option 2 on its way
        game_Choice=game.game_Choice();

        // set title of game to choice chosen by user
        game.set_Game(game_Choice);
    }
    else{
        Player p;
        // Creating username string for game play, call set_User_Name to set name
        cout<<""<<endl;
        getline(cin, userName);
        int count=0;
        // validating user hasn't been used and is in the right format
        bool enterUser=false;
        while(enterUser==false){
            if(p.is_Valid(userName)==false) {
                userName.clear();
                if (count > 0) {
                    cout << "Enter a UserName: ";
                    getline(cin, userName);
                    enterUser = false;
                }
            }
            if(game.check_Username(userName)==true && count>0){
                cout<<"It looks like that username is being used please try another"<<endl;
                cout<<"Enter a UserName: ";
                getline(cin, userName);
                enterUser=false;
            }


            if(p.is_Valid(userName)==true && count>0){
                if(game.check_Username(userName)==false){
                    enterUser=true;
                }

            }
            count++;
        }

        string password;
        cout<<""<<endl;
        cout<<"Enter a Password:";
        getline(cin, password);
        // validating password is in the right format
        while(p.is_Valid(password)== false){
            if(password.length()>15){
                cout<<"Username too, long please enter 15 characters max: ";
            }
            password.clear();
            cout<<"Enter a Password: ";

            getline(cin, password);

        }

        // once validated adding user to system
        game.add_Username(userName,password);
        cout<<"Thanks for Joining, "+userName+"!"<<endl;

        // users choice of game, game 2 not ready for production
        game_Choice=game.game_Choice();

        // set user game choice as game title
        game.set_Game(game_Choice);

    }
    if(game_Choice=="Dont_Build_The_Man"){
        // Call print_rules() function to read rules of the game
        game.print_rules(cout);
        game.print_Leaderboard(userName);

        // Call levelChoice function to validate input for level choice
        int levelChoice=game.get_Level_Choice(cout, cin);
        Level level;
        level.set_Level(levelChoice);
        vector<string> wordsList=level.level_to_string(levelChoice);

        // Timers initiated for Start and Stop to be used for gameplay
        time_t startTime, endTime;
        double totalTime;

        // Create Score Board, CSV, file including Username, level choice, and time
        ofstream outFile;
        outFile.open("../leaders.csv", std::ios::app);

        // Random Integer for changing the word from the word list each time
        vector<int> randomIntegers;
        int randInt;
        randomIntegers.clear();

        // bool playAgain set for option of user to play another round
        bool playAgain=false;

        // Call shuffle_words with word list to get size of list and generate vector of random integers
        randomIntegers=game.shuffle_words(wordsList);

        // game play per level is the length of the words in each list, around 15 each
        for(int i=0;i<wordsList.size();i++){

            // Iterating through random integer vector to get integer to choose from word list
            randInt=randomIntegers[i];
            string wordToGuess=wordsList[randInt];

            // Time captured with built-in time.h library
            time(&startTime);

            // send word as parameter to play_Game
            if(game.play_Game(cout,wordToGuess)){

                // End time captured.
                time(&endTime);

                // built-in function difftime to take the difference of second time from fist
                totalTime = difftime(endTime, startTime);

                // call set_Time from PlayGame class to set time for user
                game.set_Time(totalTime);

                // create player object and write stats out to personal .txt file in player class
                Player p;
                p.write_Stats(game.get_Game(),level.get_Level(),game.get_Time(),userName);

                // Call getters from PlayGame Class,write to csv file for leaderboard
               outFile << userName<< ',' << level.get_Level() << ',' << game.get_Time() << endl;

                // print word that was guessed right to terminal
                cout<<wordsList[randInt]<<endl;
                cout<<"Awesome Work, You Guessed it"<<endl;

                // option to play_again call function play_Again to validate user input
                playAgain=game.play_Again(cout, cin);
                if(playAgain==false){

                    // to exit game
                    exit(0);
                }
                else{
                    continue;
                }
            }
            else{
                // All same as above if statement with different print statements and score doesn't get recorded
                time(&endTime);
                totalTime = difftime(endTime, startTime);
                game.set_Time(totalTime);
                cout<<"The Word Was....";
                cout<<wordsList[randInt]<<endl;
                cout<<"Wanna Try Again?!"<<endl;
                playAgain=game.play_Again(cout, cin);
                if(playAgain==false){
                    exit(0);
                }
                else{
                    continue;
                }

            }

        }
        randomIntegers.clear();
        outFile.close();
        userName.clear();

    }

    return 0;
}
