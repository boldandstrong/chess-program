#include "Board.h"
#include "Player.h"
#include <iostream>
#include <string.h>
#include "Pipe.h"

using namespace std;

int main()
{
    // arr that have the list of posible answers
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

    // conect to the Frontend 
    Pipe p;
    bool isConnect = p.connect();

    string ans;
    
    while (!isConnect)
    {
        // if there are isiuse with connecting the Frontend
        cout << "cant connect to graphics" << endl;
        cout << "Do you try to connect again or exit? (0-try again, 1-exit)" << endl;
        std::cin >> ans;
        
        // if the client wants to try to reconect
        if (ans == "0")
        {
            cout << "trying connect again.." << endl;
            Sleep(5000);
            isConnect = p.connect();
        }
        else
        {
            // if not close the program
            p.close();
            return 1;
        }
    }
    
    // local variables
    string userInput = "";
    string move = "";
    string current_player = "white";
    char msgToGraphics[1024];
    string msgFromGraphics;
    Board* board = new Board();

    Player white(board, "white");
    Player black(board, "black");

    int moveAns = 0;

    string boardString = board->getBoardString() + "0";
    strcpy_s(msgToGraphics, 1024, boardString.c_str());
    p.sendMessageToGraphics(msgToGraphics);

    msgFromGraphics = p.getMessageFromGraphics();
    
    while (msgFromGraphics != "quit")
    {
        cout << "current player: " << current_player << endl;
        
        board->printBoard();

        moveAns = board->movePiece(msgFromGraphics, current_player);

        cout << errorsArr[moveAns] << endl;
    
        // custom ans so  cast it into the legal answers
        if (moveAns == 9)
        {
            moveAns = 6;
        }

        strcpy_s(msgToGraphics, 1024, std::to_string(moveAns).c_str());
        p.sendMessageToGraphics(msgToGraphics);

        msgFromGraphics = p.getMessageFromGraphics();

        // ןif move is legal
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
