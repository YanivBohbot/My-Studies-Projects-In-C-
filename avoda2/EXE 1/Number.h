/* Name :YAniv BOHBOT
ID :204892749
Campus :Ashdod
*/

#pragma once
#ifndef Number_H
#define Number_H
#include "DIGIT.h"
#include <iostream>
#include <cstdlib>
#include <time.h>
using namespace std;
#define N 4 


class Number //class of number
{ 
private: 
	DIGIT number[N] ;//array that is type of DIGIT for each 

public:

	Number();//constructor
	void INSERT_NUMBER(int []);//function to insert a number
	void random_digit();//function to random a digit
	int return_value_of_digit_with_index(int i);//function to return the digit
	void print_number();//function to print a number

	~Number();//destructor 
};
#endif

