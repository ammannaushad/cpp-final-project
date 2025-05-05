#include <iostream>
#include "adventuregame.h" 


using namespace std;


int getUsersChoice(int size) {                //Input Validation
int choose;
while (true) {
cout<< "Enter your choice (1-" <<size<< "):";
cin>> choose;

if (cin.fail() || choose < 1 || choose > size) {
cin.clear();  
cin.ignore(numeric_limits<streamsize>::max(), 'n'); 
cout<< "Error. Enter a number between 1 and" <<size<< "." <<endl;
    } else {
cin.ignore(numeric_limits<streamsize>::max(), 'n');  
    return choose;
    }
}
}