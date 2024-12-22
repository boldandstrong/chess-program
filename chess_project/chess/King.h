#pragma once
#include "Piece.h"
#include "Board.h"
#include "string.h"
using namespace std;

class King : public Piece
{
public:
	King(string type, string place, Board* board, string color);
	~King();

	virtual int move(string dest) override;
	virtual int isValid(string dest) const override;

};