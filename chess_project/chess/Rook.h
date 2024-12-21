#pragma once
#include "Piece.h"
#include "Board.h"

class Rook : public Piece
{
public:
    Rook(string type, string place, Board* board, string color);
    ~Rook();

	virtual int move(string dest) override;
	virtual int isValid(string dest) const override;
};