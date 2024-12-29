#include "King.h"

King::King(string type, string place, Board* board, string color) : Piece(type, place, board, color)
{ }

King::~King()
{ }


/*this function checks if a king move is valid
input: a dest
output: a number that indicated if the move is valid
*/
int King::isMoveValid(string dest) const
{
    int* dstArr = Board::stringToIndex(dest);
    int* srcArr = Board::stringToIndex(this->_place);

    //the king only has 8 valid moves, one in every direction
    //checking all the options of the king movement
    if (srcArr[0] == dstArr[0] && srcArr[1] + 1 == dstArr[1])
    {
        return 0;//valid move
    }

    if (srcArr[0] == dstArr[0] && srcArr[1] - 1 == dstArr[1])
    {
        return 0;//valid move
    }

    if (srcArr[0] + 1 == dstArr[0] && srcArr[1] + 1 == dstArr[1])
    {
        return 0;//valid move
    }

    if (srcArr[0] + 1 == dstArr[0] && srcArr[1] - 1 == dstArr[1])
    {
        return 0;//valid move
    }

    if (srcArr[0] - 1 == dstArr[0] && srcArr[1] + 1 == dstArr[1])
    {
        return 0;//valid move
    }

    if (srcArr[0] - 1 == dstArr[0] && srcArr[1] - 1 == dstArr[1])
    {
        return 0;//valid move
    }

    if (srcArr[0] + 1 == dstArr[0] && srcArr[1] == dstArr[1])
    {
        return 0;//valid move
    }

    if (srcArr[0] - 1 == dstArr[0] && srcArr[1] == dstArr[1])
    {
        return 0;//valid move
    }

    delete[] dstArr;
    delete[] srcArr;

    return 6;//invalid movement
}
