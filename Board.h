#pragma once
#include "Piece.h"

class Piece;

class Board
{
public:
	Board();
	~Board();

	void printBoard() const;

	Piece* _board[8][8];
private:

};
