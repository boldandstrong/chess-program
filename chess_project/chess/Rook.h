#pragma once
#include "Piece.h"
#include "string.h"
using namespace std;


class Rook : public Piece
{
public:
    Rook(string type, string place, Board* board, string color);
    ~Rook();

	virtual int isMoveValid(string dest) const override;
};