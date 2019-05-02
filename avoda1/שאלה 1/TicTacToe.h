/* Assignment: 1
Campus: Ashdod
Author: Yaniv Bohbot, ID: 204892749
*/
#pragma once
#define _CRT_SECURE_NO_WARNINGS
#ifndef TicTacToe_H
#define TicTacToe_H
#include <iostream>
#include <cstdlib>
using namespace std;
#define SIZE 3

enum state{ X_win,O_win,draw,not_finished}; // we ccreate a new type "state" he can be 4 different state 

class TicTacToe // we create a class tictactoe
{  
private :
	char BOARD[SIZE][SIZE]; // the class have a matrix[3][3]
	bool game_over; // a variable game over willchange to true if we have a winner 
	char turn; // a variable turn who is change before each step ,it turn the player  X to O
	void Print_Board();// a function who print the board of the game
	void Step_Board();// a function that switch between the player and check the coordinates if they are correct
	state GAME_STATE(char BOARD[][SIZE]);// a function that check all the condition of the game (if theire is a winner X,O, not finisherd or draw)
public:
	TicTacToe(); // constructor
	~TicTacToe();//destructor
	void PLay_Game();// call the function play who is calling all the function to play 
		
};
#endif
