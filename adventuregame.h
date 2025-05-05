#ifndef ADVENTUREGAME_H
#define ADVENTUREGAME_H


#include <string>
#include <iomanip>

using namespace std;



void printGameIntroduction();                      //User defined functions
void printOptions(string choices[], int size);
int getUsersChoice(int size); 
void printEnd(int win);


#endif

