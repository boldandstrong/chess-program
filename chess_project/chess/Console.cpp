#include "Board.h"
#include "Player.h"
#include <iostream>
#include <string>

using namespace std;

int main()
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
        "legal move - you made checkmate!"
    };

    string userInput = "";
    string move = "";
    string corrent_player = "white";
    Board* board = new Board();  
    
    Player white(board, "white", "e1");
    Player black(board, "black",  "e8");

    int moveAns = 0;

    while (userInput != "checkMate")
    {
        cout << "Enter your move: ";
        cin >> move;

        moveAns = board->movePiece(move);
        
        cout << errorsArr[moveAns] << endl;

        if (moveAns == 8)
        {  // Checkmate
            cout << "Mate! " << corrent_player << " won!" << endl;
            break;
        }

        // Switch player
        corrent_player = (corrent_player == "white") ? "black" : "white";

        board->printBoard();
    }

    delete board;  // Free memory
    return 0;
}

