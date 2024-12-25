#include "Board.h"


Board::Board()
{
	int i = 0, j = 0;

	this->_king_black_place = "d8";
	this->_king_white_place = "d1";

	//white back pieces
	this->_board[0][0] = new Rook("R", "a1", this, "white");
	this->_board[0][1] = new Knight("N", "b1", this, "white");
	this->_board[0][2] = new Bishop("B", "c1", this, "white");
	this->_board[0][3] = new King("K", "d1", this, "white");
	this->_board[0][4] = new Queen("Q", "e1", this, "white");
	this->_board[0][5] = new Bishop("B", "f1", this, "white");
	this->_board[0][6] = new Knight("N", "g1", this, "white");
	this->_board[0][7] = new Rook("R", "h1", this, "white");

	for (i = 1, j = 0; j < 8; j++)
	{
	    //this->_board[i][j] = nullptr;
	    this->_board[i][j] = new Pawn("P", string(1, char(j + 97)) + '2', this, "white"); //white pawns
	}

	for (i = 2; i < 6; i++)
	{
	    for (j = 0; j < 8; j++)
	    {
	        this->_board[i][j] = nullptr;// empty places
	    }
	}

	//black back pieces
	this->_board[7][0] = new Rook("r", "a8", this, "black");
	this->_board[7][1] = new Knight("n", "b8", this, "black");
	this->_board[7][2] = new Bishop("b", "c8", this, "black");
	this->_board[7][3] = new King("k", "d8", this, "black");
	this->_board[7][4] = new Queen("q", "e8", this, "black");
	this->_board[7][5] = new Bishop("b", "f8", this, "black");
	this->_board[7][6] = new Knight("n", "g8", this, "black");
	this->_board[7][7] = new Rook("r", "h8", this, "black");

	for (i = 6, j = 0; j < 8; j++)
	{
		//this->_board[i][j] = nullptr;
		this->_board[i][j] = new Pawn("p", string(1, char(j + 97)) + '7', this, "black"); //black pawns
	}
}

Board::~Board()
{
	int i = 0, j = 0;

	for (i = 0; i < 8; i++)
	{
		for (j = 0; j < 8; j++)
		{
			this->_board[i][j] = nullptr; // free places
		}
	}
}

/*this functiuon converts a string like 'e4' to index of a 2d array
input: the string
output: an array with the index
*/
int* Board::stringToIndex(string place)
{
	int* placeArr = new int[2];

	placeArr[1] = int(place[0]) - 'a'; // Convert 'a'-'h' to 0-7
	placeArr[0] = int(place[1]) - '1'; // Convert '1'-'8' to 0-7

	return placeArr;
}

/*this functiuon prints the board
input: none
output: none
*/
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
				cout << this->_board[i][j]->getType() << " ";
			}
			else
			{
				cout << "# ";  // Empty square.
			}
		};

		cout << endl;
	};
}

/*this functiuon moves a piece to a place in the board
input: the new piece, the place to put the piece in
output: none
*/
void Board::setBoard(Piece* newPiece, string place)
{
	int* placeArr = stringToIndex(place);

	this->_board[placeArr[0]][placeArr[1]] = newPiece;

	if (newPiece != nullptr)
	{
		this->_board[placeArr[0]][placeArr[1]]->setPlace(place);


		if (newPiece->getType() == "k")
		{
			this->_king_black_place = place;
		}
		else if (newPiece->getType() == "K")
		{
			this->_king_white_place = place;
		}
	}

}

/*this functiuon returns a piece
input: the place of the piece
output: the piece
*/
Piece* Board::getPiece(string index) const
{
	int* pieceArr = stringToIndex(index);

	return this->_board[pieceArr[0]][pieceArr[1]];
}

/*this functiuon returns a string of the board
input: none
output: the string of the board
*/
string Board::getBoardString() const
{
	// 0,0 point is bottom left!
	string boardString = "";
	int i = 0, j = 0;

	for (i = 7; i >= 0; i--)
	{
		for (j = 0; j < 8; j++)
		{
			if (this->_board[i][j] != nullptr)
			{
				boardString += this->_board[i][j]->getType();
			}
			else
			{
				boardString += "#";  // Empty square.
			}
		};
	};
	return boardString;
}

/*this functiuon removes a piece and deletes it from the memory
input: the place of the piece
output: none
*/
void Board::removePiece(string index)
{
	int* pieceArr = stringToIndex(index);
	delete this->_board[pieceArr[0]][pieceArr[1]];
	this->_board[pieceArr[0]][pieceArr[1]] = nullptr;
}

/*this functiuon moves a piece according to the player input
input: the move like 'e2e4', and the current player
output: an number that indicates of the move is valid
*/
int Board::movePiece(string move, string player_color)
{
	int moveAns = 0, isCheck = 0, is_clear = 0;

	string enemy_player_color = "";
	string dst = "";
	string src = "";

	//splitting the move into 2 places
	src += move[0];
	src += move[1];
	dst += move[2];
	dst += move[3];

	//finding the index of the places
	int* srcArr = stringToIndex(src);
	int* dstArr = stringToIndex(dst);

	//checking if there is a piece in the src index
	if (this->_board[srcArr[0]][srcArr[1]] == nullptr)
	{
		delete[]  srcArr;
		delete[] dstArr;
		return 2; //no piece in the src
	}

	Piece* srcPiece = this->_board[srcArr[0]][srcArr[1]];
	Piece* dstPiece = this->_board[dstArr[0]][dstArr[1]];

	if (player_color == "white")
	{
		enemy_player_color = "black";
	}
	else
	{
		enemy_player_color = "white";
	}

	//checking if the piece is that of a different color than the player
	if (srcPiece->getColor() != player_color)
	{
		delete[]  srcArr;
		delete[] dstArr;
		return 9; //you can only ove with your pieces
	}

	//checking if the src and the dest are valid
	if (!(srcArr[0] >= 0 && srcArr[0] <= 7 && srcArr[1] >= 0 && srcArr[1] <= 7 && dstArr[0] >= 0 && dstArr[0] <= 7 && dstArr[1] >= 0 && dstArr[1] <= 7))
	{
		delete[]  srcArr;
		delete[] dstArr;
		return 5; //src or dest are not valid
	}

	//checking if the src and dest are not in the same place
	if (src == dst)
	{
		delete[]  srcArr;
		delete[] dstArr;
		return 7; //src and dest are the same
	}

	//cheking if there is a piece in the src
	if (srcPiece == NULL)
	{
		delete[]  srcArr;
		delete[] dstArr;
		return 2; //no piece in the src
	}

	//checking if there is a piece of the same color of the src piece in the dest
	if (dstPiece != NULL)
	{
		if (dstPiece->getColor() == player_color)
		{
			delete[]  srcArr;
			delete[] dstArr;
			return 3; //an ally piece in the dest
		}
	}

	//checking is the move is valid 
	moveAns = srcPiece->isMoveValid(dst);

	//if thge move is valid
	if (moveAns == 0)
	{
		//doing the move
		this->setBoard(srcPiece, dst);
		this->setBoard(nullptr, src);

		//checking if the king is under a check
		isCheck = this->isCheck(player_color);

		//if the king is under a check the move is invalid
		if (isCheck == 1)
		{
			//returning the pieces into thier original places
			this->setBoard(srcPiece, src);
			this->setBoard(dstPiece, dst);
			delete[]  srcArr;
			delete[] dstArr;
			return 4; //self check
		}
		else
		{
			delete dstPiece;
			//checking if the move caused a check to the op
			isCheck = this->isCheck(enemy_player_color);

			if (isCheck == 1)
			{
				delete[]  srcArr;
				delete[] dstArr;
				return 1; //you caused a check to your op
			}
			else
			{
				delete[]  srcArr;
				delete[] dstArr;
				return 0; //valid move
			}
		}
	}
	else
	{
		delete[]  srcArr;
		delete[] dstArr;
		return moveAns;
	}

	delete[]  srcArr;
	delete[] dstArr;
}

/*this functiuon checks if a piece is threatened, this function is used to check if a check has happend
input: the color of the king
output: 1 - if the king is under a check, 0 - if the king is not under a check
*/
int Board::isCheck(string color) const
{
	string place = " ";

	//finding the place if the of the king according to the color
	if (color == "white")
	{
		place = this->_king_white_place;
	}
	else
	{
		place = this->_king_black_place;
	}

	int i = 0, j = 0;
	//checking every piece for checking the king
	for (i = 0; i < 8; i++)
	{
		for (j = 0; j < 8; j++)
		{
			//if a piece exsist in the index
			if (this->_board[i][j] != nullptr)
			{
				//checking if the color of the piece is a different color than the color of the king
				if (this->_board[i][j]->getColor() != color)
				{
					//checking if the piece can eat the king
					if (this->_board[i][j]->isMoveValid(place) == 0)
					{
						cout << "checked by: " << this->_board[i][j]->getType() << ", it`s color: " << this->_board[i][j]->getColor() << ", it`s place: " << i << j << endl;
						return 1; // a check has occured
					}
				}
			}
		}
	}

	return 0;
}