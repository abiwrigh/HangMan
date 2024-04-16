//
// Created by abiga on 2/23/2024.
//

#include "Dont_Build_The_Man.h"

Dont_Build_The_Man::Dont_Build_The_Man() {
    PlayGame();
    fTime=0;

}
void Dont_Build_The_Man::set_Time(double pTime){
    fTime=pTime;
}


double Dont_Build_The_Man::get_Time(){
    return fTime;
}
string Dont_Build_The_Man::get_Level(int pLevel){
    Level level;
    level.set_Level(pLevel);
    string lev=level.get_Level();
    return lev;
}
void Dont_Build_The_Man::build_Man(int pNumberGuessesWrong){
    int fNumberGuessesWrong=pNumberGuessesWrong;
    if(fNumberGuessesWrong==0){
        cout<<""<<endl;
    }
    else if(fNumberGuessesWrong==1){
        cout<<"0"<<endl;
    }
    else if(fNumberGuessesWrong==2){
        cout<<" 0 "<<endl;
        cout<<"-"<<endl;
    }
    else if(fNumberGuessesWrong==3){
        cout<<" 0 "<<endl;
        cout<<"-|"<<endl;
    }
    else if(fNumberGuessesWrong==4){
        cout<<" 0 "<<endl;
        cout<<"-|-"<<endl;
    }
    else if(fNumberGuessesWrong==5){
        cout<<" 0 "<<endl;
        cout<<"-|-"<<endl;
        cout<<"/"<<endl;
    }
    else {
        cout<<" 0 "<<endl;
        cout<<"-|-"<<endl;
        cout<<"/ \\"<<endl;
    }
}
bool Dont_Build_The_Man::character_Validator(vector<char> pGuesses, vector<char> pGuessedRight, string pValidateInput){
    vector<char> fGuesses=pGuesses;
    vector<char> fGuessedRight=pGuessedRight;
    int checkCharacter;
    char characterGuess;
    string fValidateInput=pValidateInput;

    // validating string is only 1 character
    if(fValidateInput.length() != 1) {
        cout << "Invalid Input please only Enter 1 letter" << endl;
        return false;
    }

    else{
        // https://www.programiz.com/cpp-programming/library-function/cctype/isalpha
        // validating is character is in the alphabet from above code
        checkCharacter= isalpha(fValidateInput[0]);
        if(checkCharacter==0){
            cout << "Invalid Input please only letters in the alphabet" << endl;
            return false;
        }
        else{
            // if character in alphabet checking if character has been guessed before
            characterGuess = fValidateInput[0];
            for (int i=0;i<fGuessedRight.size();i++){
                if (characterGuess==fGuessedRight[i]){
                    cout<<"You already guessed that right, enter a different character"<<endl;
                    return false;
                }
            }
            for(int j=0;j<fGuesses.size();j++){
                if(characterGuess==fGuesses[j]){
                    cout<<"You already made that wrong guess, enter a different character"<<endl;
                    return false;
                }
            }
            return true;
        }
    }
}

bool Dont_Build_The_Man::play_Game(std::ostream &outs,string pWord){
    // Create Array list of guesses to be added to, once user guesses
    vector<char> guesses;
    // Array of char guessed that were right
    vector<char> guessedRight;
    // Create integer Count for wrong guesses
    int numberOfGuessesWrong=0;

    // Variables initiated
    string fWord=pWord;
    char placeHolder='_';
    char characterGuess;
    string builtWord;
    int lengthOfWord=pWord.length();
    vector<char> buildWord;
    bool guessWrong=true;
    bool gamePlay=false;
    string validateInput;
    bool validaterPassed=false;

    outs<<"Here is Your Word, The Placeholders Below Represent Your Letters To Guess"<<endl;
    outs<<"The Timer Starts Now, Good Luck!"<<endl;

    // initiating vector size of word with filler characters
    for(int i=0;i<lengthOfWord;i++){
        buildWord.push_back(placeHolder);
    }

    outs<<" "<<endl;
    outs<<" "<<endl;

    // loop for number of guesses wrong, accumulating to 6 unless word guessed right
    while(numberOfGuessesWrong<6){

        // call build man to print body part to screen for wrong guesses
        build_Man(numberOfGuessesWrong);

        // print guesses wrong to terminal to remind user
        outs<<""<<endl;
        outs<<"Letters Guessed Wrong: "<<endl;
        for(int i=0;i<guesses.size();i++){
            cout<<guesses[i];
        }

        // print to terminal word placeholders or placeholders with right guesses to screen
        outs<<""<<endl;
        for(int i=0;i<buildWord.size();i++){
            outs<<buildWord[i];
        }

        // Prompt user to enter character
        outs<<""<<endl;
        outs<<""<<endl;
        outs<<"Enter letter: "<<endl;

        // While loop to validate user input, or to see if character is not already guessed
        while(validaterPassed==false){
            cin>>validateInput;
            // Changing all characters to lowercase from https://www.geeksforgeeks.org/tolower-function-in-cpp/
            characterGuess= (char) tolower(validateInput[0]);
            validaterPassed=character_Validator(guesses,guessedRight,validateInput);
        }



        // looping to see if character is in the word, replaces placeholder with character
        for(int i=0;i<lengthOfWord;i++){
            if(characterGuess==fWord[i]){
                buildWord[i]=characterGuess;
                guessWrong=false;
            }
        }
        // if guessed wrong, increment number of wrong guesses and add to vector
        if(guessWrong==true){
            guesses.push_back(characterGuess);
            numberOfGuessesWrong++;
        }
        // if guessed right, print to terminal, add to right guesses vector
        if(guessWrong==false){
            outs<<"Nice Work!"<<endl;
            guessedRight.push_back(characterGuess);
        }

        // add characters from vector, to build a string to check if string matches word
        // got from https://www.geeksforgeeks.org/convert-vector-of-chars-to-string-in-cpp/
        for (char c : buildWord) {
            builtWord.push_back(c);
        }

        // if word is guessde right gameplay is true
        if(builtWord==fWord){
            gamePlay=true;
            numberOfGuessesWrong=6;
        }

        // resetting variables
        guessWrong=true;
        validaterPassed=false;
        builtWord="";
    }
    // prints last leg of man for last wrong guess, could be a bug but this works
    if(gamePlay== false){
        build_Man(numberOfGuessesWrong);
    }
    return gamePlay;
}
void Dont_Build_The_Man::print_rules(std::ostream &outs){
    outs <<""<<endl;
    outs << "Ready to Play DONT BUILD THE MAN?" << endl;
    outs << "This is a take on the classic game of Hang Man" << endl;
    outs << "BUT, that seemed a bit intense and outdated so it's a race to guess the word before building the man." << endl;
    outs << "You are given an option of a easy, medium, or hard word" << endl;
    outs << "You'll have to enter the letter of your choosing as your guess to be in the word" << endl;
    outs << "Oh, and you're being timed" << endl;
    outs << "So, 6 wrong guesses and your man is built and you lose" << endl;
    outs << "Guessing it right will put your name on the leaderboard" << endl;
    outs<<""<<endl;
}
int Dont_Build_The_Man::get_Level_Choice(std::ostream &outs,std::istream &ins){
    int levelChoice;
    cout <<" "<<endl;
    cout << "Choose a Level:"<<endl;
    cout << "Enter (1) for Easy, (2) for Medium, (3) for Hard"<<endl;
    // from Lisa Dion, UVM 
    while (!(cin >> levelChoice)||(!(levelChoice == 1 || levelChoice == 2|| levelChoice==3))){
        cout << "Invalid Input! Please Enter Integer."<<endl;
        cin.clear();
        string junk;
        getline(cin, junk);
    }
    string levels=get_Level(levelChoice);
    return levelChoice;
}

bool Dont_Build_The_Man::play_Again(std::ostream &outs,std::istream &ins){
    int choicePlayAgain;
    cout<<"Enter (1) to Play again (2) to exit"<<endl;
    while (!(cin >> choicePlayAgain)||(!(choicePlayAgain == 1 || choicePlayAgain == 2))){
        cout << "Invalid Input! Please Enter Integer (1) or (2)"<<endl;
        cin.clear();
        string junk;
        getline(cin, junk);
    }
    if(choicePlayAgain==1){
        return true;
    }
    else{
        cout << "Thanks For Playing!" << endl;
        return false;
    }

}
void Dont_Build_The_Man::print_Leaderboard(string pUser){
    int see;
    cout<<"Enter (1) to see leaderboard (2) to choose level (3) to see personal stats"<<endl;
    while (!(cin >> see)||(!(see == 1 || see == 2 || see == 3))){
        cout << "Invalid Input! Please Enter Integer (1) , (2), or (3)"<<endl;
        cin.clear();
        string junk;
        getline(cin, junk);
    }
    if(see==1){
        ifstream inFile("../leaders.csv");
        string line;
        //stackoverflow.com/questions/11719538/how-to-use-stringstream-to-separate-comma-separated-strings to print in columns
        cout<<""<<endl;
        cout<<"LEADERBOARD, Who Guessed IT RIGHT?"<<endl;
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
    if(see==3){
        Player p;
        p.player_Stats(pUser);
        print_rules(cout);
    }
    else{
        cout<<""<<endl;
    }

}
vector<int> Dont_Build_The_Man::shuffle_words(vector<string> &pWords){
    vector<string> wordsToShuffle=pWords;
    // Generate random number of length of array to choose random word
    int vectorLength=wordsToShuffle.size();
    vector<int> randomInt;
    for (int i=0;i<vectorLength; ++i){
        randomInt.push_back(i);
    }
    // got from previous work done in Data Structures
    auto rng = std::default_random_engine {};
    std::shuffle(std::begin(randomInt), std::end(randomInt), rng);
    return randomInt;
}
