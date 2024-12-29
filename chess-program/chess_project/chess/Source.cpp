#include "Board.h"
#include "Player.h"
#include <iostream>
#include <string.h>
#include "Pipe.h"
#include "Maneger.h"

using namespace std;

int main()
{
    string current_player = "white";
    char msgToGraphics[1024];
    string msgFromGraphics;
    Board* board = new Board();
    Maneger* man = new Maneger();

    //establishing connection between this and the gui
    Pipe* p = Maneger::establishConnection();

    if (p == nullptr)
    {
        return 1;
    }

    Player white(board, "white");
    Player black(board, "black");

    int moveAns = 0;

    //sending the starting board
    string boardString = board->getBoardString() + "0";
    strcpy_s(msgToGraphics, 1024, boardString.c_str());
    p->sendMessageToGraphics(msgToGraphics);

    man->play(board, p, current_player);

    

    delete board;  // Free memory
    return 0;
}

