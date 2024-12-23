#pragma once
#include "Piece.h"

class Player
{
public:
	Player(Board* board, string color);
	~Player();


private:
	string _color;
	Board* _board;
};
