/* Name :YAniv BOHBOT
ID :204892749
Campus :Ashdod
*/


#include "GAME.h"
#include "DIGIT.h"
#include "Number.h"
#define SIZE 4 

GAME::GAME()//contructor 
{
	pointer_user = new Number; //initialise the pointer user to a new object 
	pointer_comp = new Number;//initialise the pointer computer to a new object 
}

void GAME::copy_constructor_game(GAME &object)//copy cinstructor  with object sent
{

	pointer_user =object.pointer_user; //the pointer is cpopy
	pointer_comp =object.pointer_comp ;//the pointer is cpopy

}
/////////////////*****************************PLAY***********************//////////////////


void GAME::play()// funcion play manage the game 
{

	char number_char[SIZE+10], num_char, not_finish;
	int number_user_int[SIZE+1];
	
	int check = 0, cow = 0, bulls = 0, Num = 0, count = 0;
	bool flag, play_again = false;		
	do{
		pointer_comp->random_digit(); //call function random for randomize  number 
	    pointer_comp->print_number(); // call the function for print the number who is in array 
		cout << "Enter your number:";

		do{ // start  the first a do while 

			do{ // start the second a do while 

				flag = false; 
				cin >> number_char; // enter a number in the array of char 
				if ((number_char[0] == '0') || (number_char[1] == '0') || (number_char[2] == '0') || (number_char[3] == '0')) // check the condition if theire is 0 in one of the digit in the number 
				{
					cout << "Dont insert 0,insert new digit: "; // if the condition is ok then print hte message error   
					flag = true;  // and the flag is true , while the flag is true , the user have to reinsert the number 
					
				}
			
			count=0;
			int i = 0;
			while (number_char[i] != NULL) //while the value in the array is not NULL  enter 
			{
				if (number_char[i]!=NULL)//if  the value in the array is not NULL count ++
				count++;

				i++;// incremintg the index until we arrive to NULL

			}

			
			if (count > 4)// if the counter is bigger than 4 print the message of error and flag true ,while flag is true the user have to reinsert the number 
			{
				cout << "Your number is too big than 9999" << endl << " try again ";
				flag = true;
				
				
			}
			if ((number_char[0] == number_char[1]) || (number_char[0] == number_char[2]) || (number_char[0] == number_char[3]))// if we have digit the same then it print the message of error and flag true ,while flag is true the user have to reinsert the number 
			
			{
				cout << "Your number have same digit" << endl << " try again ";
				flag = true;
			}
			if ((number_char[1] == number_char[2]) || (number_char[1] == number_char[3]))//if we have digit the same then it print the message of error and flag true print the message of error and flag true ,while flag is true the user have to reinsert the number 
			
			{
				cout << "Your number have same digit" << endl << " try again ";
				flag = true;
			}
			if ((number_char[2] == number_char[3]))//if we have digit the same then it print the message of error and flag true ,while flag is true the user have to reinsert the number 
			
			{
				cout << "Your number have same digit" << endl << " try again ";
				flag = true;
			}


			for (int i = 0; i < SIZE; i++)  // start a for for check each index if the digit is a letter 
			{                               
				if ((number_char[i] <'0') || (number_char[i] >'9')) // if the digit is a letter then print error and the user have to resinser the numbe 
				{
					cout << "Your inserted a letter " << endl << " try again ";
					flag = true;
					break;
				}
			}

			for (int i = 0; i < SIZE+1; i++) // start a for
			{
				num_char = number_char[i]; // num char is equal of the digit in the array 
				Num = (int)(num_char) - 48; // we convert the digit who ws in char to int 
				number_user_int[i] = Num; // now the digit converted is now in the new array of int 
			}

		} while (flag==true); // while is true the user have a problem and then to reinsert a number 

		
			pointer_user->INSERT_NUMBER(number_user_int); // call of the function insert nubmer we sent the array of int whose contain the array of digit
			cout << "Number:" << endl;
			pointer_user->print_number(); // call the function of the array of digit


			cout << "============================" << endl;
			cow = AMOUNT_OF_COW();// call the function of the amount of cow
			cout << "COWS :" << cow << endl;
			bulls = AMOUNT_OF_BULL(); // call the function of the amount of bull 
			cout << "BULLS:" << bulls << endl;
			cout << "============================" << endl;

		} while (bulls != 4); // while we dont have 4 bulls we have to continue to play 
		cout << "The Random Number of the Computer was:";

		pointer_comp->print_number(); // function call print 
		cout << "=========================" << endl;
		cout << "YOU WOOOOOOOOOONNN!!!!!!!!!!!" << endl;
		cout << "=========================" << endl;
		do //check input for start new game
		{
			cout << "New game (y/n)? " << endl;
			cin >> not_finish; // insrrtuser 
			if (not_finish != 'y' && not_finish != 'Y' &&not_finish != 'N' &&not_finish != 'n')//wrong input
				cout << "Wrong input! try again" << endl;
		} while (not_finish != 'y' && not_finish != 'Y' && not_finish != 'N' &&not_finish != 'n');//wrong input

		play_again = (not_finish == 'y' || not_finish == 'Y') ? false : true;   //if choose to start new game play=1 else play=0
	} while (play_again != true); // while is not true , we have to play again 

	
}
int GAME::AMOUNT_OF_BULL() // function to count how much bull we have 
{
	int amount = 0;
	for (int i = 0; i < SIZE; i++) // start for 
	{
		if (pointer_user->return_value_of_digit_with_index(i) == pointer_comp->return_value_of_digit_with_index(i)) // check if we have in the array of the user at the specific index the same value in the second array (computer )tht we random at the same index 
		{
			amount++; // if the condtion is ok counter ++
		}
	}
	
	return amount; // return the count 

}
int GAME::AMOUNT_OF_COW() // function to count how much COW we have 
{
	int amount=0;

	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < SIZE; j++)
		{
			
				if ((pointer_user->return_value_of_digit_with_index(j) == pointer_comp->return_value_of_digit_with_index(i)) && (i != j))// check if we have in the array of the user at the specific index the same value in the second array (computer )tht  nott at the same index 
				{

				amount++; //counte++

				}
		}		
	}
	
	return amount;//return te count of the cow 
}


GAME::~GAME()//destructor 
{
	delete pointer_user; // delete the pointer user
	delete pointer_comp;//delete the pointer compu
}



