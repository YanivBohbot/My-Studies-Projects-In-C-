/* Name :YAniv BOHBOT
ID :204892749
Campus :Ashdod
*/




#pragma once
#ifndef Game_H
#define Game_h
#include <iostream>
#include "Battleship.h"
using namespace std;
#define SIZE 10

class Game
{
private: char Board[SIZE][SIZE]; //private board 
		// char Board_GAME[SIZE][SIZE];
		 static int  amount_of_ship;//variable static amount of ship  
		 Battleship *array_battleship=NULL; // pointer of array battleship
		 int CheckPlace(int,int,int,int); // function checklace, is checking each battleship in the board game
		 int Build_Board(Game &,int);// function whose building the board
		 int Check_Hit(int, int, Game &, char Board_GAME[][SIZE]);//function that check if there is hit int the board 
		 bool CheckSunk(int, int, char Board_GAME[][SIZE]);//function that check if there is a sunk
		
public:
	void printBoard(char [][SIZE]);// function for print 
	void play(Game &, int, char [][SIZE]);// function that manage the game 
	Game(int);// function constructor 
	~Game();//function destructor 
	void clear_board(char [][SIZE]);//function for clear the board 
	void PrintOriginalBoard();//function to print the original
	
};
#endif

