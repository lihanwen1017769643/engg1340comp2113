//player.cpp

#include <iostream>
#include <string>
#include <iomanip>
#include "player.h"
using namespace std;


const double init_property = 100;

//This member function enables us to get the maximum of a player's house level
//There is no input and the return value is the maximum.
int Player::max_house_level(){
  int max = 0;

  //get the maximum of house level
  for (int i = 0; i <land_count; i ++) {
      if (house_level[i] > max)
          max = house_level[i];
  }
  return max;
}

//This member function gets the player's name
//The input will be the player's name (within 20 characters)
string Player::getName() {
    string _name;
    cout << "Please input your name: ";
    cin >> _name;
    while(cin.get() != '\n')
        continue;
    while(_name.length() > 20)
    {
        cout << "Invalid name. Please input again!\n";
        cin >> _name;
        while(cin.get() != '\n')
            continue;
    }
//    getline(cin, _name);
//    while(_name.length() > 20)
//    {
//        cout << "Invalid name. Please input again!\n";
//        cin >> _name;
//    }
    return _name;
}

//This member function initialize the values of player's member variables
void Player::init() {
    name = getName();
    loop = 1;
    pos = 0;
    mobility = true;
    property = init_property;
    land_count = 0;

}

//This function shows the information of the players.
//no input needed and no return value
//But the player's information will be printed out.
void Player::show_info() {
    cout << "Name: " << name << endl;
    cout << "Loop: " << loop << endl;
    cout << "Position: " << pos << endl;
    cout << "Mobility: ";
    if (mobility)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
    cout << "Property: " << property << endl;
    cout << "Land count: " << land_count << endl;
    cout << "max_house_level: " << max_house_level() << endl;
    cout << "Player order: " << order << endl << endl;

    cout << "   Owned lands" << setw(20) << "House level" << endl;

    for(int i = 0; i < land_count; ++i)
    {
        int len = 21 - (int)land[i].length();
        cout << i + 1 << ". " << land[i] << setw(len) << house_level[i] << endl;
    }
    cout << endl;
}
