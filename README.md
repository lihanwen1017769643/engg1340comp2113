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
> There are altogether 23 nations in the map, which is called *land*. Every piece of *land* has its own value, which means that players are able to buy different *land* of different costs.
> Once a player moves onto a *land* that does not belong to anyone, one can choose to buy this *land* or not. On the other hand, once a player moves onto a *land* that does belong to someone, one has to pay some money to the owner of this *land*.
* special land
> There are altogether 4 *special lands* in the map, one on each side of the game board. When a player goes onto a *special land*, one will be randomly assigned to a task.
* house
> There are three levels of *house* that can be built on every *land*, which consists of level-1, level-2, level-3.
> A *house* can only be constructed by the player if the player has owned the *land*, i.e. he/she has to pass through the *land* at least twice to buy a *house*. As long as the owner of a *land* passes onto the *land*, he/she can choose to build a higher level *house* on the land. But more construction fee is needed for higher level *house*. If it is the second time for the player to go onto the *land*, he can only choose to build a level-1 *house*.
* Go
> In the beginning, every player will be placed on Go and thet can receive certain amount of *property* every time they pass Go.
* Corner land
> Each land on the corner has some special function as follows.
- worm-hole
   When a player lands on the worm-hole, he/she can choose to move towards to any land in the next round. Note that if he/she pass through Go land, he/she can still receive the corresponding *property*.
- jail
  When a player lands on the jail, he/she 
#### Game Flow
There are four players. In the beginning, every one is assigned to a given amount of *property*. Also, the numbers 1,2,3,4 will be assigned to four cards a,b,c,d. Each player need to choose a card and this will be the order. On a player's turn, he/she must roll the 2 dices and move forward according to the number on the dices. The player should follow the instruction above when he/she lands on some land. Moreover, there's a possibility that the player will roll the double. In that 

The game will end if one of criteria below is met.    

### Winning Requirements
One winning criterion is fixed: the player wins if the others are driven into *bankruptcy*(having no *property*). Besides, there will be one more winning criterion randomly selected from the following. It will be printed when the game starts. 
* One will win if he/she is the first one who finishes 15 turns of the map .
* One will win if he/she is the first one who constructs a house of the highest level on one of his *lands*.
* One will win if he/she is the first one who possesses all *lands* in one side of game board.

## Features
* Generation of random game sets or events

* Data structures for storing game status

* Dynamic memory management

* File input/output

* Program codes in multiple files
