#include "Queen.h"

#include "Bishop.h"


Queen::Queen(string type, string place, Board* board, string color) : Piece(type, place, board, color) { }

Queen::~Queen() { }

int Queen::isMoveValid(string dest) const
{
    int* src = Board::stringToIndex(this->_place);
    int* dst = Board::stringToIndex(dest);
    int diffence = 0, i = 0, j = 0, valid1 = 0;

    int x1 = src[0];
    int y1 = src[1];
    int x2 = dst[0];
    int y2 = dst[1];
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
        for (i = 0; i < 8; i++)
        {
            if ((src[0] + i == dst[0] && src[1] + i == dst[1]) || (src[0] + i == dst[0] && src[1] - i == dst[1]) || (src[0] - i == dst[0] && src[1] + i == dst[1]) || (src[0] - i == dst[0] && src[1] - i == dst[1]))
            {
                valid1 = 1;
            }
        }

        if (valid1 == 0)
        {
            delete[] src;
            delete[] dst;
            return 6;
        }

        int diffX = src[0] - dst[0];
        int diffY = src[1] - dst[1];

        if (diffX < 0 && diffY < 0)
        {
            for (i = src[0] + 1, j = src[1] + 1; i < dst[0] && j < dst[1]; i++, j++)
            {
                if (this->_board->_board[i][j] != nullptr)
                {
                    delete[] src;
                    delete[] dst;
                    return 6;
                }
            }
        }
        else if (diffX > 0 && diffY < 0)
        {
            for (i = src[0] - 1, j = src[1] + 1; i > dst[0] && j < dst[1]; i--, j++)
            {
                if (this->_board->_board[i][j] != nullptr)
                {
                    delete[] src;
                    delete[] dst;
                    return 6;
                }
            }
        }
        else if (diffX < 0 && diffY > 0)
        {
            for (i = src[0] + 1, j = src[1] - 1; i < dst[0] && j > dst[1]; i++, j--)
            {
                if (this->_board->_board[i][j] != nullptr)
                {
                    delete[] src;
                    delete[] dst;
                    return 6;
                }
            }
        }
        else if (diffX > 0 && diffY > 0)
        {
            for (i = dst[0] + 1, j = dst[1] + 1; i < src[0] && j < src[1]; i++, j++)
            {
                if (this->_board->_board[i][j] != nullptr)
                {
                    delete[] src;
                    delete[] dst;
                    return 6;
                }
            }
        }
    }
   

    delete[] src;
    delete[] dst;
    return 0;
}