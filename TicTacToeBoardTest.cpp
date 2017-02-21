/**
 * Unit Tests for TicTacToeBoard
**/

#include <gtest/gtest.h>
#include "TicTacToeBoard.h"
 
class TicTacToeBoardTest : public ::testing::Test
{
	protected:
		TicTacToeBoardTest(){} //constructor runs before each test
		virtual ~TicTacToeBoardTest(){} //destructor cleans up after tests
		virtual void SetUp(){} //sets up before each test (after constructor)
		virtual void TearDown(){} //clean up after each test, (before destructor) 
};

TEST(TicTacToeBoardTest, sanityCheck)
{
	ASSERT_TRUE(true);
}

TEST(TicTacToeBoardTest, clearBoardCheck)
{
	TicTacToeBoard b;
	b.clearBoard();
	bool is_clear = true;
	for (unsigned int i = 0; i < 3; i++)
	{
		for (unsigned int j = 0; j < 3; j++)
		{
			if (b.getPiece(i,j) != Blank)
			{
				is_clear = false;
			}
		}
	} 
	ASSERT_TRUE(is_clear);
}

TEST(TicTacToeBoardTest, constructorCheck)
{
	TicTacToeBoard b;
	Piece turn = b.getTurn();
	ASSERT_EQ(turn, X);
}

TEST(TicTacToeBoardTest, placePieceCheck)
{
	TicTacToeBoard b;
	Piece result = b.placePiece(1,2);
	ASSERT_EQ(result, X);
}

TEST(TicTacToeBoardTest, placePieceAfterTurnCheck)
{
	TicTacToeBoard b;
	Piece result;
	b.placePiece(1,1);
	b.placePiece(1,2);
	result = b.placePiece(2,2);
	ASSERT_EQ(result, X);
}

TEST(TicTacToeBoardTest, getPieceCheck)
{
	TicTacToeBoard b;
	Piece result;
	b.placePiece(0,1);
	b.placePiece(1,0);
	b.placePiece(0,1);
	result = b.getPiece(0,1);
	ASSERT_EQ(result, X);
}

TEST(TicTacToeBoardTest, getWinnerRowXCheck)
{
	TicTacToeBoard b;
	Piece result;
	b.placePiece(0,0);
	b.placePiece(1,0);
	b.placePiece(0,1);
	b.placePiece(2,0);
	b.placePiece(0,2);
	result = b.getWinner();
	ASSERT_EQ(result, X);
}

TEST(TicTacToeBoardTest, getWinnerRowOCheck)
{
	TicTacToeBoard b;
	Piece result;
	b.placePiece(0,0);
	b.placePiece(1,0);
	b.placePiece(0,1);
	b.placePiece(1,1);
	b.placePiece(2,2);
	b.placePiece(1,2);
	result = b.getWinner();
	ASSERT_EQ(result, O);
}

TEST(TicTacToeBoardTest, getWinnerColXCheck)
{
	TicTacToeBoard b;
	Piece result;
	b.placePiece(0,0);
	b.placePiece(1,1);
	b.placePiece(1,0);
	b.placePiece(2,2);
	b.placePiece(2,0);
	result = b.getWinner();
	ASSERT_EQ(result, X);
}

TEST(TicTacToeBoardTest, getWinnerColOCheck)
{
	TicTacToeBoard b;
	Piece result;
	b.placePiece(1,1);
	b.placePiece(2,2);
	b.placePiece(0,1);
	b.placePiece(0,2);
	b.placePiece(1,0);
	b.placePiece(1,2);
	result = b.getWinner();
	ASSERT_EQ(result, O);
}

TEST(TicTacToeBoardTest, getWinnerDiagOCheck)
{
	TicTacToeBoard b;
	Piece result;
	b.placePiece(1,0);
	b.placePiece(2,2);
	b.placePiece(0,1);
	b.placePiece(1,1);
	b.placePiece(0,2);
	b.placePiece(0,0);
	result = b.getWinner();
	ASSERT_EQ(result, O);
}
