
/* Name :YAniv BOHBOT
ID :204892749
Campus :Ashdod
*/
#include "Number.h"
#include <time.h>
#include "DIGIT.h"
#include <iostream>

using namespace std;
#define SIZE 4 




Number::Number()//constructor
{
	for (int i = 0; i < SIZE; i++) //for to insert in the  array 0 for inisialization of the array
	{
		number[i].insert_value_in_digit(0);//insert 0
	}
}

void Number::INSERT_NUMBER(int numb[SIZE])//function to insert the value inthe array sent at the same index in different array
{
	for (int i=0; i < SIZE; i++)
	{
		number[i].insert_value_in_digit(numb[i]);//insert the value at the same index
	}
}

void  Number::random_digit()//function to randomize a digit for the number

{	int digit1, digit2, digit3, digit4;
   	srand(time(NULL));

	//cout << " the random number is :" ;

	do
	{
digit1 = rand() % 9 + 1;// randomize only between 0-9
	} while (digit1==0);//while the digit ==0 its randomize again 

	//cout << digit1;
	do
	{
		digit2 = rand() % 9 + 1;// randomize only between 1-9
	} while (digit2 == digit1 || digit2 ==0 );//while the digit ==0 its randomize again 
	//cout << digit2;
	do
	{
digit3 = rand() % 9 + 1;// randomize only between 1-9
	} while ((digit3==digit1)||(digit3==digit2)|| digit3==0);//while the digit ==0 its randomize again 
	//cout << digit3;
	do
	{
digit4 = rand() % 9 + 1;// randomize only between 1-9
	} while ((digit4==digit1)||(digit4==digit2)||(digit3==digit4)|| digit4==0);//while the digit ==0 its randomize again 

		number[0].insert_value_in_digit(digit1);// insert the value of digit in each case of the array 
		number[1].insert_value_in_digit(digit2);
		number[2].insert_value_in_digit(digit3);
		number[3].insert_value_in_digit(digit4);
	

}

int Number::return_value_of_digit_with_index(int i) // function of return the digit whit the index 
{

	if (i < 0 || i>4) // if the index is not between 0-4
		return -1; // retur -1


	return number[i].return_digit(); // else return the value at the same index 

}

void Number::print_number() // function to print 
{    
	
	for (int i = 0; i < SIZE; i++)
	{
		cout<<number[i].return_digit();
	}
	cout << endl;
}



Number::~Number() // destructor 
{



}
