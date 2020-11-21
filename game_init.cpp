//game_init.cpp

//This function initialize the game setting, including getting the player's name,
//deciding the player's order, generate the additional winnning condition,
//deciding the land number for 4 chance lands and
//setting up the initial value of member variable of each land

//The parameters are one array of Player and one array of Land with no assigned value.

//In the function calling, you will be prompted to enter the player's name
//There's no return value. However, since it's pass-by-reference, two arrays
//will be modified during the function calling

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <cmath>
#include <string>
#include <algorithm>
#include "player.h"
#include "land.h"
#include "game_init.h"
using namespace std;

const int player_num = 4;
const int chance_land_num = 4;
const int tot_land_num = 28;
const string land_name[tot_land_num] = {"HW", "JL", "KBSB", "MB", "HHY", "KB", "KK", "RR", "RHT", "RM", "CYM", "CYC", "CYP", "EH", "GH", "CB", "CPD", "JCT", "RRS", "CCT"};

template <typename T>
bool is_in(T x, T* arr, int n) {
    for(int i = 0; i < n; ++i) {
        if(x == arr[i])
            return 1;
    }
    return 0;
}

void game_init(Player players[], Land lands[], int& win_condition) {

    int chance_land_numset[chance_land_num];

    cout << "please input the player's name one by one" << endl;
    for(int i = 0; i < player_num; ++i)
    {
        (players + i)->init();
        //set player's order
        players[i].order = i + 1;
    }

    //generate the addtional winnning condition
    srand((unsigned)time(NULL));
    win_condition = rand() % 2 + 1;

    //randomly select 4 numbers (except for 0,7,14,21) to be chance lands

    int temp1;
    for(int i = 0; i < chance_land_num; ++i) {
        srand((unsigned)time(NULL));
        temp1 = rand() % 28;

        while(temp1 == 0 || temp1 == 7 || temp1 == 14 || temp1 == 21 || is_in(temp1, chance_land_numset, i)){
             srand((unsigned)time(NULL));
             temp1 = rand() % 28;
        }

        chance_land_numset[i] = temp1;
    }

    sort(chance_land_numset, chance_land_numset + chance_land_num);

    int index = 0;
    for(int i = 0; i < tot_land_num; ++i) {
        (lands + i)->owner = "None";
        (lands + i)->house_level = 0;
        lands[i].no = i;
        //set land name and type
        if(i == 0 || i == 7 || i == 14 || i == 21 || is_in(i, chance_land_numset, chance_land_num)) {
            lands[i].type = "Special";
            if(i == 0)
                lands[i].name = "START";
            else if(i == 7)
                lands[i].name = "JAIL";
            else if(i == 14)
                lands[i].name = "TEMP_DOUBLE";
            else if(i == 21)
                lands[i].name = "WORM_HOLE";
            else
                lands[i].name = "CHANCE";
            lands[i].price = 0;
        }
        else {
            lands[i].type = "Normal";
            lands[i].name = land_name[index++];
            //set land price, from 10 to 20
            srand((unsigned)time(NULL));
            lands[i].price = 10 + rand() % 11;
        }
    }
}
