//load.cpp
//This function will load last unfinished game from the file "data.txt"

//The parameters are one array of Player, one array of Land (both with no assigned value)
//and two integers turn and win_condition represent
//whose loop the current loop is and the winning condition respectively

//There's no input needed.

//There's no return value. However, since it's pass-by-reference, two arrays
//will be modified during the function calling

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include "player.h"
#include "land.h"
#include "load.h"
using namespace std;

const int player_num = 4;
const int tot_land_num = 28;

void load_data(Player* players, Land* lands, int& turn, int& win_condition)
{
    //create fin object and associate it with data.txt
    ifstream fin;
       fin.open("data.txt");
       if(fin.fail()) {
           cout << "Error in opening the file!" << endl;
           cout << "Fail in loading!" << endl;
           return;
       }

    //load win_condition and turn
    fin >> win_condition >> turn;

    //load the status for 4 players
    for(int i = 0; i < player_num; i++) {
        fin >> players[i].name >> players[i].loop >> players[i].pos >> players[i].mobility >> players[i].property >> players[i].land_count >> players[i].order;

        for (int j = 0; j < players[i].land_count; j++) {
            fin >> (players[i].land)[j];
        }

        for (int j = 0; j < players[i].land_count; j++) {
            fin >> (players[i].house_level)[j];
        }
    }

    //load the status for 28 lands
    for(int i = 0; i < tot_land_num; i++) {
        fin >> lands[i].owner >> lands[i].house_level >> lands[i].no >> lands[i].name >> lands[i].type >> lands[i].price;
    }

    fin.close();

    cout << "Successfully loaded!" << endl;
}
