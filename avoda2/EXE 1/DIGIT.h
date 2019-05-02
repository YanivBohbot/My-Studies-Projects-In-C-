/* Name :YAniv BOHBOT
ID :204892749
Campus :Ashdod
*/


#pragma once
#ifndef DIGIT_H
#define DIGIT_H
#include <iostream>
using namespace std;

class DIGIT//class digit 
{
private:  int value; //value is the digit

public:
		DIGIT();//constructor
	bool digit_equal_(const DIGIT &a);//declaration whose verify if the value is the same that is in the object sent 
	int return_digit(){ return value; };// declaration of function inline to return the value of the digit
	void insert_value_in_digit(int );// declaration of the function to insert the value of the digit in the array 
	~DIGIT();// destructor 
};
#endif

