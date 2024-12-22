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
    int* dstArr = Board::stringToIndex(dest);
    int* srcArr = Board::stringToIndex(this->_place);

    if (srcArr[0] == dstArr[0] && srcArr[1] + 1 == dstArr[1])
    {
        return 0;
    }

    if (srcArr[0] == dstArr[0] && srcArr[1] - 1 == dstArr[1])
    {
        return 0;
    }

    if (srcArr[0] + 1 == dstArr[0] && srcArr[1] + 1 == dstArr[1])
    {
        return 0;
    }

    if (srcArr[0] + 1 == dstArr[0] && srcArr[1] - 1 == dstArr[1])
    {
        return 0;
    }

    if (srcArr[0] - 1 == dstArr[0] && srcArr[1] + 1 == dstArr[1])
    {
        return 0;
    }

    if (srcArr[0] - 1 == dstArr[0] && srcArr[1] - 1 == dstArr[1])
    {
        return 0;
    }

    if (srcArr[0] + 1 == dstArr[0] && srcArr[1] == dstArr[1])
    {
        return 0;
    }

    if (srcArr[0] - 1 == dstArr[0] && srcArr[1] == dstArr[1])
    {
        return 0;
    }

    delete[] dstArr;
    delete[] srcArr;

    return 6;
}
