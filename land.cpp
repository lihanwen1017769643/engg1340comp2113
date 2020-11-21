//land.cpp
//This member function of struct enable us to get the current information
//of certain land

//There is no input needed and no return value. 
//But the information of all member variable of land
//will be printed during the function calling

#include <iostream>
#include <string>
#include "land.h"
using namespace std;

void Land::show_info() {
    cout << "********************" << endl;
    cout << "Land Name: " << name << endl;
    cout << "Land Number: " << no << endl;
    cout << "Land Type: " << type << endl;
    cout << "Land Owner: " << owner << endl;
    cout << "House Level: " << house_level << endl;
    cout << "House Price: " << price << endl;
    cout << "********************" << endl;
}
