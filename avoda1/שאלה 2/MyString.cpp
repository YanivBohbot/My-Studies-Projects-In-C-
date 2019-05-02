/* Assignment: 1
Campus: Ashdod
Author: Yaniv Bohbot, ID: 204892749
*/

#include "MyString.h"


MyString::MyString()
{
	str = NULL; // initiatlze the ponter to null 
	length = 0; // initialize the varaible to 0
}

MyString::~MyString()
{
	cout << "Freeing memory!" << endl; // free the allocate
	delete str; // free the allocated memory 
}

MyString::MyString(char *str)
{
	char *pointer= str; // we use a new pointer to count
	int count = 0; // varaiable to count the word
	while (*pointer != NULL) // condtion to count the size
	{
		count++; // increment the counter
		pointer++;// the pointer now is pass in the next adress
	}
	this->str = new char[count + 1];// we create an allocate memory with the size of count +1 for the null 

	this->length = count;//now length is equal to count 

	for (int i = 0; i < length; i++)
	{
		this->str[i] = str[i];  // we put the string in the Table with memory allocated
		this->str[i + 1] = NULL;
	}

}

void MyString::Print()const // function to print
{
	for (int i = 0; i < length; i++) // loop until we arrive to the size of the table
	{
		cout << str[i]; // print the string 
	}
	cout << endl;
}

MyString::MyString(const MyString &m)/*Copy constructor allocating pointer." */
{
	char *pointer = m.str; // we have a new pointer who is now pointing on the pointer of the object send
	int count = 0;
	while (*pointer != NULL) // condtion to count the size
	{
		count++;// increment the counter
		pointer++;// the pointer now is pass in the next adress
	}
	this->str = new char[count + 1];// we create an allocate memory with the size of count +1 for the null 
	this->length = count;//now length is equal to count 
	for (int i = 0; i < count; i++)
	{
		this->str[i] = m.str[i]; // we put the string in the Table with memory allocated from the strign from the object send
		this->str[i + 1] = NULL;
	}
}

void MyString::Change_tableaux_str(char *string)
{
	//str = string;
	char *pointer= string;// we have a new pointer who is now pointing on the pointer of the object send
	int counter = 0;

	if (string == NULL)
		cout << "The string is empty" << endl;

	while (*pointer != NULL)// condtion to count the size
	{
		counter++;// increment the counter
		pointer++;// the pointer now is pass in the next adress
	}
	str = new char[counter + 1];// we create an allocate memory with the size of count +1 for the null
	length = counter;//now length is equal to count 

	for (int i = 0; i < length; i++)
	{
		str[i] = string[i];// we put the string in the Table with memory allocated from the strign
		str[i + 1] = NULL;
	}
}
int MyString::getLength() // functiuon to get the size of the string
{
	char* pointer = str;// we have a new pointer who is now pointing on the pointer str
	int counter = 0;

	while (*pointer != NULL)// condtion to count the size
	{
		counter++;// increment the counter
		pointer++;// the pointer now is pass in the next adress
	}
	length = counter;//now length is equal to count 

	return length;// return the size of the string
}
int MyString::Counter_Char(char charactere) // function who count how many the charactere appeares
{
	char *pointer= str;// we have a new pointer who is now pointing on the pointer str
	int count = 0;

	for (int i = 0; i < length; i++) /// loop until we arrive to the size 
	{
		if (pointer[i] == charactere || pointer[i] == (charactere+ 32) || str[i] == (charactere - 32))// check the conditon if we have the charactere in different
			count++;                                                                                  // size letters we count him 
	}

	return count;// return the count of number characteere appaeares
}

int MyString::CountWord() // functino who count how many word there are in the string 
{
	char *pointer = str;// we have a new pointer who is now pointing on the pointer str
	int counter_word = 0, flag = 0, i = 0;

	while (pointer[i]) // while the exprression is true continue the loop 
	{
		if (pointer[i] == ' ' || pointer[i] == '.' || pointer[i] == ',' || pointer[i] == NULL)// condition is if we have in this index one of these charactere we change the state to 0
			flag = 0;
		else if (flag== 0) // if the state is 0
		{
			flag = 1;
			counter_word++; // we count 1 word
		}
		pointer[++i];//we increment the index and pass to the next 
	}
	return counter_word; // we return the number of word 
}

void MyString::LItlle_to_Upper() // function to change the string lower letter to capital letter 
{
	char *pointer= str;// we have a new pointer who is now pointing on the pointer str
	for (int i = 0; i < length; i++)
	{
		if (pointer[i] >= 'a' && pointer[i] <= 'z') // if at this index we have a lower letter 
		{
			pointer[i] -= 32; // then change to capital letter 
		}
	}
	cout << pointer << endl; // print the new string after change 

}

void MyString::Bigger_ToLower()// function to change the string capital letter to lower  letter 
{
	char *pointer = str;// we have a new pointer who is now pointing on the pointer str

	for (int i = 0; i < length; i++)
	{
		if ((pointer[i]) >= 'A' && pointer[i] <= 'Z')// if at this index we have a capital letter
		{
			pointer[i] += 32;// then change to lower letter 
		}
	}
	cout <<pointer<<endl;// print the new string after change 
}

void MyString::by_reference(int &count_B, int &count_L, int &count_N) // function who return by refrence the numb of Cap LEt,Low Let , numbers
{
	char *pointer= str;// we have a new pointer who is now pointing on the pointer str
	int i = 0;

	while (pointer[i]) // until the contion is true 
	{
		if (pointer[i] >= 'a' && pointer[i] <= 'z') // if at this index we have a capital letter
			count_L++; // counter capital letter =+1
		if (pointer[i] >= 'A' && pointer[i] <= 'Z')// if at this index we have a lower letter
			count_B++;// counter lower letter =+1
		if (pointer[i] >= '0' && pointer[i] <= '9')// if at this index we have  numbers
			count_N++;// counter number =+1
		
		i++;  // increment the index 
	}
}


void  MyString::Concetanation(const MyString &m)// function who is concatanate the string of the object send to the original
{
	char *pointer = str;// we have a new pointer who is now pointing on the pointer str


	int new_length = m.length + 1 + length;// we have a new size its from the lenght + the M.length who is counted before in the function constructor with string as parameter
	
	pointer = new char[new_length];// now we do an allocation with the size 
		

	for (int i = 0; i <length; i++)
	{
		
		pointer[i] = str[i];// we coping the original string  in  the table pointer 
		pointer[i + 1] = NULL;
	}

	for (int i = length,j=0; i < new_length-1;j++, i++) // we have the index who is equal to size:lenght who is the last index ,and j=0
	{
		pointer[i] =m.str[j];//now we coping the new string into the table pointer 
	    pointer[i + 1] = NULL;
	}
	cout << "the new string concatenate is:";
		for (int i = 0; i <new_length; i++)
	   {
			cout << pointer[i]; // we print the new string that we concatened
		}
		cout << endl;
			
}

char* MyString::Find_Word(int num) // function that find the word 
{
	

	char *pointer = str;// we have a new pointer who is now pointing on the pointer str
	char *new_pointer = NULL;
	int count = 0, j = 0, size_word = 0, index;
	

	for (int i = 0; i < length; i++) // loop until the condtion is false 
	{
		if (((pointer[i] >= 'a' && pointer[i] <= 'z') || (pointer[i] >= 'A' && pointer[i] <= 'Z') || (pointer[i] >= '0' && pointer[i] <= '9')) && (pointer[i + 1] == ' ' || pointer[i + 1] == '.' || pointer[i + 1] == ',' || pointer[i + 1] == ';' || pointer[i + 1] == NULL))
			count += 1;//IF we have at this index a letter and the next index not a letter then count a word ,word+1
		if (count == num) // if we count the woord and we have the same as the number send to the function then
		{
			while (((pointer[i] >= 'a' && pointer[i] <= 'z') || (pointer[i] >= 'A' && pointer[i] <= 'Z') || (pointer[i] >= '0' && pointer[i] <= '9')) && (pointer[i - 1] != ' ' || pointer[i - 1] != '.' || pointer[i - 1] != ',' || pointer[i - 1] != ';'))
			{              // until we have letter at this index and the letter before is not a letter
				j += 1;   // then count 
				size_word += 1;
				index = i--;
			}
			break;// when the condition is false it mean that we find the word  then break the for to go out 
		}
	}

	new_pointer = new char[size_word + 1];// now create a new table with the new size of the word 
	for (int j = 0, k = index; j < size_word; j++, k++)// loop until the condition is flse , the index k=index is the index of where the word is in the original table 
	{
		new_pointer[j] = str[k];// then we copy in the new table , each letters that are in the index even after incrementin
		new_pointer[j + 1] = NULL;
	}
		return new_pointer;// return the pointer as table 
	}