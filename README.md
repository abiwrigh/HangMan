
ABIGAIL WRIGHT

# Title: DON'T BUILD THE MAN

This is a game, designed like the hang man, but instead is don't build the man (hang man seems a bit outdated). 
This program allows the user to choose from three levels, easy, medium, and hard. Each level has a set of 15 words based on hardness. The game will prompt for username and password for new and returning players. 

# Languages and Files Used

This program uses C++ and reads from CSV files. 


# Details Of Game

Main Function: The main function prompts user if they have an account or not. If yes it will check username, if found will prompt for password. If not found after 5 trys game exits.
If found, user has a choice of which game to play. Option 2 doesn't work yet as no other game is implemented yet. If new user it prompts user to create and account by validating the username isn't taken. 
Once game 1, is selected the user will have options to see leaderboard, personal stats, or start game, all options lead to game. Game has 3 levels to choose from. 
If the game is won the stats will be recorded in personal stats and game leaderboard. Everytime the game is run there is an option to exit.

- Component: Don't Build a Man has a Level class, which has 3 different levels to choose from using and enumerated type in class


- Component: PlayGame has a Player class which has fields username and password, player stats to write out to, player stats to read from, and input validation


- Files: Player class writes out to a file for individual user, if user is new it will create new csv file for user. It also has a function to read from user's csv file.


- Files: In Don't build the man class leaderboard reads from csv file to show leaderboard for game


- Files: In main function, if player wins a game the stats are recorder to leader csv file


- Files: In Level Class files are read in from a txt file for each level, medium, easy, and hard


- Files: PlayGame reads from two files one of usernames and one of passwords for each player. I kept it separate to maybe implement encoding.Class also has a function to add new users with username and password.



Known bugs: username input is case-sensitive

- Future work would include graphics, sorting the leader board by level and time

# Citations:
- https://www.programiz.com/cpp-programming/library-function/cctype/isalpha to see if character is in alphabet
- https://www.geeksforgeeks.org/tolower-function-in-cpp/ to lower case 
- https://stackoverflow.com/questions/11719538/how-to-use-stringstream-to-separate-comma-separated-strings to print in columns



