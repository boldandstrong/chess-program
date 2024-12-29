#include "Maneger.h"

Maneger::Maneger()
{
}

Maneger::~Maneger()
{
}

/*this functiuon moves a piece according to the player input
input: the move like 'e2e4', and the current player
output: an number that indicates of the move is valid
*/
int Maneger::movePiece(Board* board, string move, string player_color)
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
	int* srcArr = Board::stringToIndex(src);
	int* dstArr = Board::stringToIndex(dst);

	//checking if there is a piece in the src index
	if (board->_board[srcArr[0]][srcArr[1]] == nullptr)
	{
		delete[]  srcArr;
		delete[] dstArr;
		return 2; //no piece in the src
	}

	Piece* srcPiece = board->_board[srcArr[0]][srcArr[1]];
	Piece* dstPiece = board->_board[dstArr[0]][dstArr[1]];

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
		board->setBoard(srcPiece, dst);
		board->setBoard(nullptr, src);

		//checking if the king is under a check
		isCheck = board->isCheck(player_color);

		//if the king is under a check the move is invalid
		if (isCheck == 1)
		{
			//returning the pieces into thier original places
			board->setBoard(srcPiece, src);
			board->setBoard(dstPiece, dst);
			delete[]  srcArr;
			delete[] dstArr;
			return 4; //self check
		}
		else
		{
			delete dstPiece;
			//checking if the move caused a check to the op
			isCheck = board->isCheck(enemy_player_color);

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

string Maneger::play(Board* board, Pipe* p, string currentPlayer)
{
	string errorsArr[] =
	{
		"legal move - nice!",
		"legal move - you caused a check!",
		"illegal move - no piece in chosen src!",
		"illegal move - an ally piece in chosen dst!",
		"illegal move - you caused a check to yourself!",
		"illegal move - invalid src/dst",
		"illegal move - illegal piece move!",
		"illegal move - src and dst are the same",
		"legal move - you made checkmate!",
		"ilegal move - u can only move with your pieces!"
	};

	char msgToGraphics[1024];
	string msgFromGraphics;
	int moveAns;

	msgFromGraphics = p->getMessageFromGraphics();
	while (msgFromGraphics != "quit")
	{

		cout << "current player: " << currentPlayer << endl;
		board->printBoard();

		moveAns = this->movePiece(board, msgFromGraphics, currentPlayer);

		cout << errorsArr[moveAns] << endl;

		// custom ans so cast it into the legal answers
		if (moveAns == 9)
		{
			moveAns = 6;
		}

		//sending the result
		strcpy_s(msgToGraphics, 1024, std::to_string(moveAns).c_str());
		p->sendMessageToGraphics(msgToGraphics);

		//getting the new move
		msgFromGraphics = p->getMessageFromGraphics();

		//if move is leagal
		if (moveAns == 8 || moveAns < 2)
		{
			if (moveAns == 8)
			{  // Checkmate
				cout << "Mate! " << currentPlayer << " won!" << endl;
				break;
			}

			// Switch player
			currentPlayer = (currentPlayer == "white") ? "black" : "white";
		}
	}
}

/*this function establishes connection between the running code and the gui
input: none
output: a pointer to a pipe that can be used to communicate
*/
Pipe* Maneger::establishConnection()
{
	Pipe* p = new Pipe;
	bool isConnect = p->connect();

	string ans;
	while (!isConnect)
	{
		cout << "cant connect to graphics" << endl;
		cout << "Do you try to connect again or exit? (0-try again, 1-exit)" << endl;
		std::cin >> ans;

		if (ans == "0")
		{
			cout << "trying connect again.." << endl;
			Sleep(5000);
			isConnect = p->connect();
		}
		else
		{
			p->close();
			return nullptr;
		}
	}
	return p;
}