
/* Name :YAniv BOHBOT
ID :204892749
Campus :Ashdod
*/


#define _CRT_SECURE_NO_WARNINGS
#pragma once
#ifndef GAME_H
#define GAME_H
#include <iostream>
#include <cstdlib>
using namespace std;
#include "DIGIT.h"
#include "Number.h"


class GAME // class Game

{  private :
	Number *pointer_user = NULL, *pointer_comp = NULL; //two pointer of type NUmber : one for the array with the random number
	                                                                                // and one for the array with the number inserted by the user
    int AMOUNT_OF_BULL(); // declaration of the function that count the amount of BULL (number in the same index that we random)
	int AMOUNT_OF_COW();  // declaration of the function that count the amount of COW (number not in the same index that we random)
	
public:
	GAME();//constructor 
	void copy_constructor_game(GAME &obj);//copy constructor 
	void play();	//declaration of function play whose manage the game 
	~GAME();// destructor 
};
#endif

