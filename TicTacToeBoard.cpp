#include "TicTacToeBoard.h"
/**
 * Class for representing a 3x3 Tic-Tac-Toe game board, using the Piece enum
 * to represent the spaces on the board.
**/

//Switches turn member variable to represent whether it's X's or O's turn
void TicTacToeBoard::toggleTurn()
{
	if (turn == X)
	{
		turn = O;
	}
	else
	{	
		turn = X;
	}
}

//Constructor sets an empty board and specifies it is X's turn first
TicTacToeBoard::TicTacToeBoard()
{
	clearBoard();
	turn = X;
}

//Resets each board location to the Blank Piece value
void TicTacToeBoard::clearBoard()
{
	for (unsigned int i = 0; i < BOARDSIZE; i++)
	{
		for (unsigned int j = 0; j < BOARDSIZE; j++)
		{
			board[i][j] = Blank;
		}
	}

}


/**
 * Places the piece of the current turn on the board, returns what
 * piece is placed, and toggles which Piece's turn it is. placePiece does 
 * NOT allow to place a piece in a location where there is already a piece.
 * In that case, placePiece just returns what is already at that location. 
 * Out of bounds coordinates return the Piece Invalid value
**/ 
Piece TicTacToeBoard::placePiece(int row, int column)
{
	if (row >= BOARDSIZE || row < 0 || column >= BOARDSIZE || column < 0)
	{
		toggleTurn();
		return Invalid;
	}
	else
	{
		Piece temp_piece = getPiece(row, column);
		if (temp_piece == X || temp_piece == O)
		{
			toggleTurn();
			return temp_piece;	
		} else if (temp_piece == Blank)
		{
			if (turn == X)
			{
				board[row][column] = X;
			}
			else
			{
				board[row][column] = O;
			}
			toggleTurn();
			return board[row][column];
		}
		else // an error occured
		{
			toggleTurn();
			return Invalid;
		}
	}
}

/**
 * Returns what piece is at the provided coordinates, or Blank if there
 * are no pieces there, or Invalid if the coordinates are out of bounds
**/
Piece TicTacToeBoard::getPiece(int row, int column)
{
	return board[row][column];
}

/**
 * Returns which Piece has won, if there is a winner, Invalid if the game
 * is not over, or Blank if the board is filled and no one has won.
**/
Piece TicTacToeBoard::getWinner()
{
	Piece checkWinner[BOARDSIZE];
	bool boardFull = true;
	// Checks each row
	for (unsigned int i = 0; i < BOARDSIZE; i++)
	{
		for (unsigned int j = 0; j < BOARDSIZE; j++)
		{
			checkWinner[j] = board[i][j];
			if (board[i][j] == Blank)
			{
				boardFull = false;
			}
			if (checkWinner[0] == X && checkWinner[1] == X && checkWinner[2] == X)
			{
				return X;
			}
			else if (checkWinner[0] == O && checkWinner[1] == O && checkWinner[2] == O)
			{
				return O;
			}
		}
		checkWinner[2] = Blank;
	}
	// Checks each col
	for (unsigned int j = 0; j < BOARDSIZE; j++)
	{
		for (unsigned int i = 0; i < BOARDSIZE; i++)
		{
			checkWinner[i] = board[i][j];
			
			if (checkWinner[0] == X && checkWinner[1] == X && checkWinner[2] == X)
			{
				return X;
			}
			else if (checkWinner[0] == O && checkWinner[1] == O && checkWinner[2] == O)
			{
				return O;
			}
		}
		checkWinner[2] = Blank;
	}
	// Checks diagonals for winner
	if (board[0][0] == X && board[1][1] == X && board[2][2] == X)
	{
		return X;
	}
	else if (board[0][2] == X && board[1][1] == X && board[2][0] == X)
	{
		return X;
	}
	else if (board[0][0] == O && board[1][1] == O && board[2][2] == O)
	{
		return O;
	}
	else if (board[0][2] == O && board[1][1] == O && board[2][0] == O)
	{
		return O;
	}
	if (boardFull)
	{
		return Blank;
	}
	// All checks Failed...
	return Invalid;
}

Piece TicTacToeBoard::getTurn()
{
	return turn;
}
