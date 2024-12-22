#pragma once
#include "Piece.h"
#include "Board.h"
#include "string.h"
using namespace std;

class Bishop : public Piece
{
public:
	Bishop(string type, string place, Board* board, string color);
	~Bishop();

	virtual int isMoveValid(string dest) const override;
};