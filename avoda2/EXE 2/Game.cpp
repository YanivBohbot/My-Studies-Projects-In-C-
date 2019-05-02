
/* Name :YAniv BOHBOT
ID :204892749
Campus :Ashdod
*/
#include "Game.h"
#include "Battleship.h"
#include <iostream>
#include <time.h>
#define SIZE_BOARD 10
#define SIZE 10
enum { Horizontal, Vertical }Place;//enum

int Game:: amount_of_ship = 0;

Game::Game( int taille)// constructor of the game 
{
	array_battleship = new Battleship[taille]; // new Battleship[5];

	for (int i = 0; i < taille; i++)
	{
		amount_of_ship+=array_battleship[i].getShips(); //we get the amount of ship 
	}
	//cout <<amount_of_ship << endl;
}


Game::~Game() //destructor 
{
	delete[]array_battleship; // delete the pointer 
}


void Game::printBoard(char Board_GAME[][SIZE])//function that printing the board
{                                            // and the place that the user played
	cout << "    A  B  C  D  E  F  G  H  I  J\n";
	for (int i = 0; i < SIZE_BOARD; i++)// for loop to print rows
	{
		cout << (1 + i) << " ";
		if (i + 1 == SIZE_BOARD)
			cout << "\b";
		for (int j = 0; j < SIZE; j++)// for loop to print columns
		{
			cout << "  " << Board_GAME[i][j];
		}
		cout << endl << endl;
	}
}


void Game::clear_board(char Board_GAME[][SIZE])//function to clear the board
{
	for (int index1 = 0; index1 < SIZE_BOARD; index1++) // for loop to print rows
	{
		for (int index2 = 0; index2 < SIZE_BOARD; index2++) // for loop to print columns
		{
			Board[index1][index2] = '_'; // start with '_' 
			Board_GAME[index1][index2] = '_';
		}
	}

}


int Game::Check_Hit(int index_row, int index_col, Game &game,char Board_GAME[][SIZE])//function tht checked if the user hit exactly at the same coordinates 
{
	int result = 0;
	if (Board_GAME[index_row ][index_col] == 'X' || Board_GAME[index_row ][index_col ] == '@')//The place already selected
	{
		cout << "The place already selected!" << endl;//output message
	}
	else if (Board[index_row][index_col] == 'S')//if the player hit the battleship
	{
		Board_GAME[index_row][index_col] = '@';//it place on player board @
		cout << "Hit!!!" << endl;//output message
		result = game.CheckSunk(index_row, index_col,Board_GAME);//call fanction to check if battleship is sunk

	}
	else////player didnt hit the battleship
	{
		Board_GAME[index_row][index_col] = 'X';//place on player board X
		cout << "Not hit" << endl;//output message
	}
	return result;//return if the battleship sunk
}

	

int Game::Build_Board(Game &game, int index)//function to buildthe  board
{
	srand((unsigned)time(NULL));
	int randRow = 0, randCol = 0, position = 0, index1 = 0, index2 = 0, index3 = 0, index4 = 0, check = 0;
	int size_ship = array_battleship[index].getShips();//return size of battleship

	randRow = rand() % SIZE; //random number for row
	randCol = rand() % SIZE;//random number for column
	position = rand() % 2;//random number vertical/horizontal
	

	if (position == 1)
	{
		position = Vertical;//vertical
		randRow = game.CheckPlace(randRow, randCol, position, index);//function call to check random row

	}
	else
	{
		position = Horizontal;//horizontal
		randCol = game.CheckPlace(randRow, randCol, position, index);//function call to check random column
	}
	

	switch (position)//our case is the position of the battleship 
	{
	case Vertical://vertical
	{
		if (randCol == 0)
		{
			index2 = randCol;
		}
		else
		{
			index2 = randCol - 1;
		}//if num column=0 j=0 else j=num column-1 
		for (index3 = 0, index2; index3 < 3; index2 += 2, index3 += 2)//loop that go all around battleship
		{
			if (randRow == 0)
			{
				index1 = randRow;
			}
			else
			{
				index1 = randRow - 1;
			}//if num row=0 i=0 else i=num row -1
			for (index4 = 0, index1; index4 < size_ship + 2; index1++, index4++)//loop that go all around battleship
			{
				if (Board[index1][index2] != '_')//wrong place
					return 1;//wrong place
			}
		}
		if (randRow == 0)
		{
			index1 = randRow;
		}
		else
		{
			index1=randRow - 1;//if num row=0 i=0 else i=num row -1
		}
		if (Board[index1][randCol] != '_' || Board[randRow + size_ship][randCol] != '_')//wrong place
			return 1;//wrong place

		for (int i = 0; i < size_ship; i++)//all check good-initialization board with battleship
		{
			Board[randRow + i][randCol] = 'S';
		}

		break;
	}
	case Horizontal://horizontal
	{
		if (randRow == 0)//if the random row ==0
		{
			index1 = randRow;// our index==0
		}
		else
		{
			index1 = randRow - 1;// if its not 0 , its the row -1
		}//if num row=0 i=0 else i=num row -1
			for (index3 = 0, index1; index3 < 3; index1 += 2, index3 += 2)//loop that go all around battleship
			{
				if (randCol == 0)//if the random column ==0
					index2 = randCol;// our index==0
				else
					index2 = randCol - 1;/// if its not 0 , its the column -1
				for (index4 = 0, index2; index4 < size_ship + 2; index2++, index4++)//loop that go all around battleship
				{
					if (Board[index1][index2] != '_')//wrong place
						return 1;//wrong place
				}
			}
			if (randCol == 0)
				index2 = randCol;
			else
				index2 = randCol - 1;//if num column=0 j=0 else j=num column-1
			if (Board[randRow][index2] != '_' || Board[randRow][randCol + size_ship] != '_')//wrong place
				return 1;

			for (int i = 0; i < size_ship; i++)//all check good-initialization board with battleship
			{

				Board[randRow][randCol + i] = 'S';
			}

			break;
		}
	default:
		break;
	}
	return 0;  //correct place
}


int Game::CheckPlace(int randRow,int randCol,int position,int size1)//function to check the place of the battleship in the board 
{		
	int rand_temp=0;
		switch (position)// two case :vertical /horizontal
		{
		case Vertical://vertical
		{
			rand_temp = randRow;
			while (rand_temp + (array_battleship[size1].getShips() - 1)>9)//get num for row until it will be legal 
				rand_temp = rand() % SIZE; 
			break;
		}
		case Horizontal://horizontal
		{
			rand_temp = randCol;
			while (rand_temp + (array_battleship[size1].getShips() - 1)>9)//get num for colume antil is be legal
				rand_temp = rand() % SIZE;
			break;
		}
		default:
			break;
		}
		return rand_temp;//returm correct value
}

	

bool Game::CheckSunk(int rows, int column, char Board_GAME[][SIZE])//check if battleship sunk
	{
		int count1 = 0, count2 = 0;

		if ((Board[rows+1][column] == 'S') || (Board[rows-1][column] == 'S')) //Vertical1
		{
			int i = 1;
			while (Board[rows+i][column] == 'S')//compare original board to player board and check if battleship sunk
			{
				count1++;
				if (Board_GAME[rows+i][column] == '@')
					count2++;
				i++;
			}
			if (count1 == count2)//The comparison is equal check other side of battleship
			{
				int i = 1;
				while (Board[rows-i][column] == 'S')//compùre original board to player board and check if battleship sunk
				{
					count1++;
					if (Board_GAME[rows - i][column] == '@')
						count2++;
					i++;
				}
			}
			if (count1 == count2)//if battleship sunk return true else false
			{
				return true;
			}
			else{
				return false;
			}
			
		}
		if ((Board[rows][column+1] == 'S') || (Board[rows][column-1] == 'S')) //Horizontal
		{
			int i = 1;
			while (Board[rows][column+i] == 'S')//compare original board to player board and check if battleship sunk
			{
				count1++;
				if (Board_GAME[rows][column + i] == '@')
					count2++;
				i++;
			}
			if (count1 == count2)//The comparison is equal check other side of battleship
			{
				int i = 1;
				while (Board[rows][column-i] == 'S')//compare original board to player board and check if battleship sunk
				{
					count1++;
					if (Board_GAME[rows][column - i] == '@')
						count2++;
				i++;
				}
			}
			if (count1 == count2)//if battleship sunk return true else false
			{
				return true;
			}
			else{
				return false;
			}
		}
		return false;//Defaulte returnn


	}




void Game::play(Game &game, int amount_s, char Board_GAME[][SIZE])// function to manage the game 
{
	char status, Col_char;
	int  Row = 0,  not_finish = 1, count = 0,col=0;
	bool result=false;
	game.clear_board(Board_GAME);//Reset the board

	for (int i=0;i<amount_s; i++)//loop to build board with battleship
	{
		int place = 1; //wrong place 
		while (place)//
		{
			place= game.Build_Board(game, i);//build board-if return 1 check wrong, and continue the loop until right.
		}
	}



	do
	{
		cout << "Dear user you want to hint? [y/n]   ";//output message to see the original board
		cin >> status;
		if (status == 'y' || status == 'Y')//user choose to see original board
		{
			game.PrintOriginalBoard();//call function to see original board
			cout << "Memorize the board start the game" << endl;//output message
		}
		else if (status == 'n' || status == 'N')//user choose not to see original board
		{
			cout << "Goodbye! Have a nice day ;) " << endl;//output message
		}
		else//wrong input from user
		{
			cout << "Wrong input!!" << endl;
		}
	} while (status != 'n' && status != 'N' && status != 'y' && status != 'Y');//continue if input wrong

	while (not_finish)//while game not finish (=1)
	{
		do{
			cout << "Enter your guess x y to exit use 0 0 " << endl;//input-user guess
			cin >> Row >> Col_char;
			if (Row < 0 || Row>10)//check legal input for row
				cout << "Wrong input for x! please try again!";//output message wrong input for row

			if ((Col_char < 'A' || Col_char>'J') && (Col_char < 'a' || Col_char>'j') && (Col_char != '0'))//check legal input for column
				cout << "Wrong input for y!please try again!";//output message wrong input for column

		} while ((Row < 0 || Row>10) || ((Col_char < 'A' || Col_char>'J') && (Col_char  < 'a' || Col_char>'j') && (Col_char != '0')));//continue if input wrong

		col = (Col_char >= 'A' && Col_char <= 'J') ? int(Col_char) - 65 : int(Col_char) - 97;

		not_finish = ((Row == 0) && (Col_char == '0')) ? 0 : 1;//if user choose to finish game go_on=0 else go_on=1

		if(not_finish != 0)//game not finish (go_on=1)
		{
			result = game.Check_Hit(Row - 1, col, game,Board_GAME);//call function to check if user hit the battleship
			count += result;//count num of battleship sunk

			if (result == true)//user hit the battleship
				cout << "Sunk the Boat !!" << endl;//output message-sunk the battleship

			if (count == amount_s)// if all battleship sunk
			{
				cout << "YOU WIIIIIIIN !" << endl;//output message-end game
				not_finish= 0;//end game go_on=0
			}
			game.printBoard(Board_GAME);//print player board
		}
	}
}




void Game::PrintOriginalBoard()//Print original board
{
	cout << "   A B C D E F G H I J " << endl;
	for (int i = 0; i < 10; i++)
	{
		if ((i + 1) != 10)//terms for Board to be more readable
			cout << i + 1 << "  ";//2 space
		else//terms for Board to be more readable
			cout << i + 1 << " ";//1 space
		for (int j = 0; j < 10; j++)
		{
			cout << Board[i][j] << " ";
		}
		cout << endl;
	}
}