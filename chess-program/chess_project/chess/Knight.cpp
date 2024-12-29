#include "Knight.h"


Knight::Knight(string type, string place, Board* board, string color) : Piece(type, place, board, color) { }

Knight::~Knight() { }

/*this function checks if a the piece can move to the choosen destentation
input: dest - string
output: return int value - (0 - valid move, 6 - invalid move)
*/
int Knight::isMoveValid(string dest) const
{
	int* srcArr = Board::stringToIndex(this->_place);
	int* dstArr = Board::stringToIndex(dest);

	int tempRow = 0, tempCol = 0;

	tempRow = srcArr[0] + 2;

	// check if the row that the knight can move to is in the board
	if (tempRow >= 0 && tempRow <= 7)
	{
		tempCol = srcArr[1] + 1;
		// check if the col that the knight can move to is in the board and if the chosent dest fits the conditions
		if ((tempCol >= 0 && tempCol <= 7) && (tempRow == dstArr[0] && tempCol == dstArr[1]))
		{
			delete[] srcArr;
			delete[] dstArr;
			return 0; //valid move
		}

		tempCol = srcArr[1] - 1;
		// check if the col that the knight can move to is in the board and if the chosent dest fits the conditions
		if ((tempCol >= 0 && tempCol <= 7) && (tempRow == dstArr[0] && tempCol == dstArr[1]))
		{
			delete[] srcArr;
			delete[] dstArr;
			return 0;//valid move
		}
	}

	tempRow = srcArr[0] + 1;
	// check if the row that the knight can move to is in the board
	if (tempRow >= 0 && tempRow <= 7)
	{
		tempCol = srcArr[1] + 2;
		// check if the col that the knight can move to is in the board and if the chosent dest fits the conditions
		if ((tempCol >= 0 && tempCol <= 7) && (tempRow == dstArr[0] && tempCol == dstArr[1]))
		{
			delete[] srcArr;
			delete[] dstArr;
			return 0;//valid move
		}

		tempCol = srcArr[1] - 2;
		// check if the col that the knight can move to is in the board and if the chosent dest fits the conditions
		if ((tempCol >= 0 && tempCol <= 7) && (tempRow == dstArr[0] && tempCol == dstArr[1]))
		{
			delete[] srcArr;
			delete[] dstArr;
			return 0;//valid move
		}
	}

	tempRow = srcArr[0] - 1;

	// check if the row that the knight can move to is in the board
	if (tempRow >= 0 && tempRow <= 7)
	{
		tempCol = srcArr[1] + 2;
		// check if the col that the knight can move to is in the board and if the chosent dest fits the conditions
		if ((tempCol >= 0 && tempCol <= 7) && (tempRow == dstArr[0] && tempCol == dstArr[1]))
		{
			delete[] srcArr;
			delete[] dstArr;
			return 0;//valid move
		}

		tempCol = srcArr[1] - 2;
		// check if the col that the knight can move to is in the board and if the chosent dest fits the conditions
		if ((tempCol >= 0 && tempCol <= 7) && (tempRow == dstArr[0] && tempCol == dstArr[1]))
		{
			delete[] srcArr;
			delete[] dstArr;
			return 0;//valid move
		}
	}

	tempRow = srcArr[0] - 2;

	// check if the row that the knight can move to is in the board
	if (tempRow >= 0 && tempRow <= 7)
	{
		tempCol = srcArr[1] + 1;
		// check if the col that the knight can move to is in the board and if the chosent dest fits the conditions
		if ((tempCol >= 0 && tempCol <= 7) && (tempRow == dstArr[0] && tempCol == dstArr[1]))
		{
			delete[] srcArr;
			delete[] dstArr;
			return 0;//valid move
		}

		tempCol = srcArr[1] - 1;
		// check if the col that the knight can move to is in the board and if the chosent dest fits the conditions
		if ((tempCol >= 0 && tempCol <= 7) && (tempRow == dstArr[0] && tempCol == dstArr[1]))
		{
			delete[] srcArr;
			delete[] dstArr;
			return 0;//valid move
		}
	}

	delete[] srcArr;
	delete[] dstArr;
	return 6;//invalid movement
}