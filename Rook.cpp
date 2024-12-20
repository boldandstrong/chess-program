#include "Rook.h"

int Rook::move(std::string dest)
{

}

int Rook::isValid(string dest) const
{
	int valid = 0;
	if (dest[0] == this->place[0] && dest[1] != this->place[1])
	{
		int i = 0;
		string index;
		if (this->place[1] > dest[1])
		{
			for (i = int(this->place[1]) - int(dest[1]); i < this->place[1]; i++)
			{
				index = 8 * (int(this->place[1]) - 97) + i;
				if(this->_board._board[index])
			}
		}
		for (;i = 0;)
		{

		}
	}
	else if (dest[1] == this->place[1] && dest[0] != this->place[0])
	{

	}
}