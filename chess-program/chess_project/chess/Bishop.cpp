#include "Bishop.h"


Bishop::Bishop(string type, string place, Board* board, string color) : Piece(type, place, board, color) { }

Bishop::~Bishop() { }

int Bishop::isMoveValid(string dest) const
{
	int* srcIndex = Board::stringToIndex(this->_place);
	int* destIndex = Board::stringToIndex(dest);
	int i = 0, j = 0, valid1 = 0;
	for (i = 0; i < 8; i++)
	{
		if ((srcIndex[0] + i == destIndex[0] && srcIndex[1] + i == destIndex[1]) || (srcIndex[0] + i == destIndex[0] && srcIndex[1] - i == destIndex[1]) || (srcIndex[0] - i == destIndex[0] && srcIndex[1] + i == destIndex[1]) || (srcIndex[0] - i == destIndex[0] && srcIndex[1] - i == destIndex[1]))
		{
			valid1 = 1;
			break;
		}
	}

	if (valid1 == 0)
	{
		delete[] srcIndex;
		delete[] destIndex;
		return 6;
	}

	int diffX = srcIndex[0] - destIndex[0];
	int diffY = srcIndex[1] - destIndex[1];

	if (diffX < 0 && diffY < 0)
	{
		for (i = srcIndex[0] + 1, j = srcIndex[1] + 1; i < destIndex[0] && j < destIndex[1]; i++, j++)
		{
			if (this->_board->_board[i][j] != nullptr)
			{
				delete[] srcIndex;
				delete[] destIndex;
				return 6;
			}
		}
	}
	else if (diffX > 0 && diffY < 0)
	{
		for (i = srcIndex[0] - 1, j = srcIndex[1] + 1; i > destIndex[0] && j < destIndex[1]; i--, j++)
		{
			if (this->_board->_board[i][j] != nullptr)
			{
				delete[] srcIndex;
				delete[] destIndex;
				return 6;
			}
		}
	}
	else if (diffX < 0 && diffY > 0)
	{
		for (i = srcIndex[0] + 1, j = srcIndex[1] - 1; i < destIndex[0] && j > destIndex[1]; i++, j--)
		{
			if (this->_board->_board[i][j] != nullptr)
			{
				delete[] srcIndex;
				delete[] destIndex;
				return 6;
			}
		}
	}
	else if (diffX > 0 && diffY > 0)
	{
		for (i = destIndex[0] + 1, j = destIndex[1] + 1; i < srcIndex[0] && j < srcIndex[1]; i++, j++)
		{
			if (this->_board->_board[i][j] != nullptr)
			{
				delete[] srcIndex;
				delete[] destIndex;
				return 6;
			}
		}
	}
	return 0;
}