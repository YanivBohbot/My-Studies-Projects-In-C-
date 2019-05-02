/* Assignment: 1
Campus: Ashdod
Author: Yaniv Bohbot, ID: 204892749
*/
#include "TicTacToe.h"


TicTacToe::TicTacToe()  // constructor 
{
	for (int i=0; i < SIZE; i++)   // we initialize the matrix  to '-'
	{
		for (int j=0; j < SIZE; j++)
		{
			BOARD[i][j] = '-'; // the board is now doing initialization to '-'
		}
		
	}

	turn = 'X';  // we initialize the variable turn to X 
	game_over = false; // initialize a variable game_over to false 

	
}


TicTacToe::~TicTacToe()// destructor 
{

}


void TicTacToe::Print_Board() // function that printing the board
{
	for (int i = 0; i < SIZE; i++)  
	{
		for (int j = 0; j < SIZE; j++)
		{
			cout << BOARD[i][j]<< " " ; // print the case in these coordinates 
		}
		cout << endl;
	}

	
}


void TicTacToe::Step_Board() // fucntion that check the coordinates
{
	int coord1, coord2;
	
	cout << "Player "<<turn<<" Enter The First coordinates (0-2 only)" << endl; // message to the user have to insert the first index

	do{
		cout << "index i:";
		cin >> coord1;// the user insert the the first index 

	} while ((coord1<0) ||( coord1>2)); // while the user insert an index that not in the range it will be in the loop to correct himself

	cout << "Player "<<turn<<" Enter The Second coordinates (0-2 only)" << endl;  //message to the user that have to insert the second index 
	
	do {
		cout << "index j:";
		cin >> coord2; // the user insert in the second index

	} while ((coord2< 0) || (coord2>2));// while the user insert an index that not in the range it will be in the loop to correct himself

	do{ 
		if ((BOARD[coord1][coord2] == 'X') || (BOARD[coord1][coord2] == 'O')) // if the player put coordinates that corresponding to an existing  player
		{
			cout << "ERROR ITS ALREADY OCCUPY " << endl;// if its true the user receive message that is an error and its already occupy by the player 
			cout << "index i:";  // message to index1 again 
			cin >> coord1; // insert index1 again
			cout << "index j:"; // // message to index2 again
			cin >> coord2; // insert index2 again
		}
	}while ((BOARD[coord1][coord2] != '-')); // while the board in these coordinate is not empty

		
		BOARD[coord1][coord2] = turn;//put the player X/O in these coordinates 

		
		/*else if  (BOARD[coord1][coord2] == 'X')
		{
			cout << "You made a mistake !!" << endl;
			Step_Board();
		}
		else if  (BOARD[coord1][coord2] == 'O')
		{
			cout << "You made a mistake !!" << endl;
			Step_Board();
		}*/
		//system("cls");
	Print_Board(); // we printing now the board with the updates of the game 
	
	//GAME_STATE(BOARD,coord1,coord2);

}



void TicTacToe::PLay_Game() // function game control the game
{
	//TicTacToe();
	int matsav=0;
	cout << "-----TIC TAC TOE-----" << endl;
	cout << "THIS IS THE BOARD GAME" << endl;
	Print_Board();

	cout << "PLaYER  X START thE GAME " << endl;
	do{
		Step_Board();// calling the function step_board 
		if (turn == 'X')// after inserting the player we check which played and then we switch 
		{               // if turn true we change to O
          turn = 'O';
		}
		else if(turn == 'O') // if  the turn was O now is change to turn to X
		{turn = 'X';
		}
		
		matsav = GAME_STATE(BOARD); // we call the function game_state , we receive an argument who have the type state 
	
	} while (matsav ==not_finished); // if the variable who receive the state not_finished we continue to play ( we are in loop until we have different answer)


	if (matsav == X_win) // if the situation is x_win 
	{
		game_over = true; // the game is over 
		cout << " THE PLAYER X WIN !!!!!!" << endl; // message x win 

	}
	if (matsav == O_win) // if situation is o_win 
	{
		game_over = true; // game over is true 
		cout << "THe PLAYER O WIN !!!!!!" << endl; // message O win 
	}
			
	if (matsav == draw) // if situation is draw 
	{
		game_over = true; // game is over 
		cout << "DRAW !!" <<"START AGAIN"<< endl; // message the game is tako 
	}
}
	
state TicTacToe::GAME_STATE(char board[][3]) // function game _state receive a board as argumant 
{
	
	if ((board[0][0] == board[0][1]) && (board[0][1] == board[0][2])&&(board[0][0]!='-') ) // check if the first row we have a win 
	{
		if (board[0][0] == 'X')  //if we have win we check wich one win 
		{			
		return X_win; // if its true we return X_win state 
		}
		
		else{
			return O_win;// if its true we return O_win state
		}
	}
	else if ((board[0][0] == board[1][0]) && (board[1][0] == board[2][0]) && (board[0][0] != '-'))// check if the second row we have a win 
	{
		if (board[0][0] == 'X')//if we have win we check wich one win 
		{
			return X_win;// if its true we return X_win state
		}
		else{
			return O_win;// if its true we return O_win state
		}
	}
	else if ((board[1][0] == board[1][1]) && (board[1][1] == board[1][2])&&(board[1][0]!='-'))// check if the third row we have a win 
	{
		if (board[1][0] == 'X')//if we have win we check wich one win 
		{
			return X_win;// if its true we return X_win state
		}
		else{
			return O_win;// if its true we return O_win state
		}
	}
	else if ((board[0][1] == board[1][1]) && (board[1][1] == board[2][1]) && (board[0][1] != '-'))// check if the first column we have a win 
	{
		if (board[0][1] == 'X')//if we have win we check wich one win 
		{
			return X_win;// if its true we return X_win state
		}
		else{
			return O_win;// if its true we return O_win state
		}
	}

	else if ((board[2][0] == board[2][1]) && (board[2][1] == board[2][2])&&(board[2][0] != '-'))// check if the second column we have a win 
	{
		if (board[2][0] == 'X')//if we have win we check wich one win 
		{
			return X_win;// if its true we return X_win state
		}
		else{
			return O_win;// if its true we return O_win state
		}
	}
	else if ((board[0][2] == board[1][2]) && (board[1][2] == board[2][2]) && (board[0][2] != '-'))// check if the third column we have a win 
	{
		if (board[0][2] == 'X')//if we have win we check wich one win 
		{
			return X_win;// if its true we return X_win state
		}
		else{
			return O_win;// if its true we return O_win state
		}
	}
	else if ((board[0][0] == board[1][1]) && (board[1][1] == board[2][2]) && (board[0][0] != '-'))// check if the first diagonal we have a win 
	{
		if (board[1][1] == 'X')//if we have win we check wich one win 
		{
			return X_win;// if its true we return X_win state
		}
		else{
			return O_win;// if its true we return O_win state
		}
	}
	else if ((board[0][2] == board[1][1]) && (board[1][1] == board[2][0])&&(board[0][2] != '-'))// check if the second diagonal we have a win 
	{
	if (board[1][1] == 'X')//if we have win we check wich one win 
		{
			return X_win;// if its true we return X_win state
		}

   else{
			return O_win;// if its true we return O_win state
	   }

	}
	else if ((board[0][0] !='-') && (board[0][1]!='-') && (board[0][2] !='-') && (board[1][0] !='-') && (board[1][1] !='-') && (board[1][2] != '-') && (board[2][0] !='-') && (board[2][1] !='-') &&(board[2][2]!='-'))  // if all the matrix is not empty and there is not a win its mean that there is a draw 
	{	
		return draw;        // return the draw state to the function 
	}

	else
	{
		return not_finished; // else if we have no win and no a draw then we send back the state of not_finished until we have a winner  

	}
}


