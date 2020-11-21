//move.cpp
//This function moves the player according to the rolling results.
//The parameters are the array storing the information of the player and two integers
//represents the rolling result and whose loop the current loop is, respectively.

//There's no input needed and no return value.
//But since the array player is pass-by-reference, the player's information
//will be modified during the function calling.

#include "player.h"
#include "move.h"

const int tot_land_num = 28;
const int loop_award = 10;

void move(Player * players, int rs, int turn) {
    players[turn].pos += rs;
    if(players[turn].pos > tot_land_num - 1)
    {
        players[turn].pos -= tot_land_num;
        players[turn].loop += 1;
        players[turn].property += loop_award;
    }
}
