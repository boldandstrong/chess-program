#pragma once
#include "Piece.h"
#include "string.h"
using namespace std;

class Piece;

class Board
{
public:
	Board();
	~Board();
	
	// get string and retuns an index on the board
	static int* stringToIndex(string place);

	// print board
	void printBoard() const;

	// retrun piece on spesific place
    Piece* getPiece(string index) const;

	// set a piece to a new place
	void setBoard(Piece* newPiece, string place);
    
	// remove piece from the board
	void removePiece(string index);

	int movePiece(string move);

	Piece* _board[8][8];
};
