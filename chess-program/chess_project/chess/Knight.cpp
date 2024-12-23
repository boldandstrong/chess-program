#include "Knight.h"


Knight::Knight(string type, string place, Board* board, string color) : Piece(type, place, board, color) { }

Knight::~Knight() { }

int Knight::isMoveValid(string dest) const
{
	int* srcArr = Board::stringToIndex(this->_place);
	int* dstArr = Board::stringToIndex(dest);

	int tempRow = 0, tempCol = 0;

	tempRow = srcArr[0] + 2;

	if (tempRow >= 0 && tempRow <= 7)
	{
		tempCol = srcArr[1] + 1;
		if ((tempCol >= 0 && tempCol <= 7) && (tempRow == dstArr[0] && tempCol == dstArr[1]))
		{
			delete[] srcArr;
			delete[] dstArr;
			return 0;
		}

		tempCol = srcArr[1] - 1;
		if ((tempCol >= 0 && tempCol <= 7) && (tempRow == dstArr[0] && tempCol == dstArr[1]))
		{
			delete[] srcArr;
			delete[] dstArr;
			return 0;
		}
	}

	tempRow = srcArr[0] + 1;

	if (tempRow >= 0 && tempRow <= 7)
	{
		tempCol = srcArr[1] + 2;
		if ((tempCol >= 0 && tempCol <= 7) && (tempRow == dstArr[0] && tempCol == dstArr[1]))
		{
			delete[] srcArr;
			delete[] dstArr;
			return 0;
		}

		tempCol = srcArr[1] - 2;
		if ((tempCol >= 0 && tempCol <= 7) && (tempRow == dstArr[0] && tempCol == dstArr[1]))
		{
			delete[] srcArr;
			delete[] dstArr;
			return 0;
		}
	}

	tempRow = srcArr[0] - 1;

	if (tempRow >= 0 && tempRow <= 7)
	{
		tempCol = srcArr[1] + 2;
		if ((tempCol >= 0 && tempCol <= 7) && (tempRow == dstArr[0] && tempCol == dstArr[1]))
		{
			delete[] srcArr;
			delete[] dstArr;
			return 0;
		}

		tempCol = srcArr[1] - 2;
		if ((tempCol >= 0 && tempCol <= 7) && (tempRow == dstArr[0] && tempCol == dstArr[1]))
		{
			delete[] srcArr;
			delete[] dstArr;
			return 0;
		}
	}

	tempRow = srcArr[0] - 2;

	if (tempRow >= 0 && tempRow <= 7)
	{
		tempCol = srcArr[1] + 1;
		if ((tempCol >= 0 && tempCol <= 7) && (tempRow == dstArr[0] && tempCol == dstArr[1]))
		{
			delete[] srcArr;
			delete[] dstArr;
			return 0;
		}

		tempCol = srcArr[1] - 1;
		if ((tempCol >= 0 && tempCol <= 7) && (tempRow == dstArr[0] && tempCol == dstArr[1]))
		{
			delete[] srcArr;
			delete[] dstArr;
			return 0;
		}
	}

	return 6;
}
