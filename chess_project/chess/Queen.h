#pragma once
#include "Piece.h"
#include "Board.h"
#include "string.h"
using namespace std;

class Queen : public Piece
{
public:
	Queen(string type, string place, Board* board, string color);
	~Queen();

	virtual int isMoveValid(string dest) const override;
};