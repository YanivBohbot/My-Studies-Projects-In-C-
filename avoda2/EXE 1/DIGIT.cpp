/* Name :YAniv BOHBOT
ID :204892749
Campus :Ashdod
*/


#include "DIGIT.h" //include the classe digit 

DIGIT::DIGIT() // constructor 
{
	value = 0; // initialize the variable value to 0
}

bool DIGIT::digit_equal_(const DIGIT &a)//function for check the value with the value in the object sent 
{

	if (value == a.value) // if the value is equal to value in the object 
	{
		return true; // retun true else false 
	}
	else{
		return false;
	}


}

void DIGIT::insert_value_in_digit(int numb) // function that insert the value 
{
	value = numb; // the user sent a value and then we insert this value to the variable value 
	//cout << value;
}




DIGIT::~DIGIT() // descturctor
{


}
