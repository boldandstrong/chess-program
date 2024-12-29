#pragma once
#include "Piece.h"
#include "Board.h"
#include "Pipe.h"

class Maneger
{
public:
	Maneger();
	~Maneger();

	int movePiece(Board* board, string move, string player_color);

	string play(Board* board, Pipe* p, string firstPlayer);

	static Pipe* establishConnection();
};