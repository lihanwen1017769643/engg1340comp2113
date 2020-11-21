//save.cpp
//This function will save the information of current game into file "date.txt"

//The parameters are one array of Player storing the information
//of players, one array of Land storing the information
//of lands and two integers turn and win_condition represent
//the whose loop the current loop is and the winning condition respectively.

//There's no input needed.

//There's no return value. However, all information above will be saved to
//the file "data.txt".
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include "player.h"
#include "land.h"
#include "save.h"
using namespace std;

const int player_num = 4;
const int tot_land_num = 28;

void save_data(Player* players, Land* lands, int turn, int win_condition) {
    //create fout object and associate it with data.txt
    ofstream fout;
    fout.open("data.txt");
    if(fout.fail()) {
        cout << "Error in opening the file!" << endl;
        cout << "Fail in saving!" << endl;
        return;
    }

    //store turn
    fout << win_condition << '\n' << turn << '\n';

    //store the status for 4 players
    Player p;
    for(int i = 0; i < player_num; i++) {
        p = players[i];
        fout << p.name << '\n' << p.loop << '\n' << p.pos
        << '\n' << p.mobility << '\n' << p.property << '\n'
        << p.land_count << '\n' << p.order << '\n';

        for(int j = 0; j < p.land_count; j++)
            fout << p.land[j] << '\n';

        for(int j = 0; j < p.land_count; j++)
            fout << p.house_level[j] << '\n';
    }

    //store the status for 28 lands
    Land l;
    for(int i = 0; i < tot_land_num; i++) {
        l = lands[i];
        fout << l.owner << '\n' << l.house_level << '\n'
        << l.no << '\n' << l.name << '\n' << l.type << '\n'
        << l.price << '\n';
    }

    fout.close();

    cout << "Successfully saved!" << endl;
}
