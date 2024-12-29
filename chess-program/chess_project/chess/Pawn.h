#pragma once
#include "Piece.h"
#include "Board.h"

class Pawn : public Piece
{
public:
    Pawn(string type, string place, Board* board, string color);
    ~Pawn();

    virtual int isMoveValid(string dest) const override;
};