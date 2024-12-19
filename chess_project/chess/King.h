#pragma once
#include "Piece.h"

class King : public Piece
{
public:
	virtual int move(string dest) override;
	virtual int isValid(string dest) const override;
};