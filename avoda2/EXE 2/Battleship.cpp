/* Name :YAniv BOHBOT
ID :204892749
Campus :Ashdod
*/

#include "Battleship.h"

int  Battleship:: amount_battleship = 0; // static variable of the amount of ship in the board

Battleship::Battleship()
{	
	switch (amount_battleship) // switch case with the amount of ship as case 
    {
	case 0:
		lenght_battleship = 5;// size of ship 5
		amount_battleship++; // increment the variable
		break;
	case 1:
		lenght_battleship = 4;// size of ship 4
		amount_battleship++;// increment the variable
		break;
	case 2:
		lenght_battleship = 3;// size of ship 3
		amount_battleship++;// increment the variable
		break;
	case 3:
		lenght_battleship = 2;// size of ship 2
		amount_battleship++;// increment the variable
		break;
	case 4:
		lenght_battleship = 3; // it cant be size of 1
		amount_battleship++;// increment the variable
		break;
	}

	
}


Battleship::~Battleship()
{


} // destructor 


