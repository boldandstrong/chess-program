#include "Board.h"

Board::Board()
{
	int i = 0, j = 0;
    
    char arrBlackPieces[] = {'r', 'n', 'b', 'q', 'k', 'b', 'n','r',};
    char arrWhitePieces[] = { 'R', 'N', 'B', 'Q', 'K', 'B', 'N','R'};

    for (i = 0, j = 0; j < 8; j++)
    {
        this->_board[i][j] = nullptr; // back pieces
    }

    for (i = 1, j = 0; j < 8; j++)
    {
        this->_board[i][j] = nullptr; //black pawns
    }

    for (i = 2; i < 6; i++)
    {
        for (j = 0; j < 8; j++)
        {
            this->_board[i][j] = nullptr; // empty places
        }
    }

    for (i = 0, j = 0; j < 8; j++)
    {
        this->_board[i][j] = nullptr; // white pieces
    }

    for (i = 1, j = 0; j < 8; j++)
    {
        this->_board[i][j] = nullptr; //white pawns
    }



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
    int placeArr[] = {place[0] - 'a', place[1] - '1'}; // Convert 'a'-'h' to 0-7 // Convert '1'-'8' to 0-7

    return placeArr;
}

void Board::printBoard() const
{
    // 0,0 point is bottom left!
    int i = 0, j = 0;

    for (i = 8; i > 0; i--)
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

int Board::movePiece(string move)
{
    int moveAns = 0;

    string dst = " ";
    string src = " ";
    src += move[0];
    src += move[1];
    dst += move[2];
    dst += move[3];

    int* srcArr = stringToIndex(src);
    int* dstArr = stringToIndex(src);


    if (srcArr[0] >= 0 && srcArr[0] <= 7 && srcArr[1] >= 0 && srcArr[1] <= 7 && dstArr[0] >= 0 && dstArr[0] <= 7 && dstArr[1] >= 0 && dstArr[1] <= 7)
    {
        if (srcArr[0] != dstArr[0] && srcArr[1] != dstArr[1])
        {
            if (this->_board[srcArr[0]][srcArr[1]] != NULL)
            {
                if (this->_board[srcArr[0]][srcArr[1]]->getColor() != this->_board[dstArr[0]][dstArr[1]]->getColor())
                {
                    return this->_board[srcArr[0]][srcArr[1]]->move(dst);
                }
                else
                {
                    return 3;
                }
            }
            else
            {
                return 2;
            }
        }
        else
        {
            return 7;
        }
    }
    else
    {
        return 5;
    }
}

int Board::isCheckOccurred(string color) const
{
    return 0;
}
