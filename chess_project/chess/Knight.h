#pragma once
#include "Piece.h"
#include "string.h"
using namespace std;
#include "Board.h"

class Knight : public Piece
{
public:
	Knight(string type, string place, Board* board, string color);
	~Knight();


	virtual int isMoveValid(string dest) const override;
};