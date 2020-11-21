// monopoly.cpp
//This is the main function of our game
//You may input the value according to the instruction given

#include <iostream>
#include <iomanip>
#include <ctime>
#include <cstdlib>
#include <fstream>
#include <algorithm>
#include <cmath>
#include <string>
#include <unistd.h>

#include "player.h"
#include "land.h"
#include "save.h"
#include "load.h"
#include "show_choice.h"
#include "game_init.h"
#include "move.h"
#include "roll.h"
#include "land_manip.h"
using namespace std;

const int player_num = 4;
const int tot_land_num = 28;
const int loop_win = 15;

int main()
{
    cout << "Welcome to Monopoly-updated version!" << endl;
    cout << "Please input a number to continue:" << endl;
    cout << "1: New game" << '\t' << "2: Load last game" << endl;
    char game_status;
    cin >> game_status;
    while(game_status != '1' && game_status != '2') {
        cout << "Invalid input. Please input again.\n";
        cin >> game_status;
    }
    while(cin.get() != '\n')
        continue;

    Player p1, p2, p3, p4;                           //initialize four Player struct
    Player players[player_num] = {p1, p2, p3, p4};   //player array
    Land lands[tot_land_num];                        //land array

    string choice;
    int turn = 0;        //the order of the player, from 0 to 3
    int r1 = 0, r2 = 0;  //the number on two dices
    int win_condition;  //1: loops >15; 2: have a highest level house

    //new game
    if(game_status == '1')
        game_init(players, lands, win_condition);

    //load last game
    else if(game_status == '2')
        load_data(players, lands, turn, win_condition);

    //test
    //show players' and lands' information
//    for(int i = 0; i < player_num; i++)
//        players[i].show_info();
//    for(int i = 0; i < tot_land_num; i++)
//        lands[i].show_info();

    //show winning condition
    cout << "-----------------------------------" << endl;
    if (win_condition == 1)
         cout << "This game's addtional winning condition is finishing 15 loops of the map!" <<endl;
    else
         cout << "This game's addtional winning condition is having house with the highest level!" <<endl;

    //main game loop
    while(1)
    {
        cout << "-----------------------------------" << endl;
        cout << "Player " << turn + 1 << " " << players[turn].name << "'s turn!" << endl;
        cout << "Input a letter below to continue." << endl;

        //game home page
        show_choice();
        cin >> choice;

        while(choice != "1") {
            //quit game
            if(choice == "0") {
                cout << "-----------------------------------" << endl;
                cout << "Are you sure you want to quit?\n";
                cout << "The system will automatically save your game status if you quits." << endl;
                cout << "Please input y/Y or n/N. (y/Y = yes, n/N = no)" << endl;
                cin >> choice;
                while(choice != "y" && choice != "Y" && choice != "n" && choice != "N") {
                    cout << "Not valid. Please input again!" << endl;
                    cin >> choice;
                }

                if(choice == "y" || choice == "Y") {
                    save_data(players, lands, turn, win_condition);
                    return 0;
                }
             }
            //show current player information
            else if(choice == "2")
                players[turn].show_info();

            //save game status
            else if(choice == "3")
                save_data(players, lands, turn, win_condition);
            else
                cout << "Invalid input. Please input again!" << endl;

            show_choice();
            cin >> choice;
        }

        int rs;
        //check whether the player has opportunity to roll dices
        if(!players[turn].mobility) {
            cout << "Sorry. You cannot roll dices this turn! Have a good luck!" << endl;
            players[turn].mobility = 1;
        }

        else {
            roll(r1, r2, rs);                       //roll dice
            move(players, rs, turn);                //player move
            usleep(2000000);    //wait 2 seconds to moving the rolling process
            cout << endl;
            lands[players[turn].pos].show_info();  //show the land information
            cout << endl;

            //land manipulation
            land_manip(players, lands, turn, choice, r1, r2, rs);

            //check whether the player has a double roll
            while (r1 == r2) {

              if(!players[turn].mobility) {
                 cout << "Sorry. You cannot roll dices this turn! Have a good luck!" << endl;
                 players[turn].mobility = 1;
              }
              else {
                 roll(r1, r2, rs);
                 move(players, rs, turn);
                 cout << "moving..." << endl;
                 usleep(2000000);    //wait 2 seconds to simulate the moving process
                 cout << endl;
                 lands[players[turn].pos].show_info();
                 cout << endl;

                 land_manip(players, lands, turn, choice, r1, r2, rs);
               }
            }
        }

        //check whether game ends
        //property < 0 or one of (loop >= 15; have a house with highest level)
       if (players[turn].property < 0) {
            cout << "You go bankrupt!" << endl;
            int pro = 0;       //max property
            int max_pro = 0;   //max property index

            for(int i = 0; i < player_num; i++) {
                if(players[i].property > pro) {
                    pro = players[i].property;
                    max_pro = i;
                }
            }
            cout << players[max_pro].name << " has the maximum property "
            << players[max_pro].property << ".\n";
            cout << players[max_pro].name << " is the winner!" << endl;
            goto Win;
        }

        else if(players[turn].loop >= loop_win && win_condition == 1) {
            cout << "You are the first to complete " << loop_win << " loops." << endl;
            cout << players[turn].name << " is the winner!" << endl;
            goto Win;
        }

        else if (players[turn].max_house_level() == 3 && win_condition == 2) {
          cout << "You are the first to have the highest level house" << endl;
          cout << players[turn].name << " is the winner!" << endl;
          goto Win;
        }


        //update current turn
        turn ++;
        turn = turn % 4;

        cout << endl;
    }

    Win:
    cout << '\n' << "Game over!" << endl;

    return 0;
}
