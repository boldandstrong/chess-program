#include "Pawn.h"

Pawn::Pawn(string type, string place, Board* board, string color) : Piece(type, place, board, color)
{ }

Pawn::~Pawn()
{ }

int Pawn::isMoveValid(string dest) const
{
	int* destIndex = Board::stringToIndex(dest);
	int* srcIndex = Board::stringToIndex(this->_place);

	if((srcIndex[1] + 1 == destIndex[1] || srcIndex[1] - 1 == destIndex[1]) && srcIndex[0] + 1 == destIndex[0])
	{
		if(this->_board->_board[destIndex[0]][destIndex[1]]->getColor() != this->_color)
		{
			delete[] destIndex;
			delete[] srcIndex;
			return 3;
		}
		else
		{
			delete[] destIndex;
			delete[] srcIndex;
			return 0;
		}
	}

	if(this->_board->_board[srcIndex[0] + 1][srcIndex[1]] != nullptr)
	{
		delete[] destIndex;
		delete[] srcIndex;
		return 6;
	}

	if(srcIndex[0] + 1 == destIndex[0])
	{
		delete[] destIndex;
		delete[] srcIndex;
		return 0;
	}

	if((this->_color == "white" && srcIndex[0] == 2) || (this->_color == "black" && srcIndex[0] == 7))
	{
		if (srcIndex[0] + 2 == destIndex[0])
		{
			if (this->_board->_board[destIndex[0]][destIndex[1]] != nullptr)
			{
				delete[] destIndex;
				delete[] srcIndex;
				return 6;
			}
			else
			{
				delete[] destIndex;
				delete[] srcIndex;
				return 0;
			}
		}
	}
	
	return 0;
}