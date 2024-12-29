#include "Bishop.h"


Bishop::Bishop(string type, string place, Board* board, string color) : Piece(type, place, board, color) { }

Bishop::~Bishop() { }

/*this function checks if a bishop move is valid
input: the dest
output: a number that indicated if the move is valid
*/
int Bishop::isMoveValid(string dest) const
{
	int* srcIndex = Board::stringToIndex(this->_place);
	int* destIndex = Board::stringToIndex(dest);
	int i = 0, j = 0, valid1 = 0;
	//this loop checks if the dest and the src are in a diagonal
	//if there not it is invalid movement is inalid
	for (i = 0; i < 8; i++)
	{
		//checking every diagonal: up right, up left, down right, down left
		if ((srcIndex[0] + i == destIndex[0] && srcIndex[1] + i == destIndex[1]) || (srcIndex[0] + i == destIndex[0] && srcIndex[1] - i == destIndex[1]) || (srcIndex[0] - i == destIndex[0] && srcIndex[1] + i == destIndex[1]) || (srcIndex[0] - i == destIndex[0] && srcIndex[1] - i == destIndex[1]))
		{
			valid1 = 1;
			break;
		}
	}

	//the dest and src were found to be not in the same diagonal
	if (valid1 == 0)
	{
		delete[] srcIndex;
		delete[] destIndex;
		return 6; //invalid movement
	}

	//the difference between the x and y values of the dest and src
	int diffX = srcIndex[0] - destIndex[0];
	int diffY = srcIndex[1] - destIndex[1];

	if (diffX < 0 && diffY < 0) //up right
	{
		//checking every tile between the 2 places
		for (i = srcIndex[0] + 1, j = srcIndex[1] + 1; i < destIndex[0] && j < destIndex[1]; i++, j++)
		{
			if (this->_board->_board[i][j] != nullptr)
			{
				delete[] srcIndex;
				delete[] destIndex;
				return 6; //invalid movement
			}
		}
	}
	else if (diffX > 0 && diffY < 0) //down right
	{
		//checking every tile between the 2 places
		for (i = srcIndex[0] - 1, j = srcIndex[1] + 1; i > destIndex[0] && j < destIndex[1]; i--, j++)
		{
			if (this->_board->_board[i][j] != nullptr)
			{
				delete[] srcIndex;
				delete[] destIndex;
				return 6; //invalid movement
			}
		}
	}
	else if (diffX < 0 && diffY > 0) //up left
	{
		for (i = srcIndex[0] + 1, j = srcIndex[1] - 1; i < destIndex[0] && j > destIndex[1]; i++, j--)
		{
			//checking every tile between the 2 places
			if (this->_board->_board[i][j] != nullptr)
			{
				delete[] srcIndex;
				delete[] destIndex;
				return 6; //invalid movement
			}
		}
	}
	else if (diffX > 0 && diffY > 0) //down left
	{
		//checking every tile between the 2 places
		for (i = destIndex[0] + 1, j = destIndex[1] + 1; i < srcIndex[0] && j < srcIndex[1]; i++, j++)
		{
			if (this->_board->_board[i][j] != nullptr)
			{
				delete[] srcIndex;
				delete[] destIndex;
				return 6; //invalid movement
			}
		}
	}
	return 0;
}