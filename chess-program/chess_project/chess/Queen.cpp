#include "Queen.h"

#include "Bishop.h"


Queen::Queen(string type, string place, Board* board, string color) : Piece(type, place, board, color) { }

Queen::~Queen() { }

/*this function checks if a queen move is valid
input: dest
output: a number that indicates if the move is valid
*/
int Queen::isMoveValid(string dest) const
{
    //in chess a queen can move like a rook and a bishop
    int* src = Board::stringToIndex(this->_place);
    int* dst = Board::stringToIndex(dest);
    int diffence = 0, i = 0, j = 0, valid1 = 0;

    int x1 = src[0];
    int y1 = src[1];
    int x2 = dst[0];
    int y2 = dst[1];
    
    //ROOK MOVEMENT
    //checking if the queen and the dest have the same y value
    if (src[0] == dst[0])//if the do have the same y value i need to check the sides of the queen
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
    else //BISHOP MOVEMENT
    {
        //this loop checks if the dest and the src are in a diagonal
        //if there not it is invalid movement is inalid
        for (i = 0; i < 8; i++)
        {
            //checking every diagonal: up right, up left, down right, down left
            if ((src[0] + i == dst[0] && src[1] + i == dst[1]) || (src[0] + i == dst[0] && src[1] - i == dst[1]) || (src[0] - i == dst[0] && src[1] + i == dst[1]) || (src[0] - i == dst[0] && src[1] - i == dst[1]))
            {
                valid1 = 1;
            }
        }

        //the dest and src were found to be not in the same diagonal
        if (valid1 == 0)
        {
            delete[] src;
            delete[] dst;
            return 6; //invalid movement
        }

        //the difference between the x and y values of the dest and src
        int diffX = src[0] - dst[0];
        int diffY = src[1] - dst[1];

        if (diffX < 0 && diffY < 0) //up right
        {
            //checking every tile between the 2 places
            for (i = src[0] + 1, j = src[1] + 1; i < dst[0] && j < dst[1]; i++, j++)
            {
                if (this->_board->_board[i][j] != nullptr)
                {
                    delete[] src;
                    delete[] dst;
                    return 6; //invalid movement
                }
            }
        }
        else if (diffX > 0 && diffY < 0) //down right
        {
            //checking every tile between the 2 places
            for (i = src[0] - 1, j = src[1] + 1; i > dst[0] && j < dst[1]; i--, j++)
            {
                if (this->_board->_board[i][j] != nullptr)
                {
                    delete[] src;
                    delete[] dst;
                    return 6; //invalid movement
                }
            }
        }
        else if (diffX < 0 && diffY > 0) //up left
        {
            //checking every tile between the 2 places
            for (i = src[0] + 1, j = src[1] - 1; i < dst[0] && j > dst[1]; i++, j--)
            {
                if (this->_board->_board[i][j] != nullptr)
                {
                    delete[] src;
                    delete[] dst;
                    return 6; //invalid movement
                }
            }
        }
        else if (diffX > 0 && diffY > 0) //down left
        {
            //checking every tile between the 2 places
            for (i = dst[0] + 1, j = dst[1] + 1; i < src[0] && j < src[1]; i++, j++)
            {
                if (this->_board->_board[i][j] != nullptr)
                {
                    delete[] src;
                    delete[] dst;
                    return 6; //invalid movement
                }
            }
        }
    }
   

    delete[] src;
    delete[] dst;
    return 0;
}