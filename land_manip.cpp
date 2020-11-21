//land_manip.cpp

//This function is the action a player takes when he/she goes to some land
//depending on the type of the land (normal, special, chance) and its owner

//The parameters are the two array player[] and lands[] storing the information
//of players and lands and a integer turn reflects whose loop the current loop is
//and three integer r1, r2 and rs represents the number rolled on the two dices

//The input for indicating whether buying the land and upgrading the land or not
//will be required if you are the owner.
//There's no return value but since it's pass-by-reference, all the variable
//mentioned above will be modified during the function calling.

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <cmath>
#include <string>
#include <unistd.h>
#include "player.h"
#include "land.h"
#include "move.h"
#include "roll.h"
#include "land_manip.h"
using namespace std;

const int player_num = 4;
const int chance_num = 8;
const int tot_land_num = 28;
const string chances[chance_num] = {"Move 5 steps forward", "Move 3 steps backward", "Successfully reported the escaped criminal, get $15 more money", "You cannot move in your next turn", "Directly go to START", "Fix your car, lose 8 more money", "Interest from the bank, get 5 more money", "Go to hospital, lose 6 more money"};

void land_manip(Player * players, Land * lands, int turn, string& choice, int& r1, int& r2, int& rs) {
    //check whether the land is normal
    //this land is normal
    if(lands[players[turn].pos].type == "Normal") {
        //check whether the land has owner
        if(lands[players[turn].pos].owner == "None") {
            cout << "This land is avaiable now. Would you like to buy it or not? (y/n)\n";
            cin >> choice;
            while (choice != "y" && choice != "Y" && choice != "n" && choice != "N") {
                cout << "Invalid input. Please input again!" << endl;
                cin >> choice;
            }

            //player chooses to buy
            if(choice == "y" || choice == "Y") {
                //not enough money
                if(players[turn].property < lands[players[turn].pos].price) {
                              cout << "You do not have enough property. You cannot buy it.\n";
                }
                //enough money to buy
                else {
                    lands[players[turn].pos].owner = players[turn].name;
                    players[turn].property -= lands[players[turn].pos].price;
                    (players[turn].land)[players[turn].land_count] = lands[players[turn].pos].name;
                    (players[turn].house_level)[players[turn].land_count++] = 0;
                    cout << "You have successfully bought this land. ";
                    cout << "The property you have now is " << players[turn].property << "." << endl;
                }
            }

            //player chooses not to buy
            else if(choice == "n" || choice == "N") {
                cout << "You decided not to buy this land"
                << "What a good opportunity!" << endl;
            }
        }

        //the land already has an owner
        else {
            //the owner is the other player
            if(lands[players[turn].pos].owner != players[turn].name) {
                cout << "Oh no! This land belongs to " << lands[players[turn].pos].owner;
                cout << ". You have to pay some money!" << endl;
                //pay = original price * 0.2 * (1 + house level)
                double pay = lands[players[turn].pos].price * 0.2 * (1 + lands[players[turn].pos].house_level);

                //not enough money
                if(players[turn].property < pay) {
                    cout << "Sorry. You do not have enough money!" << endl;
                    players[turn].property -= pay;
                }
                //enough money
                else {
                    players[turn].property -= pay;
                    cout << "Now you have " << players[turn].property << " money and ";

                    for(int i = 0; i < player_num; i++) {
                        if(players[i].name == lands[players[turn].pos].owner){
                            players[i].property += pay;
                            cout << players[i].name << " has "
                            << players[i].property << " money.\n";
                        }
                    }
                 }
            }

            //the owner is the player
            else {
                cout << "The house level is now " << lands[players[turn].pos].house_level << ". " << endl;
                //the owner can upgrade its house if the house level does not reach 3
                if(lands[players[turn].pos].house_level < 3) {
                    cout << "You can upgrade your house to earn more money!" << endl;
                    cout << "Do you want to upgrade it with " << pow(2, lands[players[turn].pos].house_level) << " money? (y/n)\n";
                    cin >> choice;
                    while(choice != "y" && choice != "Y" && choice != "n" && choice != "N") {
                        cout << "Invalid input. Please input again!" << endl;
                        cin >> choice;
                    }

                    //not enough money
                    if(players[turn].property < pow(2, lands[players[turn].pos].house_level))
                    {
                        cout << "You do not have enough property. You cannot buy it.\n";
                    }
                    //enough money
                    else {
                        int* hl = new int;
                        *hl = -1;
                        //int hl = -1;
                        (lands[players[turn].pos].house_level)++;
                        players[turn].property -= pow(2, lands[players[turn].pos].house_level);
                        for(int i = 0; i < players[turn].land_count; i++) {
                            if(players[turn].land[i] == lands[players[turn].pos].name)
                                *hl = i;
                                //hl = i;
                        }
                        (players[turn].house_level[*hl])++;
                        //(players[turn].house_level[hl])++;

                        cout << "You have successfully upgrade your house! ";
                        cout << "The level is now " << lands[players[turn].pos].house_level << "." << endl;
                        cout << "The property you have now is " << players[turn].property << "." << endl;
                    }
                }
            }
        }
    }

    //this land is special
    else {
        if(lands[players[turn].pos].name == "START")
            cout << "You are now at the START." << endl;
        else if(lands[players[turn].pos].name == "JAIL") {
            cout << "Oops! You go onto JAIL! You have to stay here for the next turn!" << endl;
            players[turn].mobility = 0;
        }
        else if(lands[players[turn].pos].name == "TEMP_DOUBLE") {
            cout << "TEMP DOUBLE! You have another chance to roll!" << endl;
            if(!players[turn].mobility) {
                cout << "Sorry. You cannot roll dices this turn! Have a good luck!" << endl;
                players[turn].mobility = 1;
            }
            else {
                roll(r1, r2, rs);
                move(players, rs, turn);
                cout << "moving..." << endl;
                usleep(2000000);    //wait 2 seconds to simulate the moving process
                land_manip(players, lands, turn, choice, r1, r2, rs);
            }
        }
        else if(lands[players[turn].pos].name == "WORM_HOLE") {
            cout << "WORM HOLE is running!" << endl;
            //worm hole allows player to move at most tot_land_num/2 steps
            usleep(1000000);    //wait 1 seconds to simulate
                                //the process of running the worm hole
            srand((unsigned)time(NULL));
            move(players, rand() % (tot_land_num / 2), turn);
            cout << "Oh! You are teleported to " << lands[players[turn].pos].name << ". Isn't it familiar to you?" << endl;
        }

        //this land is "chance" land
        else if(lands[players[turn].pos].name == "CHANCE") {
            cout << "Aha! CHANCE! Wish you good luck!" << endl;
            cout << "drawing..." << endl;
            
            usleep(2000000);    //wait 2 seconds to simulate the drawing process
            int ch = rand() % (chance_num);
            cout << chances[ch] << endl;
            switch(ch) {
                case 0:
                    move(players, 5, turn);
                    land_manip(players, lands, turn, choice, r1, r2, rs);
                    break;
                case 1:
                    move(players, -3, turn);
                    land_manip(players, lands, turn, choice, r1, r2, rs);
                    break;
                case 2:
                    players[turn].property += 15;
                    break;
                case 3:
                    players[turn].mobility = 0;
                    break;
                case 4:
                    move(players, (tot_land_num - players[turn].pos), turn);
                    break;
                case 5:
                    players[turn].property -= 8;
                    break;
                case 6:
                    players[turn].property += 5;
                    break;
                case 7:
                    players[turn].property -= 6;
                    break;
            }
        }
    }
}
