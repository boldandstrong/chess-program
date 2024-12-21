#include "Rook.h"

Rook::Rook(string type, string place, Board* board, string color) : Piece(type, place, board, color)
{ }

Rook::~Rook()
{ }

int Rook::move(std::string dest)
{
    int valid = isValid(dest);

    return valid;

}

int Rook::isValid(string dest) const
{
    int* src = Board::stringToIndex(this->_place);
    int* dst = Board::stringToIndex(dest);
    int diffence = 0, i = 0;

    if (src[0] == dst[0])
    {
        diffence = src[1] - dst[1];
        if (diffence > 0)
        {
            for (i = src[1]; i < dst[1]; i++)
            {
                if (this->_board->_board[src[0]][i] == nullptr)
                {
                    return 6;
                }
            }

            return 0;
        }
        else
        {
            for (i = dst[1]; i < src[1]; i++)
            {
                if (this->_board->_board[src[0]][i] == nullptr)
                {
                    return 6;
                }
            }

            return 0;
        }
    }
    else if (src[1] == dst[1])
    {
        diffence = src[0] - dst[0];
        if (diffence > 0)
        {
            for (i = src[0]; i < dst[0]; i++)
            {
                if (this->_board->_board[i][src[1]] == nullptr)
                {
                    return 6;
                }
            }

            return 0;
        }
        else
        {
            for (i = dst[0]; i < src[0]; i++)
            {
                if (this->_board->_board[i][src[1]] == nullptr)
                {
                    return 6;
                }
            }

            return 0;
        }
    }
    else
    {
        return 6;
    }
    return 0;
}