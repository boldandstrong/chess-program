#include "Rook.h"
#include "Board.h"

Rook::Rook(string type, string place, Board* board, string color) : Piece(type, place, board, color)
{ }

Rook::~Rook()
{ }

int Rook::isMoveValid(string dest) const
{
    int* src = Board::stringToIndex(this->_place);
    int* dst = Board::stringToIndex(dest);
    int diffence = 0, i = 0;

    if (src[0] == dst[0])
    {
        diffence = dst[1] - src[1];

        if (diffence > 0)
        {
            for (i = src[1] + 1; i < dst[1]; i++)
            {
                if (this->_board->_board[src[0]][i] != nullptr)
                {
                    delete[] src;
                    delete[] dst;
                    return 6;
                }
            }
        }
        else
        {
            for (i = dst[1] + 1; i < src[1]; i++)
            {
                if (this->_board->_board[src[0]][i] != nullptr)
                {
                    delete[] src;
                    delete[] dst;
                    return 6;
                }
            }
        }
    }
    else if (src[1] == dst[1])
    {
        diffence = dst[0] - src[0];

        if (diffence > 0)
        {
            for (i = src[0] + 1; i < dst[0]; i++)
            {
                if (this->_board->_board[i][src[1]] != nullptr)
				{
					delete[] src;
					delete[] dst;
                    return 6;
                }
            }
        }
        else
        {
            for (i = dst[0] + 1; i < src[0]; i++)
            {
                if (this->_board->_board[i][src[1]] != nullptr)
				{
					delete[] src;
					delete[] dst;
                    return 6;
                }
            }
        }
    }
    else
	{
		delete[] src;
		delete[] dst;
        return 6;
    }

	delete[] src;
	delete[] dst;
    return 0;
}

