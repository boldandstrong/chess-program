#pragma once
#include "Piece.h"
#include "Board.h"

class Knight : public Piece
{
public:
	virtual int move(string dest) override;
	virtual int isValid(string dest) const override;
};