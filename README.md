# engg1340comp2113 Group Project #
## Group Number: 62
* Li Hanwen 3035719519
* Ji Zeping 3035534177
## Game Description
### Game Topic:
Monopoly-updated version
### Game Rules:
#### Game Settings
* property
> The money that a player possesses is called *property*.
* land
> There are altogether 28 places in the map, which is called *land*. Every piece of *land* has its own value, which means that players need to pay different amout of property to buy different *land*.
> Once a player moves onto a *land* that does not belong to anyone, one can choose to buy this *land* or not. On the other hand, once a player moves onto a *land* that does belong to someone, one has to pay some money as rent to the owner of this *land*.
* house
> There are three levels of *house* that can be built on every *land*, which consists of level-1, level-2, level-3.
> A *house* can only be constructed by the player if the player has owned the *land*, i.e. he/she has to pass through the *land* at least twice to buy a *house*. As long as the owner of a *land* passes onto the *land*, he/she can choose to build a higher level *house* on the land. If it is the second time for the player to go onto the *land*, he can only choose to build a level-1 *house*. When the other player lands on this land with house, he/she needs to pay more rent. 
* chance land
> There are 4 *chance lands* in the map. When a player goes onto a *chance land*, one will be randomly assigned to a task.
* special land
> There are four special lands on the gameboard. Each has some special function as listed below:
   - Start
     > In the beginning, every player will be placed on Start and thet can receive certain amount of *property* every time they pass Start.
   - Jail
     > When a player lands on the jail, he/she will be trapped for one round. 
   - Temporary Double
     > Every time when the player lands on the "Temporary Double", he/she can roll the dice once more.
   - Worm-Hole
     > When a player lands on the worm-hole, he/she will randomly be telesported to some land. Note that if he/she pass through Start land, he/she can still receive the corresponding *property*.

#### Game Flow
There are four players. In the beginning, every one is assigned to a given amount of *property*. On a player's turn, he/she must roll the 2 dices and move forward according to the number on the dices. The player should follow the instruction above when he/she lands on some land. Moreover, there's a possibility that 2 dices has the same rolling result. In that circumstance, he/she should roll the dices again to take one extra turn after resolving the events occurred in current turn.

The game will end if one of criteria below is met.    

### Winning Requirements
One winning criterion is fixed: the player wins if he/she has the most property when one of the others are driven into *bankruptcy*(having no *property*). Besides, there will be one more winning criterion randomly selected from the following. It will be printed when the game starts. 
* One will win if he/she is the first one who finishes 15 turns of the map .
* One will win if he/she is the first one who constructs a house of the highest level on one of his *lands*.

## Features
* Generation of random game sets or events
  - Apart from the normal winning criteria, the extra one will be generated at the beginning of the game.
  - The positions of chance lands are randomly generated per game. 
  - The result of rolling the dices is ramdomly generated each time.
  - Whether the player has a double rolling is ramdomly decided per rolling. 
  - When the player lands on the chance lands, the task assigned to him/her is also ramdomly selected.
* Data structures for storing game status
  >We define the structure *player* and *land* to store the information of the 
* Dynamic memory management
  >A 4-9 array and a 28-6 array will be used to store the game status. The 4-9 array consists of four variable of type Player, one for each player and the data stored are the name, the current loop no., mobility, current amount of property, his/her order and the information of the land he/she owns. The 28-6 array is served for storing the information of the 28 lands, including owner, level of house, type and the price. 
* File input/output
    On a player's turn, he/she need responds to the prompt, e.g., if the land is not owned by anyone, the program will prompt "Purchase?(Yes/No)" and the player need to input "Yes" or "No" to indicate the choice.
   Each round the current situation of lands ownership and the amount of property of each player will be output .
* Program codes in multiple files
   
  - For the rolling the dices process: one file will be served as the code for roll() function.
  - For the purchasing lands & paying rent process: one file for the land_manip() function.
  - For game status: file "data.txt" for storing the status of the most recent game.
  - In the main() function file:  code for asking the player if he/she want to continue the last game. code for checking whether the game is ended.
 * Non-standard library used
    >We used the #include <unistd.h> library and function usleep() to hold the program so as to simulate several types of process, e.g., rolling the dice, moving, drawing the chance card.
