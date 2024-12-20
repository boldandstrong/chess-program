#pragma once
#include "Piece.h"

class Player
{
public:
	Player(Board board, string color, string king_loc);
	~Player();
	
	
private:
	string _king_place;
	string _color;
	Board _board;
};

