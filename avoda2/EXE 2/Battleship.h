
/* Name :YAniv BOHBOT
ID :204892749
Campus :Ashdod
*/


#pragma once
#ifndef Battleship_H
#define Battleship_H
#include <iostream>
using namespace std;

class Battleship  // class of battleship
{
private: 
	int lenght_battleship;// size of the ship
	static int amount_battleship; //amount of battleship on the board 

public:

	Battleship();//constructor battleship
	~Battleship();//destructor batlleship 
     int getShips() { return lenght_battleship; }// size of the battleship 
};
#endif
