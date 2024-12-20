#include "Board.h"

Board::Board()
{
	int i = 0;
	int j = 0;

	for (i = 0; i < 8; i++)
	{
		for (j = 0; j < 8; j++)
		{
			this->_board[i][j] = NULL;
		}
	}
	
}

void Board::printBoard() const
{
	int i = 0, j = 0;

	for (i = 8; i > 0; i--)
	{
		for (j = 0; j < 8; j++)
		{
			if (this->_board[i][j] != nullptr)
			{
				cout << this->_board[i][j]->returnType();
			}
			else
			{
				cout << "#";
			}
			cout << " ";
		}
		cout << "\n";
	}
}

