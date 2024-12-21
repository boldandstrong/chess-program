#include "King.h"

King::King(string type, string place, Board* board, string color) : Piece(type, place, board, color)
{ }

King::~King()
{ }

int King::move(string dest)
{
    int valid = isValid(dest);

    return valid;
}

int King::isValid(string dest) const
{
    int src = stringTo
}
