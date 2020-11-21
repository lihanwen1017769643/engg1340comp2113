//roll.cpp
//This function will roll the dice and save the result.

//There's no input needed and no return value.
//But the rolling results is saved to variable r1, r2 and rs since
//it's pass-by-reference.

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <unistd.h>
#include "roll.h"
using namespace std;

void roll(int &r1, int &r2, int &rs){
  cout << "Rolling......\n";

  usleep(2000000);           //wait 3 seconds to simulate the rolling process
  cout << "You have rolled......\n";

  srand((unsigned)time(NULL));
  r1 = rand() % 6 + 1;
  cout << "The first dice: " << r1 << endl;

  usleep(2000000);           //wait 3 seconds to simulate the rolling process
  srand((unsigned)time(NULL));
  r2 = rand() % 6 + 1;
  cout << "The second dice: " << r2 << endl;

  rs = r1 + r2;

  cout << "You move forward " << rs << " steps." << endl;
}
