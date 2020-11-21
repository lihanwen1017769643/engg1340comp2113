//land.h

#ifndef LAND_H
#define LAND_H

#include <string>
using namespace std;

struct Land {
    string owner;       //owner of land
    int house_level;    //house level of this land
    int no;             //land number, from 0 to 27
    string name;        //land name
    string type;        //type is either normal or special
    int price;          //price to buy this land

    void show_info();   //print land information
};



#endif
