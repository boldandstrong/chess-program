#include "Board.h"
#include "Player.h"
#include <iostream>
#include <string.h>

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
        "legal move - you made checkmate!",
        "ilegal move - u can only move with your pieces!"
    };

    string userInput = "";
    string move = "";
    string current_player = "white";
    Board* board = new Board();  

    Player white(board, "white");
    Player black(board, "black");

    int moveAns = 0;

    while (userInput != "checkMate")
    {
        board->printBoard();

        cout << "current player: " << current_player << endl;
        cout << "Enter your move: ";
        
        cin >> move;

        moveAns = board->movePiece(move, current_player);
        
        cout << errorsArr[moveAns] << endl;

        if (moveAns == 8 || moveAns < 2)
        {
            if (moveAns == 8)
            {  // Checkmate
                cout << "Mate! " << current_player << " won!" << endl;
                break;
            }

            // Switch player
            current_player = (current_player == "white") ? "black" : "white";
        }   
    }

    delete board;  // Free memory
    return 0;
}

