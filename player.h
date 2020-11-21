//player.h

#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <string>
using namespace std;
const int max_land_num = 20;


struct Player
{
    string name;        //the player's name
    int loop;           //the current loop no. in the game
    int pos;            //the position of the player
    bool mobility;      //represent whether the player is allowed to move this turn
    int property;       //amount of property the player owns
    int land_count;     //number of owned lands
    int order;          //the player's order, i.e. 1,2,3,4
    string land[max_land_num];      //lands the player owns
    int house_level[max_land_num];  //the house level of owned lands
    int max_house_level();   //get the maximum of the house level

    string getName();   //get player's name
    void init();        //intialize player info
    void show_info();   //print player info

};



#endif
