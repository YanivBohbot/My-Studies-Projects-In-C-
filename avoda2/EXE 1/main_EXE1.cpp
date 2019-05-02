/* Name :YAniv BOHBOT
ID :204892749
Campus :Ashdod
*/


#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <time.h>
#include <iostream>
#include "DIGIT.h"
#include "Number.h"
#include "GAME.h"
using namespace std;
#define SIZE 4 


int main()
{   
	GAME game;//create a object 
	cout << "=========================" << endl << "THis GAME 'Bulls and Cows'." << endl << "=========================" << endl << "the computer conceived 4-digit number (all digit are different,without '0')" << endl << "Your task_guess it through numbers input." << endl << "If the digitis identical,but it is at the other location -this is 'cow'(C)"<<endl<<"if it is in the same place -would be 'Bull'(B)" << endl;
	game.play();// call the function play 

	
	return 0;
}