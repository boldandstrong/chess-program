#include "Pawn.h"

Pawn::Pawn(string type, string place, Board* board, string color) : Piece(type, place, board, color)
{ }

Pawn::~Pawn()
{ }


/*this function checks if a pawn move is valid
input: the dest
output: a number that indicates if the move is valid
*/
int Pawn::isMoveValid(string dest) const
{
	int* destIndex = Board::stringToIndex(dest);
	int* srcIndex = Board::stringToIndex(this->_place);
	string color = this->_color;

	if (color != "black") //checking the color of the pawn
	{
		//if the color is white then the pawn need to move up
		if ((srcIndex[1] + 1 == destIndex[1] || srcIndex[1] - 1 == destIndex[1]) && srcIndex[0] + 1 == destIndex[0])
		{
			//checking if the piece that is about to be eaten is a different color than the pawn
			if (this->_board->_board[destIndex[0]][destIndex[1]]->getColor() != this->_color)
			{
				delete[] destIndex;
				delete[] srcIndex;
				return 0;//valid movement
			}
			else
			{
				delete[] destIndex;
				delete[] srcIndex;
				return 3;//an ally piece in the dest
			}
		}

		//checking if there is a piece a tile above the pawn
		if (this->_board->_board[srcIndex[0] + 1][srcIndex[1]] != nullptr)
		{
			delete[] destIndex;
			delete[] srcIndex;
			return 6;//invalid movement
		}

		//checking if the dest is 1 tile above the pawn
		if (srcIndex[0] + 1 == destIndex[0])
		{
			delete[] destIndex;
			delete[] srcIndex;
			return 0;//valid movement
		}

		//checking if the pawn has moved
		if (srcIndex[0] == 1)//if he didnt move the pawn can move 2 tiles instead of 1
		{
			if (srcIndex[0] + 2 == destIndex[0]) //checking if the dest is 2 tiles above the pawn 
			{
				if (this->_board->_board[destIndex[0]][destIndex[1]] != nullptr) //checking if there is a piece in the dest
				{
					delete[] destIndex;
					delete[] srcIndex;
					return 6;//invalid movement
				}
				else
				{
					delete[] destIndex;
					delete[] srcIndex;
					return 0;//valid movement
				}
			}
			else
			{
				delete[] destIndex;
				delete[] srcIndex;
				return 6;//invalid movement
			}
		}
		else
		{
			delete[] destIndex;
			delete[] srcIndex;
			return 6;//invalid movement
		}
	}
	else //if the color is black the pawn need to move down
	{
		//checking if the pawn can eat and if the dest is in his eating range
		if ((srcIndex[1] + 1 == destIndex[1] || srcIndex[1] - 1 == destIndex[1]) && srcIndex[0] - 1 == destIndex[0])
		{
			//checking if the color of the piece getting eaten is a different than the pawn
			if (this->_board->_board[destIndex[0]][destIndex[1]]->getColor() != this->_color)
			{
				delete[] destIndex;
				delete[] srcIndex;
				return 0;
			}
			else
			{
				delete[] destIndex;
				delete[] srcIndex;
				return 3;
			}
		}

		//checking if there is a piece a tile below the pawn, because if there is the pawn cant move
		if (this->_board->_board[srcIndex[0] - 1][srcIndex[1]] != nullptr)
		{
			delete[] destIndex;
			delete[] srcIndex;
			return 6;//invalid movement
		}

		//checking if the dest is 1 tile below the pawn
		if (srcIndex[0] - 1 == destIndex[0])
		{
			delete[] destIndex;
			delete[] srcIndex;
			return 0;
		}
			
		//checking if the pawn has moved
		if (srcIndex[0] == 6) //if he didnt move the pawn can move 2 tiles instead of 1
		{
			if (srcIndex[0] - 2 == destIndex[0]) //checking if the dest is 2 tiles before the pawn
			{
				if (this->_board->_board[destIndex[0]][destIndex[1]] != nullptr)
				{
					delete[] destIndex;
					delete[] srcIndex;
					return 6;//invalid movement
				}
				else
				{
					delete[] destIndex;
					delete[] srcIndex;
					return 0;//valid movement
				}
			}
			else 
			{
				delete[] destIndex;
				delete[] srcIndex;
				return 6;//invalid movement
			}
		}
		else
		{
			delete[] destIndex;
			delete[] srcIndex;
			return 6;//invalid movement
		}
	}

	

	return 0;
}