#include "Board.h"


Board::Board()
{
	int i = 0, j = 0;
   
    this->_king_black_place = "e8";
    this->_king_white_place = "e1";

    char arrBlackPieces[] = {'r', 'n', 'b', 'q', 'k', 'b', 'n','r',};
    char arrWhitePieces[] = { 'R', 'N', 'B', 'Q', 'K', 'B', 'N','R'};

	this->_board[0][0] = new Rook("R", "a1", this, "white");
	this->_board[0][1] = new King("K", "a2", this, "white");

	for (j = 2; j < 8; j++)
	{
		this->_board[i][j] = nullptr;
	}

	for (i = 1; i < 7; i++)
	{
		for (j = 0; j < 8; j++)
		{
			this->_board[i][j] = nullptr;
		}
	}

	this->_board[7][0] = new Rook("r", "a8", this, "black");
	this->_board[7][1] = new King("k", "b8", this, "black");

	for (i = 2; i < 8; i++)
	{
		this->_board[7][i] = nullptr;
	}

    //for (i = 0, j = 0; j < 8; j++)
    //{
    //    this->_board[i][j] = nullptr; // back pieces
    //}

    //for (i = 1, j = 0; j < 8; j++)
    //{
    //    this->_board[i][j] = nullptr; //black pawns
    //}

    //for (i = 2; i < 6; i++)
    //{
    //    for (j = 0; j < 8; j++)
    //    {
    //        this->_board[i][j] = nullptr; // empty places
    //    }
    //}

    //for (i = 0, j = 0; j < 8; j++)
    //{
    //    this->_board[i][j] = nullptr; // white pieces
    //}

    //for (i = 1, j = 0; j < 8; j++)
    //{
    //    this->_board[i][j] = nullptr; //white pawns
    //}
}

Board::~Board()
{
    int i = 0, j = 0;

    for (i = 0; i < 0; i++)
    {
        for (j = 0; j < 8; j++)
        {
            this->_board[i][j] = nullptr; // free places
        }
    }
}

int* Board::stringToIndex(string place)
{
	int* placeArr = new int[2];

	placeArr[1] = int(place[0]) - 'a'; // Convert 'a'-'h' to 0-7
	placeArr[0] = int(place[1]) - '1'; // Convert '1'-'8' to 0-7

	return placeArr;
}

void Board::printBoard() const
{
    // 0,0 point is bottom left!
    int i = 0, j = 0;

    for (i = 7; i >= 0; i--)
    {
        for (j = 0; j < 8; j++)
        {
            if (this->_board[i][j] != nullptr)
            {
                cout << this->_board[i][j]->returnType() << " ";
            }
            else
            {
                cout << "# ";  // Empty square.
            }
        };

        cout << endl;
    };
}

void Board::setBoard(Piece* newPiece, string place)
{
    int* placeArr = stringToIndex(place);

    this->_board[placeArr[0]][placeArr[1]] = newPiece;

	if (newPiece != nullptr)
	{
		this->_board[placeArr[0]][placeArr[1]]->setPlace(place);
	}

	if (newPiece->getType() == "k")
	{
		this->_king_black_place = place;
	}
	else if (newPiece->getType() == "K")
	{
		this->_king_white_place = place;
	}
}

Piece* Board::getPiece(string index) const
{
    int* pieceArr = stringToIndex(index);

    return this->_board[pieceArr[0]][pieceArr[1]];
}

void Board::removePiece(string index)
{
    int* pieceArr = stringToIndex(index);

    this->_board[pieceArr[0]][pieceArr[1]] = nullptr;
}

int Board::movePiece(string move, string player_color)
{
    int moveAns = 0, isCheck = 0, is_clear = 0;
	
	string enemy_player_color = "";
    string dst = "";
    string src = "";

    src += move[0];
    src += move[1];
    dst += move[2];
    dst += move[3];

    int* srcArr = stringToIndex(src);
    int* dstArr = stringToIndex(dst);

	if (player_color == "white")
	{
		enemy_player_color = "black";
	}
	else
	{
		enemy_player_color = "white";
	}

    if (!(srcArr[0] >= 0 && srcArr[0] <= 7 && srcArr[1] >= 0 && srcArr[1] <= 7 && dstArr[0] >= 0 && dstArr[0] <= 7 && dstArr[1] >= 0 && dstArr[1] <= 7))
    {
        return 5;
    }

	if (src == dst)
	{
		return 7;
	}

	if (this->_board[srcArr[0]][srcArr[1]] == NULL)
	{
		return 2;
	}

	if (this->_board[dstArr[0]][dstArr[1]] != NULL)
	{
		if (this->_board[dstArr[0]][dstArr[1]]->getColor() == player_color)
		{
			return 3;
		}
	}

	moveAns = this->_board[srcArr[0]][srcArr[1]]->move(dst);

	if (moveAns == 0)
	{
		Piece* srcPiece = this->_board[srcArr[0]][srcArr[1]];
		Piece* dstPiece = this->_board[dstArr[0]][dstArr[1]];

		this->setBoard(srcPiece, dst);
		this->setBoard(nullptr, src);

		isCheck = this->isCheck(player_color);

		if (isCheck == 1)
		{
			this->setBoard(srcPiece, src);
			this->setBoard(dstPiece, dst);
			return 4;
		}
		else
		{
			isCheck = this->isCheck(enemy_player_color);

			if (isCheck == 1)
			{
				return 1;
			}
			else
			{
				return 0;
			}
		}
	}
	else
	{
		return moveAns;
	}

	delete[]  srcArr;
	delete[] dstArr;
}

int Board::isCheck(string color) const
{
	string place = " ";

	if(color == "white")
	{
		place = this->_king_white_place;
	}
	else
	{
		place = this->_king_black_place;
	}

	int* placeArr = stringToIndex(place);
	int i = 0, j = 0;
	for (i = 0; i < 8; i++)
	{
		for (j = 0; j < 8; j++)
		{
			if (this->_board[i][j] != nullptr)
			{
				if (this->_board[i][j]->getColor() != this->_board[placeArr[0]][placeArr[1]]->getColor() && this->_board[i][j]->isValid(place) == 0)
				{
					return 1;
				}
			}
		}
	}
	
	return 0;
}