#include "Battleship.h"
#include "Game.h"
#include <iostream>
using namespace std;
#define SIZE 10
/* Name :YAniv BOHBOT
ID :204892749
Campus :Ashdod
*/



int main()
{	
	int valeur;
	char Board_GAME[SIZE][SIZE];//board game 

	cout << "How many battleships do you want to place on board?[1-5]" << endl;
	cin >> valeur;
	if (valeur < 1 || valeur>5)//we check if the user insert an amount of ship that not is the range 
		valeur = 1;// if its not his value is 1
	else
	   valeur; // else is the same 
    Game game(valeur);//constructor
	game.play(game,valeur, Board_GAME);//function to manage the game
	
	return 0;
}