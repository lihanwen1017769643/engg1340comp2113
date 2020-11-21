//show_choice.cpp
//This funciton shows the avaiable choice in each loops

//There's no input needed and return value but the information of avaiable choice
//will be printed out during the function calling.

#include <iostream>
#include "show_choice.h"
using namespace std;

void show_choice() {
    cout << "1: Roll the dice" << endl;
    cout << "2: Show your information" << endl;
    cout << "3: Save game status" << endl;
    cout << "0: Exit" << endl;
}
