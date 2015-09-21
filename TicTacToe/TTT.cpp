#include <stdio.h>
#include <string>
#include <iostream>
#include <Windows.h>

#define PLAYER1 1
#define PLAYER2 2
#define NUMSQUARES 9
class TicTacToe{

public:
	int checkWin(char[]);
	int swapTurn(int);
	void drawBoard(char[], int player);
	void newTurn(char[], int);
};

void TicTacToe::newTurn(char board[], int player){
	int space;
	//char test;
	char token;
	//assign token
	if (player == PLAYER1){
		token = 'X';

	}
	else{
		token = 'O';
	}

	std::cout << "Player " << player << ", Enter available number for space on board (1-9): ";
	std::cin >> space;
	//test = space + '0';
	
	while (board[space-1] == 'O' || board[space-1] == 'X' || space > NUMSQUARES || space < 0){
		std::cout << "Sorry, that number is not valid. Please enter an available number from 1-9: ";
		std::cin >> space; 
		//test = space;
	}
	board[space - 1] = token;
}
void TicTacToe::drawBoard(char board[], int player){
	std::cout << "Turn: " << "Player " << player << "\n\n";
	std::cout << " " << board[0] << " " << "| " << board[1] << " " << "| " << board[2] << "\n";
	std::cout << "----------\n";
	std::cout << " " << board[3] << " " << "| " << board[4] << " " << "| " << board[5] << "\n";
	std::cout << "----------\n";
	std::cout << " " << board[6] << " " << "| " << board[7] << " " << "| " << board[8] << "\n\n";
}

// Temporary algorithm for 3x3. Will later implement algorithm for all odd number-sized square boards.
int TicTacToe::checkWin(char board[]){
	int col, row, diag;
	char winChar;
	//check columns
	
	for (col = 0; col <= 2; col++){
		if (board[col] == board[col + 3] && board[col + 3] == board[col + 6]){
			winChar = board[col];
			if (winChar == 'X'){
				return 1;
			}
			else{
				return 2;
			}
		}
	}

	//check rows

	for (row = 0; row <= 6; row += 3){
		if (board[row] == board[row + 1] && board[row + 1] == board[row + 2]){
			winChar = board[row];
			if (winChar == 'X'){
				return 1;
			}
			else{
				return 2;
			}
		}
	}

	//check diagonals

	if ((board[0] == board[4] && board[4] == board[8]) || (board[2] == board[4] && board[4] == board[6])){
		winChar = board[4];
		if (winChar == 'X'){
			return 1;
		}
		else{
			return 2;
		}
	}
	return 0;
}
int TicTacToe::swapTurn(int player){
	if (player == PLAYER1){
		return PLAYER2;
	}

	else{
		return PLAYER1;
	}
}


int main(){
	char board[NUMSQUARES] = { '1', '2', '3', '4', '5', '6', '7', '8', '9' };
	char playerTurn = PLAYER1;
	int numTurns = 0;
	TicTacToe newBoard;

	while (!newBoard.checkWin(board) && numTurns < NUMSQUARES){
		newBoard.drawBoard(board, playerTurn);
		newBoard.newTurn(board, playerTurn);
		newBoard.checkWin(board);
		playerTurn = newBoard.swapTurn(playerTurn);
		numTurns++;
	}
	newBoard.drawBoard(board, playerTurn);
	if (!newBoard.checkWin(board)){
		std::cout << "Tie!\n";
	}
	else{
		std::cout << "Player " << newBoard.checkWin(board) << " wins!\n";
	}


	/*std::cout << "Press enter to continue...";
	std::cin.get();*/
	system("PAUSE");
}
