#include "Rook.h"
#include "Board.h"

Rook::Rook(string type, string place, Board* board, string color) : Piece(type, place, board, color)
{ }

Rook::~Rook()
{ }

/*this function checks if a rook move is valid
input: the dest
output: a number that indeicated if the move is valid
*/
int Rook::isMoveValid(string dest) const
{
    int* src = Board::stringToIndex(this->_place);
    int* dst = Board::stringToIndex(dest);
    int diffence = 0, i = 0;

    //checking if the rook and the dest have the same y value
    if (src[0] == dst[0])//if the do have the same y value i need to check the sides of the rook
    {
        diffence = dst[1] - src[1];
        //checking which place has a bigger x value
        if (diffence > 0)//if the dest is bigger 
        {
            //checking all the tiles between the two places
            for (i = src[1] + 1; i < dst[1]; i++)
            {
                //if the tile is ocupied
                if (this->_board->_board[src[0]][i] != nullptr)
                {
                    delete[] src;
                    delete[] dst;
                    return 6;//invalid movement
                }
            }
        }
        else//if the src is bigger
        {
            //checking all the tiles between the two places
            for (i = dst[1] + 1; i < src[1]; i++)
            {
                //if the tile is ocupied
                if (this->_board->_board[src[0]][i] != nullptr)
                {
                    delete[] src;
                    delete[] dst;
                    return 6;//invalid movement
                }
            }
        }
    }
    else if (src[1] == dst[1])//checking if they have the same x value
    {
        diffence = dst[0] - src[0];

        //checking which one has a bigger x value
        if (diffence > 0)
        {
            //checking all the tiles between the two places
            for (i = src[0] + 1; i < dst[0]; i++)
            {
                //if the tile is ocupied
                if (this->_board->_board[i][src[1]] != nullptr)
                {
                    delete[] src;
                    delete[] dst;
                    return 6;//invalid movement
                }
            }
        }
        else
        {
            //checking all the tiles between the two places
            for (i = dst[0] + 1; i < src[0]; i++)
            {
                //if the tile is ocupied
                if (this->_board->_board[i][src[1]] != nullptr)
                {
                    delete[] src;
                    delete[] dst;
                    return 6;//invalid movement
                }
            }
        }
    }
    else
    {
        delete[] src;
        delete[] dst;
        return 6;//invalid movement
    }

    delete[] src;
    delete[] dst;
    return 0;
}

