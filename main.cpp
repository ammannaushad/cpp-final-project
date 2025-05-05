#include <iostream>
#include "adventuregame.h"
#include <fstream>  


using namespace std;


void printGameIntroduction () {
cout<< R"(
        _   _                          _           _ 
       | | | |   __ _   _ __     ___  | |_    ___ | |
       | |_| |  / _` | | '_ \   / _ \ | __|  / __|| |
       |  _  | | (_| | | | | | |  __/ | |_  | (__ | |
       |_| |_|  \__,_| |_| |_|  \___|  \__|  \___||_|
      
                      H A U N T E D
)" <<endl;                                               //ASCII Art
cout<< "Welcome to the Haunted Mansion" <<endl;          //Game Introduction
cout<< "Adam and Jerry have decided to investigate the mansion believing it contains a secret portal to another universe" <<endl;
cout<< "Once someone enters the mansion, they NEVER return" <<endl;
cout<< "Their curiosity has led them here" <<endl;
cout<< "Your mission is to get Adam and Jerry safely back home" <<endl;
}


void printOptions(string choices[], int size) {        //Options to choose from
    for (int i = 0; i < size; i++) {
cout<< (i + 1) << "." << choices[i] <<endl;
    }
}



int getUsersChoice(int size) {                        //Input Validation
int choose;
cin>> choose;
    while (choose < 1 || choose > size) {
    cout<< "Error. Choose one of the following options:" <<size<< ":";
    cin>> choose;
    }
return choose;
}


void printEnd(int win) {                              //Game ending
ofstream log("game_summary.txt", ios::app);

    if (win == 1) {
cout<< "YOU WON. You successfully brought them home" <<endl;
log<< "Game Result: WIN" <<endl;
    } else {
cout<< "YOU LOST. You failed to save them" <<endl;
log<< "Game Result: LOSS" <<endl;
    }
log.close(); 
}


int main() {
string leftChoices[] = {"Keep walking", "Go after the shadow"};          //Options for if the user's chooses left
string rightChoices[] = {"Open the door", "Try to escape"};              //Options for if the user's chooses right


int select;
int gameOver = 0;

while (gameOver == 0) {
    printGameIntroduction();

cout<< "What should be their first step:" <<endl;
cout<< "1. Go left" <<endl;
cout<< "2. Go right" <<endl;
cout<< "Select one option:" <<endl;
select= getUsersChoice(2);


if (select == 1) {
cout<< "They chose left where they see a shadow of a tall man" <<endl;
printOptions(leftChoices, 2);
int leftChoice = getUsersChoice(2);


if (leftChoice == 1) {
cout<< "They keep walking and the hallway ends." <<endl;
    printEnd(1);  
} else if (leftChoice == 2) {
cout<< "They try to chase the shadow, but it ends up tricking them. They end up in a room filled with poisonous gas" <<endl;
    printEnd(0); 
}


} else if (select == 2) {
cout<< "They chose right where a door magically opens" <<endl;
printOptions(rightChoices, 2);
int rightChoice = getUsersChoice(2);


if (rightChoice == 1) {
cout<< "They encounter a ghost as they enter the room, where the ghost captures Adam" <<endl;
cout<< "The ghost orders Jerry to leave or be trapped forever" <<endl;

string jerryDecisions[] = {"Look for help", "Try to escape"};
printOptions(jerryDecisions, 2);
int jerryChoice = getUsersChoice(2);


if (jerryChoice == 1) {
cout<< "Jerry runs around the mansion looking for help and stumbles upon the shadow again" <<endl;
cout<< "He begs the shadow to help Adam" <<endl;
cout<< "The shadow agrees to help, only if they never let anyone else enter the mansion again" <<endl;
cout<< "Both Adam and Jerry arrived home safely" <<endl;
    printEnd(1); 
} else {
cout<< "Jerry tries to escape, but the ghosts locks the door behind him leaving them both trapped forever" <<endl;
    printEnd(0);  
}


} else if (rightChoice == 2) {
cout<< "They try to escape, but the ghost was too strong to run away from" <<endl;
printEnd(0);  
}
}


char again;                             //Play again option
cout<< "Would you like to play again? (y/n)";
cin>> again;
if (again == 'n' || again == 'N') {
    gameOver = 1;
}
}

return 0;
}

