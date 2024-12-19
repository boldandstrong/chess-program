#pragma once
#include "Piece.h"

class Piece;

class Board
{
public:
	string getBoard();
	Piece* _board[8][8];
};