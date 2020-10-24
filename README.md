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
> There are altogether 22 nations in the map, which is called *land*. Every piece of *land* has its own value, which means that players need to pay different amout of property to buy different *land*.
> Once a player moves onto a *land* that does not belong to anyone, one can choose to buy this *land* or not. On the other hand, once a player moves onto a *land* that does belong to someone, one has to pay some money as rent to the owner of this *land*.
* house
> There are three levels of *house* that can be built on every *land*, which consists of level-1, level-2, level-3.
> A *house* can only be constructed by the player if the player has owned the *land*, i.e. he/she has to pass through the *land* at least twice to buy a *house*. As long as the owner of a *land* passes onto the *land*, he/she can choose to build a higher level *house* on the land. But more construction fee is needed for higher level *house*. If it is the second time for the player to go onto the *land*, he can only choose to build a level-1 *house*. When the other player lands on this land with house, he/she needs to pay more rent. 
* special land
> There are 2 *special lands* in the map. When a player goes onto a *special land*, one will be randomly assigned to a task.
* corner land
> There are four corner lands on the gameboard. Each has some special function as listed below (in clockwise order from lower right one):
  - Go
     In the beginning, every player will be placed on Go and thet can receive certain amount of *property* every time they pass Go.
  - jail
     When a player lands on the jail, he/she will be trapped for three rounds. Nevertheless, each round he/she can choose either paying fine or attempting to roll doubles to escape jail.
  - Temporary Double
     Every time when the player lands on the "Temporary Double", he/she can choose one of his/her own lands so that the other players need to pay the double fine if they pass that land in the next 3 rounds. Notice that this effect is additive, which means you can double the same land multiple times. 
  - worm-hole
     When a player lands on the worm-hole, he/she can choose to move towards to any land in the next round. Note that if he/she pass through Go land, he/she can still receive the corresponding *property*.

#### Game Flow
There are four players. In the beginning, every one is assigned to a given amount of *property*. Also, the numbers 1,2,3,4 will be assigned to four cards a,b,c,d. Each player need to choose a card and this will be the order. On a player's turn, he/she must roll the 2 dices and move forward according to the number on the dices. The player should follow the instruction above when he/she lands on some land. Moreover, there's a possibility that the player will roll the double. In that circumstance, he/she should roll the dices again to take one extra turn after resolving the events occurred in current turn.

The game will end if one of criteria below is met.    

### Winning Requirements
One winning criterion is fixed: the player wins if the others are driven into *bankruptcy*(having no *property*). Besides, there will be one more winning criterion randomly selected from the following. It will be printed when the game starts. 
* One will win if he/she is the first one who finishes 15 turns of the map .
* One will win if he/she is the first one who constructs a house of the highest level on one of his *lands*.
* One will win if he/she is the first one who possesses all *lands* in one side of game board.

## Features
* Generation of random game sets or events
  - Apart from the normal winning criteria, the extra one will be generated at the beginning of the game.
  - The positions of lands except the special and corner lands are randomly generated per game. 
  - The result of rolling the dices is ramdom though the possibility will be modified based on the players' input as mentioned in input/output part below.
  - Whether the player has a double rolling is ramdomly decided per rolling. 
  - When the player lands on the special lands, the task assigned to him/her is also ramdomly selected.
* Data structures for storing game status
  >The data structure for our game will be queues. The programme moves to the other player's round only if the current one is finished. Each corresponding command is enqueued in order and then processed in order.
* Dynamic memory management
  >A 4-4 array and a 22-3 array will be used to store the game status. The 4-4 array consists of four int[4] values, one for each player and the data stored are the current amount of property, his/her order, the mobility in the current round and the status of double rolling. The 22-3 array is served for storing the information of the 23 normal lands, including owner, level of house and the status of double. 
* File input/output
  >Each round the player need to indicate a integer between 1 to 10. The bigger the integer is, the more likely he/she will get large dots. The ouput will be the result of rolling ramdomly generated with modified possibility. On a player's turn, he/she need responds to the prompt, e.g., if the land is not owned by anyone, the program will prompt "Purchase?(Yes/No)" and the player need to input "Yes" or "No" to indicate the choice.
   Each round the gameboard will be output with the current situation of lands ownership and the amount of property of each player.
* Program codes in multiple files
   
  - For the rolling the dices process: one file will be served as the code for rolling() function.
  - For the purchasing lands & paying rent process: one file for the purchase() and paying() function, one for the data of information of each land
  - For the special lands & corner lands: one file each for the different function corresponding to the different tasks and corner lands' function, respectively.
  - For the winning criteria: one file for the 1 extra (ramdomly selected) +1 basic winnning requirement.
  - For game status: one file for storing the status of the most recent game.
  - In the main() function file:  code for asking the player if he/she want to continue the last game. code for the order decided in the beginning of the game, code for checking whether the game is ended.
